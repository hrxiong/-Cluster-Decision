#include"View.h"

using namespace std;

//��¼ע��������
int View::MainPage() {//��ӡ����1��ע�ᡱ�͡�2����¼��
	int i = 0;
	cout << "1.ע��" << endl << "2.��¼" << endl
		 << "3.���ӹ�������" << endl;
	cin >> i;
	return i;
};


 //ע�Ჿ��
int View::RegistPage() {//��ӡ"1�������û���������"�͡�2�����������桱��
	int i = 0;
	cout <<"1.�����û���������" << endl << "2.����������" << endl;
	cin >> i;
	return i;
}

string View::GetUserName() {//Ҫ���û������û��������룬����������string
	string username;
	cout << "�������û���������0������һ�㣩" << endl;
	cin >> username;
	return username;
}
string View::GetPassword()//Ҫ���û���������
{
	string password;
	cout << "���������룺 ����0������һ�㣩" << endl;
	cin >> password;
	return password;
}

int View::PrintUserType() {//��ӡ��1��creator���͡�2��worker����Ҫ��ѡ�����룬��������ֵ��
	int i = 0;
	cout << "1.creator" << endl << "2.worker" << endl;
	cin >> i;
	return i;
}

int View::PrintWorkType(vector<int> & WorkTypeList) {
	//����work type����ӡ���������û�ѡ������ѡ�����0��ʾѡ�������-1��ʾѡ�����
	//���������˴�����ֵ��workType�ڸ�List�еı�ţ�����1��ʼ����
	int i=0;
	cout << "��������ʤ�εĹ������ͱ��(�ɶ�ѡ)��" << endl;
	cout << "-1:" << "�ֶ�ѡ����������ѡһ�°ɣ�" << endl;
	cout << "0:" << "ѡ�����!"<<endl;
	for (int j = 0; j != WorkTypeList.size(); j++)
		cout << j + 1 << "." << WorkTypeList[j] << ";" << endl;
	cin >> i;
	return i;
}

//��¼����
//LogInʹ��GetUserInfo();
//1��creator ����
int View::CreatorPage() {//��ӡ��1������ workflow������2���鿴workflow���� ��3��ע����¼��
	int i = 0;
	cout << "1.���� workflow" << endl << "2.�鿴workflow" << endl<<"3.ע����¼"<<endl;
	cin >> i;
	return i;
}

int View::CreatWorkFlowPage(vector<int>& WorkFlowList) {
	//��ӡwork type ���飻���û�ѡ������ѡ�����0��ʾѡ�����������-1��ʾ������󣻰�ѡ���worktype���һ��vector,��vector���벢��ӡ
	//�����PrintWorkType ��һ����
	//���������˴�����ֵ��workType�ڸ�List�еı�ţ�����1��ʼ����
	int i = 0;
	cout << "��������Ҫ�Ĺ������ͱ��(�ɶ�ѡ)��" << endl;
	cout << "-1:" << "ѡ��������" << endl;
	cout << "0:" << "ѡ�����!" << endl;
	for (int j = 0; j != WorkFlowList.size(); j++)
		cout <<j+1<<". "<< WorkFlowList[j] << "." << endl;
	cin >> i;
	return i;
}

int View::PrintWorkFlowPage(vector<int>& WorkFlowList) {//��ӡ����workflow page,���û�ѡ��鿴ÿ��workflow��
	int i = 0;
	cout << "ѡ��һ��������:" << endl;
	for (int j = 0; j != WorkFlowList.size(); j++)
		cout << j + 1 << ". " << WorkFlowList[j] << ";" << endl;
	cin >> i;
	return i;
}


//2��worker ����
int View::WorkerPage() {//��ӡ��1���鿴�������񡱣���2���鿴�ѽ����񡱣���3��ע����¼��
	int i = 0;
	cout << "1.�鿴��������" << endl << "2.�鿴�ѽ�����" << endl << "3.ע����¼" << endl;
	cin >> i;
	return i;
}

int View::PrintToCheckListPage(vector<int>& ToCheckList) {
	//��ӡ�����������û�ѡ�����룬����0��ʾѡ�������-1��ʾѡ�����������
    //���������˴�����ֵ��CheckWORK�ڸ�List�еı�ţ�����1��ʼ����
	int i = 0;
	cout << "���ӹ���ȫ����" << endl;
	cout << "-1:" << "�ֶ�ѡ����������ѡһ�°ɣ�" << endl;
	cout << "0:" << "ѡ�����!" << endl;
	for (int j = 0; j != ToCheckList.size(); j++)
		cout << j + 1 << ". " << ToCheckList[j] << ";" << endl;
	cin >> i;
	return i;
}


int View::PrintWorkList(vector<int>& WorkList) {
	//��ӡ�ѽ������б����û�ѡ��ĳ��������о��������
    //���������˴�����ֵ��work�ڸ�List�еı�ţ�����1��ʼ����
	int i = 0;
	cout << "ѡ��һ���ѽӹ�����" << endl;
	for (int j = 0; j != WorkList.size(); j++)
		cout << j + 1 << ". " << WorkList[j] << ";" << endl;
	cin >> i;
	return i;
}

int View::PrintWorkOperation(WorkingStatus Status) {
	//��������״̬��ӡ������Ŀ��ò��������û�����ѡ��
	//�������״̬�ǡ�waiting" ���ӡ����0������һ�㡱��
	//�������״̬�ǡ�need check�����ӡ����1����check��,"��2Ϊcheck��ͨ��"������0������һ�㡱
	//�������״̬�ǡ�underworking�����ӡ��1��Hand in������0������һ�㡱
	//�������״̬�ǡ�hand in�����ӡ����0������һ�㡱
	//�������״̬�ǡ�checked in �����ӡ����0������һ�㡱
	//�������״̬�ǡ�need to rework�����ӡ����1 Hand in��,����0������һ�㡱
	int i = 0;
	switch (Status)
	{
	case Waiting:
	case HandedIn:
	case Checked:
		cout << "��0������һ��" << endl;
		break;
	case NeedCheck:
		cout << "��1����check" << endl<<"��2Ϊcheck��ͨ��"<<endl<<"��0������һ��"<<endl;
		break;
	case UnderWorking:
	case NeedToRework:
		cout << "1.Hand in" << endl<<"��0������һ��"<<endl;
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
	cout << "1.����	0.����" << endl;
	cin >> i;
	return i;
}

