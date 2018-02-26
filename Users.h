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

    int getLoggedInUsersID ();
    void setLoggedInUsersID (int userID);
    void registration ();
    void signIn ();
    void changeUsersPassword ();
    void logOut ();
};
