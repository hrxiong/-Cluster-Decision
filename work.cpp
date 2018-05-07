//
//  work.cpp
//  腾飞科创Model
//
//  Created by leavesyoung on 2018/5/2.
//  Copyright © 2018年 leavesyoung. All rights reserved.
//

#include "work.h"
#include <cstdio>
using namespace std;

work::work(int WorkID,int TypeID,int WorkFlowID){
    this->WorkID=WorkID;
    this->TypeID=TypeID;
    this->WorkFlowID=WorkFlowID;
    this->PreWorkID=-1;
    this->NextWorkID=-1;
    this->WorkerID=-1;
    this->Status=Waiting;
}

work::~work(){}

int work::GetWorkID(){
    return WorkID;
}

int work::GetTypeID(){
    return TypeID;
}

int work::GetWorkFlowID(){
    return WorkFlowID;
}

int work::GetPreWorkID(){
    return PreWorkID;
}

int work::GetNextWorkID(){
    return NextWorkID;
}

void work::SetPreWorkID(int ID){
    this->PreWorkID=ID;
}

void work::SetNextWorkID(int ID){
    this->NextWorkID=ID;
}

bool work::IsTaken(){
    return WorkerID!=-1;
}

void work::SetWorkerID(int ID){
    this->WorkerID=ID;
}

void work::SetStatus(WorkingStatus status){
    this->Status=status;
}

int work::GetWorkerID(){
    return WorkerID;
}

WorkingStatus work::getStatus(){
    return Status;
}
