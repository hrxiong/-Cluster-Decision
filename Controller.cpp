#include"Controller.h"

#include"User.h"
#include<vector>
using namespace std;

static string tempName;
static string tempPassword;
User* tempUser;
work* tempWork;
void Controller::ControlLogic()
{
	
	while (1)
	{
	BackToMainPage:	int MainPageChoose;
		MainPageChoose = view.MainPage();
		if (MainPageChoose == 1)//����ע�����
		{	
			int tempRegistPage = view.RegistPage();
			if (tempRegistPage == 2);//����������
			else if (tempRegistPage == 1)//����ע��
			{
				int intUserType = view.PrintUserType();
				if (intUserType==1)//ѡ��ע���û�����Ϊcreator
				{
					while (1)//��Чע����
					{
						tempName = view.GetUserName();//���������õ��û�ע����
												      //����
						if (model.searchUserName(tempName) == 0) break;//�鵽��ע����δ��ע���
						else cout << "�û����Ѿ�ע��������������룡" << endl;
					}
					while (1)//��Ч���룬�������ɸѡ����
					{
						tempPassword = view.GetPassword();//���������õ��û�ע�������
						break;//��������
					}
					model.RegistCreator(tempName, tempPassword);//�����û���Ϣ��
					cout << "ע��creator�ɹ�" << endl;
				}
				else if (intUserType == 2)//ѡ��ע���û�����Ϊworker
				{
					while (1)//��Чע����
					{
						tempName = view.GetUserName();//���������õ��û�ע����
													  //����
						if (model.searchUserName(tempName) == 0) break;//�鵽��ע����δ��ע���
						else cout << "�û����Ѿ�ע��������������룡" << endl;
					}
					while (1)//��Ч���룬�������ɸѡ����
					{
						tempPassword = view.GetPassword();//���������õ��û�ע�������
						break;//��������
					}
					model.RegistWorker(tempName, tempPassword);//�����û���Ϣ
					cout << "ע��worker�ɹ�" << endl;

					vector<int> ChosenWorkTypeList;//����vector�������û�ѡ��Ĺ�������
					vector<int> WorkTypeList;
		reset1:     WorkTypeList=model.GetWorkTypeList();//�ɹ��û�ѡ��Ĺ������ͣ���ѡ�����
					//reset1���ܺ�Ȼд��
					int flag = view.PrintWorkType(WorkTypeList);
					while (flag != 0)//ѡ�������ͻ�û�н���
					{
						if (flag == -1)//��С��ѡ���ˣ�
						{
							ChosenWorkTypeList.clear();
							goto reset1;
						}
						else {//ѡ����ĳ���������ͣ���Ҫ�Ѹù������ʹӿ�ѡ���������б���ɾ��������ӵ��û��Լ���workTypeList������
							ChosenWorkTypeList.push_back(WorkTypeList[flag - 1]);//���û�ѡ��Ĺ������ͼӵ��Լ������飻
							WorkTypeList.erase(WorkTypeList.begin() + flag - 1);//���û�ѡ��Ĺ������ʹ��û���ѡ�Ĺ���������ɾ����
							flag = view.PrintWorkType(WorkTypeList);//��������
						}
					}
					//while(1)�����������Ѿ��õ�һ��ChosenWorkTypeList�����飬������û�ѡ��������Ĺ������ͣ�
					//�ѹ������͸��½�worker��������Ϣ
					for(auto i = ChosenWorkTypeList.begin(); i!=ChosenWorkTypeList.end();i++)
						model.getWorkTypeTable()->setTable(*i, model.getUserTable()->getUser(tempName)->getUserID());//��ID������
					cout << "Worker�Ѿ���ȫע�Ტ����ɹ�����" << endl;
				}
			}
			else cout << "error input found!" << endl;//�������
		}
		else if (MainPageChoose == 2)//�����¼����
		{
			while (1)
			{
				tempName = view.GetUserName();//���������õ��û���¼��Ϣ
				if (tempName == "0") goto BackToMainPage;
				tempPassword = view.GetPassword();//���������õ��û�����
				if (tempPassword == "0") goto BackToMainPage;
			   //����Ƿ�������ȷ
				if (model.searchUserInfo(tempName, tempPassword))break;//ƥ��ɹ�
				else cout << "�û���������������������룡" << endl;
			}
			//���û�����ʶ����creator����worker��
			tempUser = model.getUserPoint(tempName, tempPassword);//���û��ҳ���
			if (tempUser->getUserType()==1)//��creator�����û�
			{
				int ID1 = (*tempUser).getUserID();//���creator��ID
				int flagCreator;
			BackToCreatorPage:	  flagCreator = view.CreatorPage();//��ӡ��creatorpage�����û���������Ľ�����ظ�flagCreator;
				if (flagCreator == 1)//�û��봴���µ�workflow;
				{
					vector<int> WorkTypeList = model.GetWorkTypeList();//�õ����е�worktype ���б�
					vector<int> WorkFlow;
					int workFlag = view.CreatWorkFlowPage(WorkTypeList);
					while (workFlag!=0)//��ѡworktype���workflow,��δ��ѡ����
					{
						if (workFlag == -1)//��С��ѡ����
							 WorkFlow.clear();//��������
						else //ѡ�������Ҫ��work type�����뵽workflow��
							 WorkFlow.push_back(WorkTypeList[workFlag - 1]);//��ѡ�õ�work type�Ž�workflow��
						workFlag = view.CreatWorkFlowPage(WorkTypeList);
					}
					//while(1)���˴���ʾ�Ѿ�ѡ����work type�����һ��workflow
					model.CreateWorkFlow(WorkFlow, (Creator*)tempUser);//��workflow��creator�󶨣������������Ϣ��
					//�����������ص�creator����
					goto BackToCreatorPage;
				}
				else if (flagCreator == 2)//�û���鿴���е�workflow��
				{
					vector<int>* WorkFlowList = model.GetWorkFlowListByCreatorID(ID1);//�Ѹ��û�������������workflow��ID���뵽һ��������
					int WhichWorkFlow = view.PrintWorkFlowPage(*WorkFlowList);//��������飬�õ��û����ĳ��workflow�����ľ�����Ϊ
					/*�˴�Ӧ���creator��ÿ�������workflowӦ�еĲ�����֮��������ӣ��˴����ڳ���Ա�����ˣ��Թ�*/
					for (int i = (*(model.getWorkFlowTable()->getTable()))[WhichWorkFlow].getBeginWorkID();i != -1;i = (*(model.getWorkTable()->getTable()))[i].GetNextWorkID()) {
						cout << (*(model.getWorkTable()->getTable()))[i].GetWorkID() << ":" << (*(model.getWorkTable()->getTable()))[i].getStatus() << endl;
					}
					//�˴�����ֱ�ӷ��ص�creator page
					goto BackToCreatorPage;
				}
				else if (flagCreator == 3);//�û���ע����¼��
				else
				{
					cout << "������󣡣�" << endl;//����Ա�Ѿ��������
					goto BackToCreatorPage;//ˢ��ҳ��
				}
			}

			else//��worker���͵��û�
			{
				int ID0 = tempUser->getUserID();//���worker��ID��
				int FlagWorker;
			BackToWorkerPage:   FlagWorker = view.WorkerPage();//��ӡ��workerpage����÷��ؽ����
				if (FlagWorker == 1)//�鿴�ɽ������б�
				{
					vector<int> ChosenWorkList;//�����Լ����Ѿ����µ������б�
					vector<int> ToCheckList = model.GetToCheckListByWorkerID(ID0);//�����ܽӵĹ����г�����
					int FlagToGetWhichWork;
				BackToCheckListPage:  FlagToGetWhichWork = view.PrintToCheckListPage(ToCheckList);//��ӡ�ɽ������б�������Ҫ���еĲ���
					while (FlagToGetWhichWork!=0)//���ڼ���������
					{
						if (FlagToGetWhichWork == -1)//�Ӵ���
						{
							ChosenWorkList.clear();
							goto BackToCheckListPage;
						}
						else
						{
							ChosenWorkList.push_back(ToCheckList[FlagToGetWhichWork - 1]);//��Ҫ�ӵ�����Ž��Լ����ѽ������б�
							ToCheckList.erase(ToCheckList.begin()+ FlagToGetWhichWork - 1);//�ɽ������б���ɾ���ѽ�����
							FlagToGetWhichWork = view.PrintToCheckListPage(ToCheckList);
						}
					}
					//while�����Ժ��ʾ�Ѿ����������񣬸ı�ToCheckList��״̬�Ϳ���
					model.UpdateToCheckList(ChosenWorkList, ID0);//���ѽ������״̬�ĳ��Ѿ�������
					goto BackToWorkerPage;
				}
				else if (FlagWorker == 2)//�鿴�ѽ������б�
				{
					vector<int>* WorkList = model.GetWorkListByWorkerID(ID0);//�Ѹ��û��ӹ�������work��ID���뵽һ���������ָ��洢
					int ToWhichWork = view.PrintWorkList(*WorkList);//��ӡ�����б�������Ҫ�Ծ���ĳ����Ĳ�����
					if (ToWhichWork == 0) goto BackToWorkerPage;//����û�����Թ������в�����ֱ�ӷ��أ�
					tempWork = model.getWorkPointByWorkID((*WorkList)[ToWhichWork - 1]);
					WorkingStatus Status = (*tempWork).getStatus();//�õ�������Ľ���״̬��
					int StatusOperation;
					StatusOperation = view.PrintWorkOperation(Status);//����״̬������worker��Ե�ǰwork�Ĳ���
					switch (Status)
					{
					case Waiting:
						break;
					case NeedCheck: {
						if (StatusOperation == 1) model.CheckIsOk((*WorkList)[ToWhichWork - 1]);
						else if (StatusOperation == 2) model.CheckIsNotOk((*WorkList)[ToWhichWork - 1]);
						break;
					}
					case UnderWorking: {
						if (StatusOperation == 1) model.HandIn((*WorkList)[ToWhichWork - 1]);
						break; }
					case HandedIn:
						break;
					case Checked:
						break;
					case NeedToRework:{
						if (StatusOperation == 1) model.HandIn((*WorkList)[ToWhichWork - 1]);
						break; }
					default:
						break;
					}
					//������ֱ�ӻص�workerPage
					goto BackToWorkerPage;
				}
				else if (FlagWorker == 3);//ע����¼
				else
				{
					cout << "������󣡷���worker���棡" << endl;
					goto BackToWorkerPage;
				}
			}
		}
		else if (MainPageChoose == 3)//���ӹ�������
		{
			int tempWorkTypeId;
			vector<int> WorkTypeId;
			while (view.ContinueOrNot())
			{
				cout << "�����빤�����ƣ�" << endl;
				cin >> tempWorkTypeId;
				model.setWorkTypeTable(tempWorkTypeId);
			}
			//model.initialWorkTypeTable(WorkTypeId);
			goto BackToMainPage;
		}
		else cout << "error input found!" << endl;//�������
	}




}

