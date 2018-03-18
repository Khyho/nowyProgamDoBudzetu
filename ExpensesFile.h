#include <iostream>
#include <vector>
#include "Expense.h"
#include "TypeConversion.h"

using namespace std;

class ExpensesFile{

private:
    string fileName;
    TypeConversion typeConversion;

public:
    ExpensesFile();
    virtual ~ExpensesFile();
    void loadAllExpensesFromFile (vector <Expense> &expenses);
    void loadExpensesFromAFileForTheLoggedinUser (vector <Expense> &expenses, int loggedInUsersId);
    void addExpenseToFile (Expense expense);
};

