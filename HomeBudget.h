#include <iostream>
#include <vector>
#include "Incomes.h"

using namespace std;

class HomeBudget {

    int userID;
    Date date;
    Incomes *incomes;

    public:
    HomeBudget (int loggedInUsersID);
    virtual ~HomeBudget();
    void addIncome();
    void TheBalance ();
    void showBalance(int startDate, int endDate);
};
