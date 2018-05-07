//
//  WorkFlowTable.h
//  腾飞科创Model
//
//  Created by leavesyoung on 2018/5/2.
//  Copyright © 2018年 leavesyoung. All rights reserved.
//

#ifndef WorkFlowTable_h
#define WorkFlowTable_h
#include <map>
#include "workFlow.h"
using namespace std;

class WorkFlowTable{
    public:
    WorkFlowTable(){}
    ~WorkFlowTable(){}
    
    map<int,workFlow>* getTable(){
        return &table;
    }
    
    void setTable(workFlow* w){
        /*printf("in setTable:\n%d %d %d %d %d\n",w->getWorkFlowID(),w->getBeginWorkID(),w->getWorkNumber(),w->getRemainWorkNumber(),w->getNotChosenWork()->size());*/
        table[w->getWorkFlowID()]=*w;
        /*printf("in setTable:\n%d %d %d %d %d\n",table[1].getWorkFlowID(),table[1].getBeginWorkID(),table[1].getWorkNumber(),table[1].getRemainWorkNumber(),table[1].getNotChosenWork()->size());*/
    }
    
    void clear(){
        table.clear();
    }
    
    private:
    map<int,workFlow> table;
};

#endif /* WorkFlowTable_h */
