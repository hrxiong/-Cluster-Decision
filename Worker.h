//
//  Worker.h
//  腾飞科创Model
//
//  Created by leavesyoung on 2018/5/2.
//  Copyright © 2018年 leavesyoung. All rights reserved.
//

#ifndef Worker_h
#define Worker_h
#include "User.h"
#include <vector>
using namespace std;

class Worker:public User{
    public:
    Worker(int UserID,int UserType);
    ~Worker();
    
    //void setWorkList(int WorkID);
    //vector<int> getWorkList();
    
    private:
    //vector<int> WorkList;
};

#endif /* Worker_h */
