#include <iostream>
#include <windows.h>
#include "User.h"

using namespace std;

User::User(){
    userID = 0;
    login = "";
    password = "";
    name = "";
    surname = "";
}

User::~User () {}

int User::getUserID(){
    return userID;
}
string User::getLogin(){
    return login;
}

string User::getPassword(){
    return password;
}

string User::getName(){
    return name;
}

string User::getSurname(){
    return surname;
}

void User::setUserID (int id){
    userID = id;
}

void User::setLogin (string log){
    login = log;
}

void User::setPassword (string pass){
    password = pass;
}

void User::setName (string n){
    name = n;
}

void User::setSurname (string s){
    surname = s;
}


