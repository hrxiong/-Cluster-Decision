#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Database.h"

using namespace std;

class View
{
public:
	//��¼ע��������
	int MainPage();//��ӡ����1��ע�ᡱ�͡�2����¼��


	//ע�Ჿ��
	int RegistPage();//��ӡ"1�������û���������"�͡�2�����������桱��
	string GetUserName();//Ҫ���û������û�����������һ��string���͵Ķ���
	string View::GetPassword();//Ҫ���û���������
	int PrintUserType();//��ӡ��1��creator���͡�2��worker����Ҫ��ѡ�����룬��������ֵ��

	int PrintWorkType(vector<int> & WorkTypeList);//����work type����ӡ���������û�ѡ������ѡ�����0��ʾѡ�������-1��ʾѡ�����
	//���������˴�����ֵ��workType�ڸ�List�еı�ţ�����1��ʼ����

	
	//��¼����
	//LogInʹ��GetUserInfo();
	//1��creator ����
	int CreatorPage();//��ӡ��1������ workflow������2���鿴workflow���� ��3��ע����¼��
	int CreatWorkFlowPage(vector<int>& WorkFlowList);//��ӡwork type ���飻���û�ѡ������ѡ�����0��ʾѡ�����������-1��ʾ������󣻰�ѡ���worktype���һ��vector,��vector���벢��ӡ
	//�����PrintWorkType ��һ����
	//���������˴�����ֵ��workType�ڸ�List�еı�ţ�����1��ʼ����


	int PrintWorkFlowPage(vector<int>& WorkFlowList);//��ӡ����workflow page,���û�ѡ��鿴ÿ��workflow��


	//2��worker ����
	int WorkerPage();//��ӡ��1���鿴�������񡱣���2���鿴�ѽ����񡱣���3��ע����¼��
	int PrintToCheckListPage(vector<int>& ToCheckList);//��ӡ�����������û�ѡ�����룬����0��ʾѡ�������-1��ʾѡ�����������
    //���������˴�����ֵ��CheckWORK�ڸ�List�еı�ţ�����1��ʼ����


	int PrintWorkList(vector<int>& WorkList);//��ӡ�ѽ������б����û�ѡ��ĳ��������о��������
    //���������˴�����ֵ��work�ڸ�List�еı�ţ�����1��ʼ����
	int PrintWorkOperation(WorkingStatus Status);//��������״̬��ӡ������Ŀ��ò��������û�����ѡ��
	//�������״̬�ǡ�waiting" ���ӡ����0������һ�㡱��
	//�������״̬�ǡ�need check�����ӡ����1����check��,"��2Ϊcheck��ͨ��"������0������һ�㡱
	//�������״̬�ǡ�underworking�����ӡ��1��Hand in������0������һ�㡱
	//�������״̬�ǡ�hand in�����ӡ����0������һ�㡱
	//�������״̬�ǡ�checked in �����ӡ����0������һ�㡱
	//�������״̬�ǡ�need to rework�����ӡ����1 Hand in��,����0������һ�㡱

	int View::ContinueOrNot();
	//��ӡ����1.������0.������


};