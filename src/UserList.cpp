#include "UserList.h"
/*------------Constructor---------------*/
UserList::UserList()
{
    capacity=0;
    usersCount=0;
}
UserList::UserList(int capacity)
{
    this->capacity=capacity;
    users=new User[capacity];//creation
    usersCount=0;
}
/*--------------Methods-------------------*/
void UserList::addUser(User &user)
{
    if(usersCount<capacity)
    {
        users[usersCount]=user;
        users[usersCount].setId(usersCount+1);
        usersCount++;
    }
    else
        cout<<"array is full\n";
}
User* UserList::searchUser(string name)
{
    for(int a=0;a<capacity;a++)
    {
        if(users[a].getName()==name)
            return &users[a];
    }
    return nullptr;
}
User* UserList::searchUser(int id)//binary_search(users,users+capacity,id)
{
    /*int low=0,high=usersCount-1;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(users[mid].getId()==id)
            return &users[mid];
        else if(users[mid].getId()>id)
            low=mid+1;
        else
            high=mid-1;
    }
    return nullptr;*/
    for(int a=0;a<capacity;a++)
    {
        if(users[a].getId()==id)
            return &users[a];
    }
    return nullptr;
}
void UserList::deleteUser(int id)
{
    bool x=true;
    for(int i=0;i<usersCount-1;i++)
    {
        if(users[i].getId()==id&&x)
        {
            x=false;
            i--;
            continue;
        }
        else if(!x)
        {
            users[i]=users[i+1];
            users[i].setId(i+1);
        }
    }
    usersCount--;
    capacity--;
}
ostream &operator<<( ostream& output,const UserList&userList)
{
    for(int i=0;i<userList.usersCount;i++)
    {
        output<<userList.users[i];
    }
}
UserList::~UserList()
{
    delete[]users;
}
