#ifndef USERLIST_H
#define USERLIST_H
#include "User.h"
#include <iostream>
using namespace std;//cin,cout,endl,string

class UserList
{
 private:
         User* users;
         int capacity;
         int usersCount;
 public:
         UserList();
         UserList(int );
         void addUser(User &);
         User* searchUser(string );
         User* searchUser(int );
         void deleteUser(int );
         friend ostream &operator<<( ostream& ,const UserList&);
         ~UserList();
};

#endif // USERLIST_H
