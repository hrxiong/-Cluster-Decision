#pragma once

#include<iostream>

#include<string>


typedef enum WorkingStatus
{
	/*
	ÿ���Ѿ��ӺõĹ�����״̬���ȴ��ϼ��ύ����Ҫ�Լ�ȷ���ϼ��Ѿ���ɡ��Լ����������Լ��Ѿ������ύ���ȴ��¼�ȷ�ϣ�
	�¼��Ѿ�ȷ���Լ��깤���¼Ҿ�������Ҫ�޸ģ�
	*/
	Waiting,//the work is being worked by the previous guy;
	NeedCheck,//the previous guy has handed in, you need to check his work
	UnderWorking,//you are working with it 
	HandedIn,//you have done your work and handed in, waiting to be checked by the next guy;
	Checked,//your work is completed;
	NeedToRework//work failed.need to fix your work;
}WorkingStatus;

typedef enum CheckStatus
{
	/*ÿ�������Ĺ�����״̬��δ����ȡ���ѱ���ȡ��
	*/
	Chosen,
	unChosen
};
typedef struct USER
{
	std::string username;//�û���
	std::string password;//����

}user;

struct WorkType {

	int WorkTypeId;//������������
};

struct Worker {
	user UserInfo;//�����ߵ��û���������
	int WorkerId;//�����ߵ�ID

};
struct WorkerJobType
{
	int WorkerJobTypeId;//�����ID
	int WorkerId;//�������ֹ�����Ĺ����ߵ�ID
	int WorkTypeId;//���ֹ������ID
};
struct Work
{
	int WorkId;//����ID
	int WorkerJobTypeId;//�÷ݹ����Ĺ������͵�ID
	int WorkFlowId;//�÷ݹ��������ĸ���������ID
	int PreWorkListId;//�ù���ǰһ��������ID
	int NextWorkListId;
	WorkingStatus Status;//�÷ݹ����Ľ���״̬
};

struct WorkFlow
{
	int WorkFlowId;//to identify this flow
	int WorkFlowCreatorId;//to identify creator's id;
};

struct WorkFlowCreator
{
	user UserInfo;//�û���������
	int WorkCreatorId;//�����ID
};

struct ToCheckList
{
	int ToCheckId;//�ȴ����ӵ��Ĺ�����ID
	int WorkTypeId;//�ù����Ĺ�������ID��
	int WorkerId;
	//int WorkCreatorId;//�ù����ķ�����ID
	int PreWorkTypeId;//��һ���������Ĺ���ID
	int NextWorkTypeId;
	int ToCheckWorkFlowId;
	CheckStatus ChooseStatus;//�ù����Ƿ���ȡ��״̬

};
struct ToCheckWorkFlow
{
	int ToCheckWorkFlowId;//��Ҫȷ�ϵĹ�������ID��
	int WorkCreatorId;//������������ID��
	int WorkNumber;//�ܹ�������
	int CheckedWorkNumber;//�Ѿ���������Ĺ�������
};



