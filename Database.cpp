#include "Database.h"


Database::Database() :UserID(0), WorkFlowID(0) {
	ut.clear();
	wtt.clear();
	wt.clear();
	wft.clear();
}

Database::~Database() {}

//�������Ҹ��û����Ƿ��Ѵ��������ݿ���
//�����û����Ѵ��ڣ��򷵻أ� 1:creator 2 : worker
//�����ڣ��򷵻�0����Чע������

int Database::searchUserName(string name) {
	map<string, UserTableAttributes>* utp = ut.getTable();
	if ((*utp).find(name) != (*utp).end())
		return ((*utp)[name].user.getUserType());
	else return 0;
}
/*
//�����û���Ϣ�ĺ���
//���û�ҵ����򷵻�false
//�ҵ��˾ͷ��� true
*/
bool Database::searchUserInfo(string name, string password) {
	map<string, UserTableAttributes>* utp = ut.getTable();
	if ((*utp).find(name) == (*utp).end()) return false;
	else return ((*utp)[name].password == getMD5(password));
}

//ע��creator
int Database::RegistCreator(string name, string password) {
	map<string, UserTableAttributes>* utp = ut.getTable();
	if ((*utp).find(name) != (*utp).end()) return -1;
	//error:username already exists.
	User user = Creator(++Database::UserID, 1);
	ut.setTable(name, getMD5(password), user);
	return 0;
}

//ע��worker
int Database::RegistWorker(string name, string password) {
	map<string, UserTableAttributes>* utp = ut.getTable();
	if ((*utp).find(name) != (*utp).end()) return -1;
	//error:username already exists.
	User user = Worker(++Database::UserID, 2);
	ut.setTable(name, getMD5(password), user);
	return 0;
}

//�����û��������룬Ĭ����Ϊ�Ѿ����û�ƥ�䣬���ض�Ӧ��userָ��
User* Database::getUserPoint(string username, string password) {
		map<string, UserTableAttributes>* utp = ut.getTable();
		return &((*utp)[username].user);
}

//��ӡ�������͵ı�
vector<int> Database::GetWorkTypeList() {
	vector<int> vec;
	map<int, WorkTypeTableAttributes>* wttp = wtt.getTable();
	for (map<int, WorkTypeTableAttributes>::iterator it = (*wttp).begin();it != (*wttp).end();it++) vec.push_back(it->first);
	return vec;
}

void Database::CreateWorkFlow(vector<int> WorkTypeList, Creator* c) {
	map<int, work>* wp = wt.getTable();
	workFlow wf = workFlow(++WorkFlowID, c->getUserID());
	//(*c).setWorkFlowList(wf.getWorkFlowID());
	int lastWorkID = 0;
	for (vector<int>::iterator it = WorkTypeList.begin();it != WorkTypeList.end();it++) {
		work w = work(++WorkID, *it, wf.getWorkFlowID());
		if (it != WorkTypeList.begin()) {
			(*wp)[lastWorkID].SetNextWorkID(w.GetWorkID());
			w.SetPreWorkID(lastWorkID);
		}
		else {
			//printf("begin ID is:%d\n",w.GetWorkID());
			wf.setBeginWorkID(w.GetWorkID());
		}
		wt.setTable(&w);
		wf.addNotChosenWork(w.GetWorkID());
		lastWorkID = w.GetWorkID();
	}
	/*for(int i=wf.getBeginWorkID();i!=-1;i=(*wp)[i].GetNextWorkID()){
	printf("+%d\n",i);
	}
	for(set<int>::iterator it=wf.getNotChosenWork()->begin();it!=wf.getNotChosenWork()->end();it++){
	printf("workflow %d:%d\n",wf.getWorkFlowID(),*it);
	}
	printf("\n\n%d %d %d %d %d\n\n",wf.getWorkFlowID(),wf.getBeginWorkID(),wf.getWorkNumber(),wf.getRemainWorkNumber(),wf.getNotChosenWork()->size());*/
	wft.setTable(&wf);
}

vector<int> Database::GetToCheckListByWorkerID(int WorkerId) {
	map<int, work>* wp = wt.getTable();
	map<int, WorkTypeTableAttributes>* wttp = wtt.getTable();
	vector<int> vec;
	for (map<int, work>::iterator it = (*wp).begin();it != (*wp).end();it++) {
		vector<int>* vp = &((*wttp)[it->second.GetTypeID()].WorkerList);
		for (vector<int>::iterator is = (*vp).begin();is != (*vp).end();is++) {
			if (*is == WorkerId) {
				if (!(it->second.IsTaken())) vec.push_back(it->second.GetWorkID());
			}
		}
	}
	return vec;
}

set<int>* Database::getNotReadyWorkFlow() {
	return &NotReadyWorkFlow;
}

