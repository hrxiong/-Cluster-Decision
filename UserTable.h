//
//  UserTable.h
//  腾飞科创Model
//
//  Created by leavesyoung on 2018/5/2.
//  Copyright © 2018年 leavesyoung. All rights reserved.
//

#ifndef UserTable_h
#define UserTable_h
#include "User.h"

#include <cstdio>
#include <map>
#include <stdexcept>

struct UserTableAttributes {
    UserTableAttributes():user(0,0){}
    ~UserTableAttributes(){}
    string password;
    User user;
    void operator = (UserTableAttributes u){
        this->password=u.password;
        this->user=u.user;
    }
};

class UserTable{
    public:
    UserTable(){
        table.clear();
    }
    
    ~UserTable(){}
    
    //getter and setter
    map<string,UserTableAttributes>* getTable(){
        return &table;
    }
    
    User* getUser(int ID){
        for(map<string,UserTableAttributes>::iterator it=table.begin();it!=table.end();it++){
            if(it->second.user.getUserID()==ID) return &(it->second.user);
        }
        throw domain_error("no such user");
    }
    
    User* getUser(string username){
        if(table.find(username)==table.end()) return NULL;
        else return &(table[username].user);
    }
    
    int setTable(string username,string password,User user){
        UserTableAttributes temp;
        temp.password=password;
        temp.user=user;
        if(table.find(username)!=table.end()) return -1;
        //warning:the key already exists.Replace it?
        else table[username]=temp;
        return 0;
    }
    
    void clear(){
        table.clear();
    }
    
    private:
    map<string,UserTableAttributes> table;
};

#endif /* UserTable_h */
