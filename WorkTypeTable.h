//
//  WorkTypeTable.h
//  腾飞科创Model
//
//  Created by leavesyoung on 2018/5/2.
//  Copyright © 2018年 leavesyoung. All rights reserved.
//

#ifndef WorkTypeTable_h
#define WorkTypeTable_h
#include <string>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

struct WorkTypeTableAttributes {
    WorkTypeTableAttributes(){}
    ~WorkTypeTableAttributes(){}
    string tag;
    vector<int> WorkerList;
    
    void operator = (WorkTypeTableAttributes u){
        this->tag=u.tag;
        (this->WorkerList).clear();
        for(vector<int>::iterator it=u.WorkerList.begin();it!=u.WorkerList.end();it++) (this->WorkerList).push_back(*it);
    }
};

class WorkTypeTable{
    public:
    WorkTypeTable(){
        table.clear();
    }
    ~WorkTypeTable(){}
    
    map<int,WorkTypeTableAttributes>* getTable(){
        return &table;
    }
    //put work types into the table
    int setTable(int WorkTypeID,string tag){
        if(table.find(WorkTypeID)!=table.end()) return -1;
        //warning:work type already exists.Replace it?
        else{
            WorkTypeTableAttributes temp;
            temp.tag=tag;
            table[WorkTypeID]=temp;
        }
        return 0;
    }
    
    //default:table has all work types.
    int setTable(int WorkTypeID,int WorkerID){
        if(table.find(WorkTypeID)==table.end()) return -1;
        //error:no such work type
        else table[WorkTypeID].WorkerList.push_back(WorkerID);
        return 0;
    }
    
    void clear(){
        table.clear();
    }
    
    private:
    map<int,WorkTypeTableAttributes> table;
};

#endif /* WorkTypeTable_h */
