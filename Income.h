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

public:
    Income ();
    virtual ~Income();

    int getIncomeID();
    int getUserID();
    int getDate();
    string getItem ();
    float getAmount();

    void setIncomeID (int incomeID);
    void setUserID (int userID);
    void setDate(int date);
    void setItem (string item);
    void setAmount (float amount);

    void enterDate();
    void enterItem();
    void enterAmount();
};
