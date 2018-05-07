#include"View.h"

using namespace std;

//登录注册主界面
int View::MainPage() {//打印出“1、注册”和“2、登录”
	int i = 0;
	cout << "1.注册" << endl << "2.登录" << endl
		 << "3.增加工作类型" << endl;
	cin >> i;
	return i;
};


 //注册部分
int View::RegistPage() {//打印"1、输入用户名和密码"和“2、返回主界面”；
	int i = 0;
	cout <<"1.输入用户名和密码" << endl << "2.返回主界面" << endl;
	cin >> i;
	return i;
}

string View::GetUserName() {//要求用户输入用户名和密码，并返回两个string
	string username;
	cout << "请输入用户名：（按0返回上一层）" << endl;
	cin >> username;
	return username;
}
string View::GetPassword()//要求用户输入密码
{
	string password;
	cout << "请输入密码： （按0返回上一层）" << endl;
	cin >> password;
	return password;
}

int View::PrintUserType() {//打印“1、creator”和“2、worker”并要求选择输入，返回输入值；
	int i = 0;
	cout << "1.creator" << endl << "2.worker" << endl;
	cin >> i;
	return i;
}

int View::PrintWorkType(vector<int> & WorkTypeList) {
	//传入work type并打印出来，让用户选择；增加选项：返回0表示选择结束，-1表示选择错误；
	//！！！！此处返回值是workType在该List中的编号！！从1开始！！
	int i=0;
	cout << "请输入能胜任的工作类型编号(可多选)：" << endl;
	cout << "-1:" << "手抖选错，让我重新选一下吧！" << endl;
	cout << "0:" << "选择结束!"<<endl;
	for (int j = 0; j != WorkTypeList.size(); j++)
		cout << j + 1 << "." << WorkTypeList[j] << ";" << endl;
	cin >> i;
	return i;
}

//登录部分
//LogIn使用GetUserInfo();
//1、creator 界面
int View::CreatorPage() {//打印“1、创建 workflow”，“2、查看workflow”， “3、注销登录”
	int i = 0;
	cout << "1.创建 workflow" << endl << "2.查看workflow" << endl<<"3.注销登录"<<endl;
	cin >> i;
	return i;
}

int View::CreatWorkFlowPage(vector<int>& WorkFlowList) {
	//打印work type 数组；让用户选择；增加选项：输入0表示选择结束，返回-1表示输入错误；把选择的worktype封进一个vector,把vector传入并打印
	//这个和PrintWorkType 不一样，
	//！！！！此处返回值是workType在该List中的编号！！从1开始！！
	int i = 0;
	cout << "请输入需要的工作类型编号(可多选)：" << endl;
	cout << "-1:" << "选错重来！" << endl;
	cout << "0:" << "选择结束!" << endl;
	for (int j = 0; j != WorkFlowList.size(); j++)
		cout <<j+1<<". "<< WorkFlowList[j] << "." << endl;
	cin >> i;
	return i;
}

int View::PrintWorkFlowPage(vector<int>& WorkFlowList) {//打印已有workflow page,让用户选择查看每个workflow；
	int i = 0;
	cout << "选择一个工作流:" << endl;
	for (int j = 0; j != WorkFlowList.size(); j++)
		cout << j + 1 << ". " << WorkFlowList[j] << ";" << endl;
	cin >> i;
	return i;
}


//2、worker 界面
int View::WorkerPage() {//打印“1、查看待接任务”，“2、查看已接任务”，“3、注销登录”
	int i = 0;
	cout << "1.查看待接任务" << endl << "2.查看已接任务" << endl << "3.注销登录" << endl;
	cin >> i;
	return i;
}

int View::PrintToCheckListPage(vector<int>& ToCheckList) {
	//打印待接任务，让用户选择输入，输入0表示选择结束，-1表示选择错误（重来）
    //！！！！此处返回值是CheckWORK在该List中的编号！！从1开始！！
	int i = 0;
	cout << "待接工作全览：" << endl;
	cout << "-1:" << "手抖选错，让我重新选一下吧！" << endl;
	cout << "0:" << "选择结束!" << endl;
	for (int j = 0; j != ToCheckList.size(); j++)
		cout << j + 1 << ". " << ToCheckList[j] << ";" << endl;
	cin >> i;
	return i;
}


int View::PrintWorkList(vector<int>& WorkList) {
	//打印已接任务列表，让用户选择某个任务进行具体操作；
    //！！！！此处返回值是work在该List中的编号！！从1开始！！
	int i = 0;
	cout << "选择一个已接工作：" << endl;
	for (int j = 0; j != WorkList.size(); j++)
		cout << j + 1 << ". " << WorkList[j] << ";" << endl;
	cin >> i;
	return i;
}

int View::PrintWorkOperation(WorkingStatus Status) {
	//根据任务状态打印对任务的可用操作，让用户进行选择；
	//如果任务状态是“waiting" 则打印“按0返回上一层”；
	//如果任务状态是“need check”则打印“按1进行check”,"按2为check不通过"，“按0返回上一层”
	//如果任务状态是“underworking”则打印“1、Hand in”，“0返回上一层”
	//如果任务状态是“hand in”则打印“按0返回上一层”
	//如果任务状态是“checked in ”则打印“按0返回上一层”
	//如果任务状态是“need to rework”则打印“按1 Hand in”,“按0返回上一层”
	int i = 0;
	switch (Status)
	{
	case Waiting:
	case HandedIn:
	case Checked:
		cout << "按0返回上一层" << endl;
		break;
	case NeedCheck:
		cout << "按1进行check" << endl<<"按2为check不通过"<<endl<<"按0返回上一层"<<endl;
		break;
	case UnderWorking:
	case NeedToRework:
		cout << "1.Hand in" << endl<<"按0返回上一层"<<endl;
		break;
	default:
		cout << "wrong status!" << endl;
		break;
	}
	cin >> i;
	return i;
}

int View::ContinueOrNot()
{
	int i;
	cout << "1.继续	0.结束" << endl;
	cin >> i;
	return i;
}

