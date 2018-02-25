#include <iostream>
#include <vector>
#include "UsersFile.h"

using namespace std;

class Users {

private:
    vector <User> users;
    int loggedInUsersId;
    UsersFile usersFile;
    User enterUserData();

public:
    Users ();
    virtual ~Users ();

    void registration ();
    int signIn ();
    void changeUsersPassword (int loggedInUsersId);
    int logOut ();
};
