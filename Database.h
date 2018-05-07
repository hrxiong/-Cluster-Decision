//
//  Database.h
//  腾飞科创Model
//
//  Created by leavesyoung on 2018/5/2.
//  Copyright © 2018年 leavesyoung. All rights reserved.
//

#ifndef Database_h
#define Database_h
#include "UserTable.h"
#include "WorkTypeTable.h"
#include "WorkTable.h"
#include "Creator.h"
#include "Worker.h"
#include "WorkFlowTable.h"
#include"MD5.h"
#include <vector>

class Database{
    public:
    Database();
    ~Database();
    
    int searchUserName(string name);//search if the user exists,and return its type
    bool searchUserInfo(string name,string password);//if the username matches the password
    int RegistCreator(string name,string password);//create a creator
    int RegistWorker(string name,string password);//create a worker
	User* getUserPoint(string username, string password);//return user* pointer according to name and password
    vector<int> GetWorkTypeList();
    void CreateWorkFlow(vector<int> WorkTypeList,Creator* c);
    vector<int>* GetWorkFlowListByCreatorID(int CreatorId);//error when multithreading
    vector<int> GetToCheckListByWorkerID(int WorkerId);//error when multithreading
    set<int>* getNotReadyWorkFlow();
    UserTable* getUserTable();
    void setWorkTypeTable(int i);//only input id.
    WorkTypeTable* getWorkTypeTable();
	work* Database::getWorkPointByWorkID(int ID);//根据workID查找work
    WorkTable* getWorkTable();
    WorkFlowTable* getWorkFlowTable();
    void UpdateToCheckList(vector<int>& ChosenWorkList, int WorkerId);
    void CheckIsOk(int WorkId);
    void CheckIsNotOk(int WorkId);
    void HandIn(int WorkId);
    vector<int>* GetWorkListByWorkerID(int WorkerID);
	void Database::initialWorkTypeTable(vector<int> vec);
    /********************************************************************
     *bool JudgeWorkerOrCreator(user a) is no need since
     *the user::userType does its job.
     *int GetId(user a, bool UserType) is no need since
     *user::getUserID() does its job.
     *void RegistWorkerJobType(vector<int> &ChosenWorkTypeList, user a) is
     *no need since WorkTypeTable::setTable() does its job.
     *WorkingStatus GetStatusByWorkId(int WorkId) is no need.
     ********************************************************************/
    
    
    private:
    UserTable ut;
    WorkTypeTable wtt;
    WorkTable wt;
    WorkFlowTable wft;
    
    int UserID;
    int WorkFlowID;
    int WorkID;
    set<int> NotReadyWorkFlow;
    vector<int> List;//not safe!
};
#endif /* Database_h */
