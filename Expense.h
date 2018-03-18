#include <iostream>
#include "Date.h"
#include "Amount.h"

using namespace std;

class Expense{

private:
    int expenseID;
    int userID;
    int date;
    string item;
    float amount;

public:
    Expense ();
    virtual ~Expense();

    int getExpenseID();
    int getUserID();
    int getDate();
    string getItem ();
    float getAmount();

    void setExpenseID (int expenseID);
    void setUserID (int userID);
    void setDate(int date);
    void setItem (string item);
    void setAmount (float amount);

    void enterDate();
    void enterItem();
    void enterAmount();
};
