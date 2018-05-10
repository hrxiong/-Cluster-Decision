#pragma once
#include<iostream>
#include"GlobalVariable.h"


class Model
{
private:

public:

	int SearchUserName(user a) {}//如果不存在返回0，如果是creator用户返回1，worker用户返回2；

	bool SearchUserInfo(user a) {}//传入用户名和密码，如果与数据库匹配成功，返回true，否则返回false；
	bool JudgeWorkerOrCreator(user a) {}//对用户进行识别，如果是creator返回true，是worker返回false;

	int GetId(user a, bool UserType) {}//如果UserType是true就是creator，false就是worker，通过user返回对应的WorkFlowCreatorId 或者WorkerId;

	void RegistCreator(user a) {}//创建creator对象，进行保存。
	//将 user a 的信息保存在WorkFlowCreator表格中,并生成一个唯一的ID；

	void RegisterWorker(user a) {}//创建worker对象，进行保存。
	//将user a 的信息保存在Worker表格中，并生成一个唯一的ID；

	vector<int> GetWorkTypeList() {}//把WorkType这个表格的所有信息存在vector里面；

	void RegistWorkerJobType(vector<int> &ChosenWorkTypeList, user a) {}//更新WorkerJobType表

	void CreatNewWorkFlow(vector<int> &WorkFlow, int CreatorId) {}//根据传进来的workflow和creator ID，更新 toCheckList 和 toCheckWorkFlow
	//所有的toCheckList的工作状态都是未被领取；
	//WorkerId 均为无效值；比如0；

	vector<int> GetWorkFlowListByCreatorID(int CreatorId) {}//返回同一creator的所有工作流ID；其他返回信息以后附加；仅用ID代表workflow的名字

	vector<int> GetToCheckListByWorkerID(int WorkerId) {}//根据workerID 获得该工作者能够工作的work type，再把toCheckList中的worktype类的工作的ToCheckID放在列表中返回；
	//要求该工作的状态是未被接出的

	void UpdateToCheckList(vector<int>& ChosenWorkList, int WorkerId) {}//把每个已经接出的任务同接到任务的worker的WorkerId绑定更新；
	//改变该工作的ChooseStatus；
	//每增加一件被接出的任务，需要根据worktypeId更新ToCheckWorkFlow的内容；
	//如果发现ToCheckWOrkFlow的所有任务都被接出，则把该WorkFlow视为找齐人了，可以开始工作
	//需要做的事是:
	//1、把ToCheckWorkFlow中的信息删除，添加到WorkFlow中；
	//2、把ToCheckList中所有的该WorkFlow的工作删除，对应添加到Work中，并把第一个工作（没有前项工作的工作）状态设为“underworking”


	vector<int> GetWorkListByWorkerID(int WorkerID) {}//根据workerId得到该worker已经接了的所有工作；

	WorkingStatus GetStatusByWorkId(int WorkId) {}//根据该work得到其进度

	void CheckIsOk(int WorkId) {}//根据workId把本Work的状态改为underworking，前项工作改为checked
	void ChechIsNotOk(int WorkId) {}//根据workId把本Work的状态改为waiting，前项工作改为NeedtoRework
	void HandIn(int WorkId) {}//根据workId把本Work的状态改为HandedIn，后项工作改为NeedCheck
};
