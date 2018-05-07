//
//  User.h
//  腾飞科创Model
//
//  Created by leavesyoung on 2018/5/2.
//  Copyright © 2018年 leavesyoung. All rights reserved.
//

#ifndef User_h
#define User_h
#include <string>
using namespace std;

class User{
	friend class Database;
	friend class Controller;
    public:
    User(int UserID,int UserType);
	User();
	User(const User& u);

    ~User();
    
    //setter and getter
    int getUserID();
    int getUserType();
    
    void operator =(User u);
    
private:

    string username;
    string password;

    int UserID;

    //1:creator 2:worker
    int UserType;
    //personal information,deal with it later:
    //to do
	//friend void User::operator =(User u);
	

};

#endif /* User_h */
