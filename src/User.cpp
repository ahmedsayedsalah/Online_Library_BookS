#include "User.h"
/*------------------------*/
int User::count=0;//initialization
/*-----------------------------------*/
User::User()//default constructor
{
    name="";
    age=0;
    password="";
    email="";
    count++;
    id=count;
}
/*-----------------------------------*/
User::User(string name, int age, string password, string email)//parameter constructor
{
    this->name=name;
    this->age=age;
    this->password=password;
    this->email=email;
    count++;
    id=count;
}
/*-----------------------------------*/
//importance of copy constructor: make object have separate location in the memory to another object
User::User(const User& user)//copy constructor..&: to not create new object and reduce area of memory..const: (like: int x=5;) to not change object that call constructor
{
    name=user.name;
    age=user.age;
    password=user.password;
    email=user.email;
    id=user.id;
}
/*-----------------------------------*/
void User::setName(string name)
{
    this->name=name;
}
string User::getName() const
{
    return name;
}
void User::setPassword(string password)
{
    this->password=password;
}
string User::getPassword()const
{
    return password;
}
void User::setEmail(string email)
{
    this->email=email;
}
string User::getEmail()const
{
    return email;
}
void User::setAge(int age)
{
    this->age=age;
}
int User::getAge()const
{
    return age;
}
void User::setId(int id)
{
    this->id=id;
}
int User::getId()const
{
    return id;
}
/*-----------------------------------*/
bool User::operator==(const User&  user)//u1.operator==(u2)
{
    if(name==user.name&&age==user.age&&password==user.password&&id==user.id&&email==user.email)
        return true;
    return false;
}
/*-----------------------------------*/
void User::Display ()
{
    cout<<"===========>enter information of the User<===========\n";
    cout<<"\n-----------------------------------\n";
    cout<<"id: "<<id<<"\nname: "<<name<<"\nage: "<<age<<"\nemail: "<<email<<"\npassword: "<<password<<endl;
    cout<<"-----------------------------------\n";
}
/*-----------------------------------*/
ostream &operator<<(ostream &output, const User &user)
{
    output<<"============Book "<<user.id<<" info==========\n";
    output<<"Name: "<<user.name<<" | age: "<<user.age<<" | email: "<<user.email<<" | password: "<<user.password<<endl;
    cout<<"===============================================\n";
    return output;
}
istream &operator>>(istream &input, User &user)
{
    cout<<"===========>enter information of the User<===========\n";
    cout<<"enter=> [name] [age] [email] [password] ??\n";
    input>>user.name>>user.age>>user.email>>user.password;
    return input;
}
