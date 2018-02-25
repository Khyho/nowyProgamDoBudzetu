#include <iostream>

using namespace std;

class User{

private:
    int userID;
    string login;
    string password;
    string name;
    string surname;

public:
    User ();
    virtual ~User();

    int getUserID();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();

    void setUserID (int id);
    void setLogin (string login);
    void setPassword (string password);
    void setName (string name);
    void setSurname (string surname);
};
