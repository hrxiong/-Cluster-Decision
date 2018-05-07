//
//  Creator.h
//  腾飞科创Model
//
//  Created by leavesyoung on 2018/5/2.
//  Copyright © 2018年 leavesyoung. All rights reserved.
//

#ifndef Creator_h
#define Creator_h
#include "User.h"
#include "workFlow.h"
#include <vector>


class Creator:public User{
    public:
    Creator(int UserID,int UserType);
    ~Creator();
    //vector<int> GetWorkFlowList();
    //void setWorkFlowList(int ID);
    
    private:
    //vector<int> workFlowList;
};

#endif /* Creator_h */
