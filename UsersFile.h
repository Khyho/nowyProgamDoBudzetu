#include <iostream>
#include <vector>
#include "User.h"
#include "TypeConversion.h"

using namespace std;

class UsersFile{

private:
    string fileName;
    TypeConversion typeConversion;

public:
    UsersFile();
    virtual ~UsersFile();
    void loadAllUsersFromFile (vector <User> &users);
    void addUserToFile (User user);
    void changeTheUserInTheFile(vector <User> &users);
};