//default:ChosenWorkList is the WorkID vector
void Database::UpdateToCheckList(vector<int>& ChosenWorkList, int WorkerId) {
	map<int, work>* wp = wt.getTable();
	map<int, workFlow>* wftp = wft.getTable();
	for (vector<int>::iterator it = ChosenWorkList.begin();it != ChosenWorkList.end();it++) {
		//printf("in UpdateToCheckList:\n");
		if ((*wp)[*it].IsTaken()) throw domain_error("already taken");
		else {
			(*wp)[*it].SetWorkerID(WorkerId);
			/*printf("$%d %d %d %d\n",(*wp)[*it].GetWorkFlowID(),(*wp)[*it].GetWorkID(),WorkerId,*it);
			printf("=%d %d\n",(*wp)[*it].GetPreWorkID(),(*wp)[*it].GetNextWorkID());
			printf("==%d %d %d %d %d\n",(*wftp)[(*wp)[*it].GetWorkFlowID()].getWorkFlowID(),(*wftp)[(*wp)[*it].GetWorkFlowID()].getWorkNumber(),(*wftp)[(*wp)[*it].GetWorkFlowID()].getRemainWorkNumber(),(*wftp)[(*wp)[*it].GetWorkFlowID()].getNotChosenWork()->size(),(*wftp)[(*wp)[*it].GetWorkFlowID()].getBeginWorkID());*/
			//((Worker*)(ut.getUser(WorkerId)))->setWorkList(*it);
			/*for(set<int>::iterator is=(*wftp)[(*wp)[*it].GetWorkFlowID()].getNotChosenWork()->begin();is!=(*wftp)[(*wp)[*it].GetWorkFlowID()].getNotChosenWork()->end();is++){
			printf("before workflow %d:%d\n",(*wftp)[(*wp)[*it].GetWorkFlowID()].getWorkFlowID(),*is);
			}*/
			(*wftp)[(*wp)[*it].GetWorkFlowID()].deleteNotChosenWork((*wp)[*it].GetWorkID());
			/*for(set<int>::iterator is=(*wftp)[(*wp)[*it].GetWorkFlowID()].getNotChosenWork()->begin();is!=(*wftp)[(*wp)[*it].GetWorkFlowID()].getNotChosenWork()->end();is++){
			printf("now workflow %d:%d\n",(*wftp)[(*wp)[*it].GetWorkFlowID()].getWorkFlowID(),*is);
			}*/
			if ((*wftp)[(*wp)[*it].GetWorkFlowID()].isReady()) {
				NotReadyWorkFlow.erase((*wp)[*it].GetWorkFlowID());
				int i = (*wftp)[(*wp)[*it].GetWorkFlowID()].getBeginWorkID();
				(*wp)[i].SetStatus(UnderWorking);
				//printf("work %d is under working\n",i);
				/*for(;i!=-1;i=(*wp)[i].GetNextWorkID()){
				printf("\n+%d %d %d\n",i,(*wp)[i].GetPreWorkID(),(*wp)[i].GetNextWorkID());
				}*/
			}
		}
	}
}

void Database::CheckIsOk(int WorkId) {
	map<int, work>* wp = wt.getTable();
	work* w = &((*wp)[WorkId]);
	w->SetStatus(UnderWorking);
	(*wp)[w->GetPreWorkID()].SetStatus(Checked);
}

void Database::CheckIsNotOk(int WorkId) {
	map<int, work>* wp = wt.getTable();
	work* w = &((*wp)[WorkId]);
	w->SetStatus(Waiting);
	(*wp)[w->GetPreWorkID()].SetStatus(NeedToRework);
}

void Database::HandIn(int WorkId) {
	map<int, work>* wp = wt.getTable();
	work* w = &((*wp)[WorkId]);
	w->SetStatus(HandedIn);
	if (w->GetNextWorkID() != -1) (*wp)[w->GetNextWorkID()].SetStatus(NeedCheck);
	else printf("Work is done!\n");
	//the last one hands in his job,can define other behaviors.
}

UserTable* Database::getUserTable() {
	return &ut;
}


void Database::setWorkTypeTable(int i) {
	wtt.setTable(i, "something");
}

WorkTypeTable* Database::getWorkTypeTable() {
	return &wtt;
}

WorkTable* Database::getWorkTable() {
	return &wt;
}

vector<int>* Database::GetWorkListByWorkerID(int WorkerID) {
	List.clear();
	for (map<int, work>::iterator it = (*(wt.getTable())).begin();it != (*(wt.getTable())).end();it++) {
		if (it->second.GetWorkerID() == WorkerID) List.push_back(it->first);
	}
	/*for(vector<int>::iterator is=vec.begin();is!=vec.end();is++){
	printf("!%d\n",*is);
	}*/
	return &List;
}
//ͨ��workID���ڱ�����work
work* Database::getWorkPointByWorkID(int ID) {
	if ((*(wt.getTable())).find(ID) != (*(wt.getTable())).end()) return &(*(wt.getTable()))[ID];
	else return NULL; //error:invalid input
}

vector<int>* Database::GetWorkFlowListByCreatorID(int CreatorId) {
	List.clear();
	for (map<int, workFlow>::iterator it = (*(wft.getTable())).begin();it != (*(wft.getTable())).end();it++) {
		if (it->second.getCreatorID() == CreatorId) List.push_back(it->first);
	}
	return &List;
}

WorkFlowTable* Database::getWorkFlowTable() {
	return &wft;
}

//����
void Database::initialWorkTypeTable(vector<int> vec) {
	vector<int>::iterator it;
	int i = 1;
	for (it = vec.begin(); it != vec.end(); i++, it++) wtt.setTable(i, *it);
}