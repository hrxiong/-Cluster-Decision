#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Database.h"

using namespace std;

class View
{
public:
	//登录注册主界面
	int MainPage();//打印出“1、注册”和“2、登录”


	//注册部分
	int RegistPage();//打印"1、输入用户名和密码"和“2、返回主界面”；
	string GetUserName();//要求用户输入用户名，并返回一个string类型的对象；
	string View::GetPassword();//要求用户输入密码
	int PrintUserType();//打印“1、creator”和“2、worker”并要求选择输入，返回输入值；

	int PrintWorkType(vector<int> & WorkTypeList);//传入work type并打印出来，让用户选择；增加选项：返回0表示选择结束，-1表示选择错误；
	//！！！！此处返回值是workType在该List中的编号！！从1开始！！

	
	//登录部分
	//LogIn使用GetUserInfo();
	//1、creator 界面
	int CreatorPage();//打印“1、创建 workflow”，“2、查看workflow”， “3、注销登录”
	int CreatWorkFlowPage(vector<int>& WorkFlowList);//打印work type 数组；让用户选择；增加选项：输入0表示选择结束，返回-1表示输入错误；把选择的worktype封进一个vector,把vector传入并打印
	//这个和PrintWorkType 不一样，
	//！！！！此处返回值是workType在该List中的编号！！从1开始！！


	int PrintWorkFlowPage(vector<int>& WorkFlowList);//打印已有workflow page,让用户选择查看每个workflow；


	//2、worker 界面
	int WorkerPage();//打印“1、查看待接任务”，“2、查看已接任务”，“3、注销登录”
	int PrintToCheckListPage(vector<int>& ToCheckList);//打印待接任务，让用户选择输入，输入0表示选择结束，-1表示选择错误（重来）
    //！！！！此处返回值是CheckWORK在该List中的编号！！从1开始！！


	int PrintWorkList(vector<int>& WorkList);//打印已接任务列表，让用户选择某个任务进行具体操作；
    //！！！！此处返回值是work在该List中的编号！！从1开始！！
	int PrintWorkOperation(WorkingStatus Status);//根据任务状态打印对任务的可用操作，让用户进行选择；
	//如果任务状态是“waiting" 则打印“按0返回上一层”；
	//如果任务状态是“need check”则打印“按1进行check”,"按2为check不通过"，“按0返回上一层”
	//如果任务状态是“underworking”则打印“1、Hand in”，“0返回上一层”
	//如果任务状态是“hand in”则打印“按0返回上一层”
	//如果任务状态是“checked in ”则打印“按0返回上一层”
	//如果任务状态是“need to rework”则打印“按1 Hand in”,“按0返回上一层”

	int View::ContinueOrNot();
	//打印：“1.继续，0.结束”


};