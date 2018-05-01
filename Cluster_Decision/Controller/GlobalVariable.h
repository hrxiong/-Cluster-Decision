#pragma once

#include<iostream>

#include<string>


typedef enum WorkingStatus
{
	/*
	每件已经接好的工作的状态：等待上家提交、需要自己确认上家已经完成、自己正在做、自己已经做完提交并等待下家确认；
	下家已经确认自己完工，下家觉得我们要修改；
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
	/*每件发布的工作的状态：未被领取、已被领取；
	*/
	Chosen,
	unChosen
};
typedef struct USER
{
	std::string username;//用户名
	std::string password;//密码

}user;

struct WorkType {

	int WorkTypeId;//工作类型名称
};

struct Worker {
	user UserInfo;//工作者的用户名和密码
	int WorkerId;//工作者的ID

};
struct WorkerJobType
{
	int WorkerJobTypeId;//本身的ID
	int WorkerId;//能做这种工作类的工作者的ID
	int WorkTypeId;//这种工作类的ID
};
struct Work
{
	int WorkId;//本身ID
	int WorkerJobTypeId;//该份工作的工作类型的ID
	int WorkFlowId;//该份工作属于哪个工作流的ID
	int PreWorkListId;//该工作前一个工作的ID
	int NextWorkListId;
	WorkingStatus Status;//该份工作的进度状态
};

struct WorkFlow
{
	int WorkFlowId;//to identify this flow
	int WorkFlowCreatorId;//to identify creator's id;
};

struct WorkFlowCreator
{
	user UserInfo;//用户名和密码
	int WorkCreatorId;//本身的ID
};

struct ToCheckList
{
	int ToCheckId;//等待被接单的工作的ID
	int WorkTypeId;//该工作的工作类型ID，
	int WorkerId;
	//int WorkCreatorId;//该工作的发布者ID
	int PreWorkTypeId;//上一个被发布的工作ID
	int NextWorkTypeId;
	int ToCheckWorkFlowId;
	CheckStatus ChooseStatus;//该工作是否被领取的状态

};
struct ToCheckWorkFlow
{
	int ToCheckWorkFlowId;//需要确认的工作流的ID；
	int WorkCreatorId;//工作流创建者ID；
	int WorkNumber;//总工作数量
	int CheckedWorkNumber;//已经被人认领的工作数量
};



