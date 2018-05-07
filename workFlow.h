//
//  workFlow.h
//  腾飞科创Model
//
//  Created by leavesyoung on 2018/5/2.
//  Copyright © 2018年 leavesyoung. All rights reserved.
//

#ifndef workFlow_h
#define workFlow_h
#include <vector>
#include <set>
using namespace std;

class workFlow{
    public:
    workFlow(){}
    workFlow(int WorkFlowID,int CreatorID);
    ~workFlow();
    
    //setters and getters
    int getWorkFlowID();
    int getCreatorID();
    int getWorkNumber();
    int getRemainWorkNumber();
    void setBeginWorkID(int ID);
    void addNotChosenWork(int WorkID);
    void deleteNotChosenWork(int WorkID);
    int getBeginWorkID();
    set<int>* getNotChosenWork();
    bool isReady();
    
    void operator = (workFlow u){
        this->WorkFlowID=u.WorkFlowID;
        this->CreatorID=u.CreatorID;
        this->BeginWorkID=u.BeginWorkID;
        this->WorkNumber=u.WorkNumber;
        this->remainWorkNumber=u.remainWorkNumber;
        this->NotChosenWork=u.NotChosenWork;
    }
    
    private:
    set<int> NotChosenWork;
    int BeginWorkID;
    int WorkFlowID;
    int CreatorID;
    int WorkNumber;
    int remainWorkNumber;
};

#endif /* workFlow_h */
