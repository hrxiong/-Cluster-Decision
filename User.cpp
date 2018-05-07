//
//  User.cpp
//  腾飞科创Model
//
//  Created by leavesyoung on 2018/5/2.
//  Copyright © 2018年 leavesyoung. All rights reserved.
//

#include "User.h"

User::User(int UserID,int UserType){
    this->UserID=UserID;
    this->UserType=UserType;
}

User::User()
{
	this->UserID = 0;
	this->UserType = 0;
}

User::User(const User& u)
{
	this->UserID = u.UserID;
	this->UserType = u.UserType;
}
User::~User(){}



int User::getUserID(){
    return UserID;
}

int User::getUserType(){
    return UserType;
}

void User::operator =(User u){
    this->username=u.username;
    this->password=u.password;
    this->UserID=u.UserID;
    this->UserType=u.UserType;
}
