#include <iostream>
#include "UsersFile.h"
#include "Markup.h"

using namespace std;

UsersFile::UsersFile(){
    fileName = "Users.xml";
}

UsersFile::~UsersFile(){};

void UsersFile::loadAllUsersFromFile (vector <User> &users){
    User user;
    TypeConversion typeConversion;
    CMarkup xml;
    bool bSuccess = xml.Load(fileName);

            xml.FindElem("Users");
            xml.IntoElem();
            while ( xml.FindElem("User")){
                xml.IntoElem();
                xml.FindElem( "userID" );
                user.setUserID(typeConversion.convertStringToInt(xml.GetData()));
                xml.FindElem( "login" );
                user.setLogin(xml.GetData());
                xml.FindElem( "password" );
                user.setPassword(xml.GetData());
                xml.FindElem( "name" );
                user.setName(xml.GetData());
                xml.FindElem( "surname" );
                user.setSurname(xml.GetData());
                xml.OutOfElem();
                users.push_back(user);
            }
}

void UsersFile::addUserToFile (User user){
    CMarkup xml;
    bool bSuccess = xml.Load(fileName);
    if (bSuccess == true){
        xml.FindElem("Users");
    }else if (bSuccess == false){
        xml.AddElem( "Users" );
    }
        xml.IntoElem();

            xml.AddElem( "User" );
            xml.IntoElem();
            xml.AddElem( "userID", user.getUserID());
            xml.AddElem( "login", user.getLogin());
            xml.AddElem( "password", user.getPassword());
            xml.AddElem( "name", user.getName());
            xml.AddElem( "surname", user.getSurname());
            xml.OutOfElem();
            xml.Save( fileName );
}

void UsersFile::changeTheUserInTheFile(vector <User> &users){
    CMarkup xml;
        xml.AddElem( "Users" );
        xml.IntoElem();

        for (vector <User>::iterator  itr = users.begin(); itr != users.end(); itr++){
            xml.AddElem( "User" );
            xml.IntoElem();
            xml.AddElem( "userID", itr -> User::getUserID());
            xml.AddElem( "login", itr -> User::getLogin());
            xml.AddElem( "password", itr -> User::getPassword());
            xml.AddElem( "name", itr -> User::getName());
            xml.AddElem( "surname", itr -> User::getSurname());
            xml.OutOfElem();
            xml.Save(fileName);
        }
}
