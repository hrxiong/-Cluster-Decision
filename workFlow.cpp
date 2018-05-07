//
//  workFlow.cpp
//  腾飞科创Model
//
//  Created by leavesyoung on 2018/5/2.
//  Copyright © 2018年 leavesyoung. All rights reserved.
//

#include "workFlow.h"
#include <cstdio>

workFlow::workFlow(int WorkFlowID,int CreatorID):WorkNumber(0),remainWorkNumber(0){
    this->WorkFlowID=WorkFlowID;
    this->CreatorID=CreatorID;
    NotChosenWork.clear();
}

workFlow::~workFlow(){};

int workFlow::getWorkFlowID(){
    return WorkFlowID;
}

int workFlow::getCreatorID(){
    return CreatorID;
}

int workFlow::getWorkNumber(){
    return WorkNumber;
}

int workFlow::getRemainWorkNumber(){
    return remainWorkNumber;
}

void workFlow::setBeginWorkID(int ID){
    BeginWorkID=ID;
}

void workFlow::addNotChosenWork(int WorkID){
    NotChosenWork.insert(WorkID);
    WorkNumber++;
    remainWorkNumber++;
}
void workFlow::deleteNotChosenWork(int WorkID){
    NotChosenWork.erase(WorkID);
    remainWorkNumber--;
}
bool workFlow::isReady(){
    return NotChosenWork.empty();
}

int workFlow::getBeginWorkID(){
    return BeginWorkID;
}

set<int>* workFlow::getNotChosenWork(){
    return &NotChosenWork;
}
