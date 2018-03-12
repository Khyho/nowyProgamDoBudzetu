#include <iostream>
#include "Date.h"
#include "Amount.h"

using namespace std;

class Income{

private:
    int incomeID;
    int userID;
    int date;
    string item;
    float amount;

    float setTheDot (string amount);

public:
    Income ();
    virtual ~Income();

    int getIncomeID();
    int getUserID();
    int getDate();
    string getItem ();
    float getAmount();

    void setIncomeID (int incID);
    void setUserID (int usID);
    void setDate(int d);
    void setItem (string ite);
    void setAmount (float am);

    void enterDate();
    void enterItem();
    void enterAmount();
};
