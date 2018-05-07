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
		if (MainPageChoose == 1)//进入注册界面
		{	
			int tempRegistPage = view.RegistPage();
			if (tempRegistPage == 2);//返回主界面
			else if (tempRegistPage == 1)//进入注册
			{
				int intUserType = view.PrintUserType();
				if (intUserType==1)//选择注册用户类型为creator
				{
					while (1)//有效注册名
					{
						tempName = view.GetUserName();//从输入界面得到用户注册名
												      //查重
						if (model.searchUserName(tempName) == 0) break;//查到该注册名未被注册过
						else cout << "用户名已经注册过！请重新输入！" << endl;
					}
					while (1)//有效密码，后续添加筛选步骤
					{
						tempPassword = view.GetPassword();//从输入界面得到用户注册的密码
						break;//后续补充
					}
					model.RegistCreator(tempName, tempPassword);//保存用户信息；
					cout << "注册creator成功" << endl;
				}
				else if (intUserType == 2)//选择注册用户类型为worker
				{
					while (1)//有效注册名
					{
						tempName = view.GetUserName();//从输入界面得到用户注册名
													  //查重
						if (model.searchUserName(tempName) == 0) break;//查到该注册名未被注册过
						else cout << "用户名已经注册过！请重新输入！" << endl;
					}
					while (1)//有效密码，后续添加筛选步骤
					{
						tempPassword = view.GetPassword();//从输入界面得到用户注册的密码
						break;//后续补充
					}
					model.RegistWorker(tempName, tempPassword);//保存用户信息
					cout << "注册worker成功" << endl;

					vector<int> ChosenWorkTypeList;//定义vector数组存放用户选择的工作类型
					vector<int> WorkTypeList;
		reset1:     WorkTypeList=model.GetWorkTypeList();//可供用户选择的工作类型（可选多个）
					//reset1是熊浩然写的
					int flag = view.PrintWorkType(WorkTypeList);
					while (flag != 0)//选择工作类型还没有结束
					{
						if (flag == -1)//不小心选错了；
						{
							ChosenWorkTypeList.clear();
							goto reset1;
						}
						else {//选择了某个工作类型，需要把该工作类型从可选工作类型列表中删除，并添加到用户自己的workTypeList数组中
							ChosenWorkTypeList.push_back(WorkTypeList[flag - 1]);//把用户选择的工作类型加到自己的数组；
							WorkTypeList.erase(WorkTypeList.begin() + flag - 1);//把用户选择的工作类型从用户可选的工作类型中删除；
							flag = view.PrintWorkType(WorkTypeList);//继续输入
						}
					}
					//while(1)结束后，我们已经得到一个ChosenWorkTypeList的数组，存放了用户选择的能做的工作类型；
					//把工作类型更新进worker的资料信息
					for(auto i = ChosenWorkTypeList.begin(); i!=ChosenWorkTypeList.end();i++)
						model.getWorkTypeTable()->setTable(*i, model.getUserTable()->getUser(tempName)->getUserID());//把ID更新了
					cout << "Worker已经完全注册并保存成功！！" << endl;
				}
			}
			else cout << "error input found!" << endl;//输入错误
		}
		else if (MainPageChoose == 2)//进入登录界面
		{
			while (1)
			{
				tempName = view.GetUserName();//从输入界面得到用户登录信息
				if (tempName == "0") goto BackToMainPage;
				tempPassword = view.GetPassword();//从输入界面得到用户密码
				if (tempPassword == "0") goto BackToMainPage;
			   //检查是否输入正确
				if (model.searchUserInfo(tempName, tempPassword))break;//匹配成功
				else cout << "用户名和密码错误！请重新输入！" << endl;
			}
			//对用户进行识别，是creator还是worker；
			tempUser = model.getUserPoint(tempName, tempPassword);//将用户找出来
			if (tempUser->getUserType()==1)//是creator类型用户
			{
				int ID1 = (*tempUser).getUserID();//获得creator的ID
				int flagCreator;
			BackToCreatorPage:	  flagCreator = view.CreatorPage();//打印出creatorpage并让用户进行输入的结果返回给flagCreator;
				if (flagCreator == 1)//用户想创建新的workflow;
				{
					vector<int> WorkTypeList = model.GetWorkTypeList();//得到所有的worktype 的列表
					vector<int> WorkFlow;
					int workFlag = view.CreatWorkFlowPage(WorkTypeList);
					while (workFlag!=0)//挑选worktype组成workflow,还未挑选结束
					{
						if (workFlag == -1)//不小心选错了
							 WorkFlow.clear();//重新来过
						else //选择好了想要的work type，加入到workflow里
							 WorkFlow.push_back(WorkTypeList[workFlag - 1]);//把选好的work type放进workflow！
						workFlag = view.CreatWorkFlowPage(WorkTypeList);
					}
					//while(1)到此处表示已经选好了work type组成了一个workflow
					model.CreateWorkFlow(WorkFlow, (Creator*)tempUser);//把workflow跟creator绑定，并更新相关信息；
					//创建结束，回到creator界面
					goto BackToCreatorPage;
				}
				else if (flagCreator == 2)//用户想查看已有的workflow；
				{
					vector<int>* WorkFlowList = model.GetWorkFlowListByCreatorID(ID1);//把该用户创建过的所有workflow的ID输入到一个数组里
					int WhichWorkFlow = view.PrintWorkFlowPage(*WorkFlowList);//输出该数组，得到用户想对某个workflow操作的具体行为
					/*此处应添加creator对每个具体的workflow应有的操作，之后会进行添加，此处由于程序员快死了，略过*/
					for (int i = (*(model.getWorkFlowTable()->getTable()))[WhichWorkFlow].getBeginWorkID();i != -1;i = (*(model.getWorkTable()->getTable()))[i].GetNextWorkID()) {
						cout << (*(model.getWorkTable()->getTable()))[i].GetWorkID() << ":" << (*(model.getWorkTable()->getTable()))[i].getStatus() << endl;
					}
					//此处令其直接返回到creator page
					goto BackToCreatorPage;
				}
				else if (flagCreator == 3);//用户想注销登录；
				else
				{
					cout << "输入错误！！" << endl;//程序员已经快崩溃了
					goto BackToCreatorPage;//刷新页面
				}
			}

			else//是worker类型的用户
			{
				int ID0 = tempUser->getUserID();//获得worker的ID；
				int FlagWorker;
			BackToWorkerPage:   FlagWorker = view.WorkerPage();//打印出workerpage并获得返回结果；
				if (FlagWorker == 1)//查看可接任务列表
				{
					vector<int> ChosenWorkList;//定义自己的已经接下的任务列表
					vector<int> ToCheckList = model.GetToCheckListByWorkerID(ID0);//把他能接的工作列出来；
					int FlagToGetWhichWork;
				BackToCheckListPage:  FlagToGetWhichWork = view.PrintToCheckListPage(ToCheckList);//打印可接任务列表并返回想要进行的操作
					while (FlagToGetWhichWork!=0)//还在继续接任务
					{
						if (FlagToGetWhichWork == -1)//接错了
						{
							ChosenWorkList.clear();
							goto BackToCheckListPage;
						}
						else
						{
							ChosenWorkList.push_back(ToCheckList[FlagToGetWhichWork - 1]);//把要接的任务放进自己的已接任务列表；
							ToCheckList.erase(ToCheckList.begin()+ FlagToGetWhichWork - 1);//可接任务列表中删除已接任务；
							FlagToGetWhichWork = view.PrintToCheckListPage(ToCheckList);
						}
					}
					//while出来以后表示已经挑好了任务，改变ToCheckList的状态就可以
					model.UpdateToCheckList(ChosenWorkList, ID0);//把已接任务的状态改成已经被接了
					goto BackToWorkerPage;
				}
				else if (FlagWorker == 2)//查看已接任务列表
				{
					vector<int>* WorkList = model.GetWorkListByWorkerID(ID0);//把该用户接过的所有work的ID输入到一个数组里，以指针存储
					int ToWhichWork = view.PrintWorkList(*WorkList);//打印工作列表；返回想要对具体某项工作的操作；
					if (ToWhichWork == 0) goto BackToWorkerPage;//如果用户不想对工作进行操作，直接返回；
					tempWork = model.getWorkPointByWorkID((*WorkList)[ToWhichWork - 1]);
					WorkingStatus Status = (*tempWork).getStatus();//得到该项工作的进度状态；
					int StatusOperation;
					StatusOperation = view.PrintWorkOperation(Status);//根据状态，返回worker想对当前work的操作
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
					//到这里直接回到workerPage
					goto BackToWorkerPage;
				}
				else if (FlagWorker == 3);//注销登录
				else
				{
					cout << "输入错误！返回worker界面！" << endl;
					goto BackToWorkerPage;
				}
			}
		}
		else if (MainPageChoose == 3)//增加工作类型
		{
			int tempWorkTypeId;
			vector<int> WorkTypeId;
			while (view.ContinueOrNot())
			{
				cout << "请输入工作名称：" << endl;
				cin >> tempWorkTypeId;
				model.setWorkTypeTable(tempWorkTypeId);
			}
			//model.initialWorkTypeTable(WorkTypeId);
			goto BackToMainPage;
		}
		else cout << "error input found!" << endl;//输入错误
	}




}

