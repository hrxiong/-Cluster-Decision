//
//  work.h
//  腾飞科创Model
//
//  Created by leavesyoung on 2018/5/2.
//  Copyright © 2018年 leavesyoung. All rights reserved.
//

#ifndef work_h
#define work_h

typedef enum WorkingStatus
{
    Waiting,//the work is being worked by the previous guy;
    NeedCheck,//the previous guy has handed in, you need to check his work
    UnderWorking,//you are working with it
    HandedIn,//you have done your work and handed in, waiting to be checked by the next guy;
    Checked,//your work is completed;
    NeedToRework//work failed.need to fix your work;
}WorkingStatus;

class work{
    public:
    work(){}
    work(int WorkID,int TypeID,int WorkFlowID);
    ~work();
    
    //setters and getters
    int GetWorkID();
    int GetTypeID();
    int GetWorkFlowID();
    int GetPreWorkID();
    int GetNextWorkID();
    int GetWorkerID();
    WorkingStatus getStatus();
    void SetPreWorkID(int ID);
    void SetNextWorkID(int ID);
    void SetWorkerID(int ID);
    void SetStatus(WorkingStatus status);
    bool IsTaken();
    
    void operator = (work u){
        this->WorkID=u.WorkID;
        this->TypeID=u.TypeID;
        this->WorkFlowID=u.WorkFlowID;
        this->PreWorkID=u.PreWorkID;
        this->NextWorkID=u.NextWorkID;
        this->Status=u.Status;
        this->WorkerID=u.WorkerID;
    }
    
    bool operator < (work w){
        return this->WorkID<w.GetWorkID();
    }
    
    private:
    int WorkID; //the id of the work in the workflow
    int TypeID; //the id of the work type
    int WorkFlowID; //the id of the workflow
    //default:chain work flow
    int PreWorkID; //the id of the former work,-1 if it's the first work
    int NextWorkID; //the id of the next work,-1 if it's the last work
    int WorkerID;//the id of the worker to deal with it.-1 if no worker
    WorkingStatus Status;
};

#endif /* work_h */
