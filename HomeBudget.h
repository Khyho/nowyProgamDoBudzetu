#include <iostream>
#include <vector>
#include "Incomes.h"
#include "Expenses.h"

using namespace std;

class HomeBudget {

    int userID;
    Date date;
    Incomes *incomes;
    Expenses *expenses;

    public:
    HomeBudget (int loggedInUsersID);
    virtual ~HomeBudget();
    void addIncome();
    void addExpense();
    void TheBalance ();
    void showBalance(int startDate, int endDate);
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromSelectedPeriod();
};
