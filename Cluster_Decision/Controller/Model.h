#pragma once
#include<iostream>
#include"GlobalVariable.h"


class Model
{
private:

public:

	int SearchUserName(user a) {}//��������ڷ���0�������creator�û�����1��worker�û�����2��

	bool SearchUserInfo(user a) {}//�����û��������룬��������ݿ�ƥ��ɹ�������true�����򷵻�false��
	bool JudgeWorkerOrCreator(user a) {}//���û�����ʶ�������creator����true����worker����false;

	int GetId(user a, bool UserType) {}//���UserType��true����creator��false����worker��ͨ��user���ض�Ӧ��WorkFlowCreatorId ����WorkerId;

	void RegistCreator(user a) {}//����creator���󣬽��б��档
	//�� user a ����Ϣ������WorkFlowCreator�����,������һ��Ψһ��ID��

	void RegisterWorker(user a) {}//����worker���󣬽��б��档
	//��user a ����Ϣ������Worker����У�������һ��Ψһ��ID��

	vector<int> GetWorkTypeList() {}//��WorkType�������������Ϣ����vector���棻

	void RegistWorkerJobType(vector<int> &ChosenWorkTypeList, user a) {}//����WorkerJobType��

	void CreatNewWorkFlow(vector<int> &WorkFlow, int CreatorId) {}//���ݴ�������workflow��creator ID������ toCheckList �� toCheckWorkFlow
	//���е�toCheckList�Ĺ���״̬����δ����ȡ��
	//WorkerId ��Ϊ��Чֵ������0��

	vector<int> GetWorkFlowListByCreatorID(int CreatorId) {}//����ͬһcreator�����й�����ID������������Ϣ�Ժ󸽼ӣ�����ID����workflow������

	vector<int> GetToCheckListByWorkerID(int WorkerId) {}//����workerID ��øù������ܹ�������work type���ٰ�toCheckList�е�worktype��Ĺ�����ToCheckID�����б��з��أ�
	//Ҫ��ù�����״̬��δ���ӳ���

	void UpdateToCheckList(vector<int>& ChosenWorkList, int WorkerId) {}//��ÿ���Ѿ��ӳ�������ͬ�ӵ������worker��WorkerId�󶨸��£�
	//�ı�ù�����ChooseStatus��
	//ÿ����һ�����ӳ���������Ҫ����worktypeId����ToCheckWorkFlow�����ݣ�
	//�������ToCheckWOrkFlow���������񶼱��ӳ�����Ѹ�WorkFlow��Ϊ�������ˣ����Կ�ʼ����
	//��Ҫ��������:
	//1����ToCheckWorkFlow�е���Ϣɾ������ӵ�WorkFlow�У�
	//2����ToCheckList�����еĸ�WorkFlow�Ĺ���ɾ������Ӧ��ӵ�Work�У����ѵ�һ��������û��ǰ����Ĺ�����״̬��Ϊ��underworking��


	vector<int> GetWorkListByWorkerID(int WorkerID) {}//����workerId�õ���worker�Ѿ����˵����й�����

	WorkingStatus GetStatusByWorkId(int WorkId) {}//���ݸ�work�õ������

	void CheckIsOk(int WorkId) {}//����workId�ѱ�Work��״̬��Ϊunderworking��ǰ�����Ϊchecked
	void ChechIsNotOk(int WorkId) {}//����workId�ѱ�Work��״̬��Ϊwaiting��ǰ�����ΪNeedtoRework
	void HandIn(int WorkId) {}//����workId�ѱ�Work��״̬��ΪHandedIn���������ΪNeedCheck
};
