//
//  WorkTable.h
//  腾飞科创Model
//
//  Created by leavesyoung on 2018/5/2.
//  Copyright © 2018年 leavesyoung. All rights reserved.
//

#ifndef WorkTable_h
#define WorkTable_h
#include <map>
#include "work.h"
using namespace std;

class WorkTable{
    public:
    WorkTable():table(){}
    ~WorkTable(){}
    
    map<int,work>* getTable(){
        return &table;
    }
    
    void setTable(work* w){
        table[w->GetWorkID()]=*w;
    }
    
    void clear(){
        table.clear();
    }
    
    private:
    map<int,work> table;
};

#endif /* WorkTable_h */
