#include <iostream>
#include <vector>
#include "ExpensesFile.h"
#include <algorithm>


using namespace std;

class Expenses {

private:
    vector <Expense> expenses;
    int loggedInUsersId;
    ExpensesFile expensesFile;
    Date date;
    int specifyID();

public:
    Expenses(int loggedInUsersId);
    virtual ~Expenses ();

    void addExpense();
    vector<Expense> getExpensesFromSelectedPeriod(int startDate, int endDate);
    void sortExpensesByDateInAscendingOrder(vector<Expense> &selectedExpenses);
    void showSelectedExpenses(vector<Expense> &selectedExpenses);
    float getExpensesSum(vector<Expense> &selectedExpenses);
};


