#include <iostream>
#include <vector>
#include <windows.h>
#include "Expenses.h"
#include <algorithm>


using namespace std;

Expenses::Expenses(int userID){
    loggedInUsersId = userID;
    expensesFile.loadExpensesFromAFileForTheLoggedinUser(expenses, loggedInUsersId);
}

Expenses::~Expenses(){
    expenses.clear();
};

int Expenses::specifyID (){
    int id = 0;

    if (expenses.empty()==true){
        id = 1;
    }
    else{
        id = expenses.back().Expense::getExpenseID() + 1;
    }
    return id;
}

void Expenses::addExpense(){
    Expense expense;
    ExpensesFile expensesFile;
    system("cls");

    expensesFile.loadAllExpensesFromFile(expenses);
    expense.setExpenseID(Expenses::specifyID());
    expense.setUserID(loggedInUsersId);
    expense.enterDate();
    expense.enterItem();
    expense.enterAmount();

    expenses.push_back(expense);

    cout << "Zapisano wydatek nr: "<<expense.getExpenseID()<<"."<<endl;
    system ("pause");

    expensesFile.addExpenseToFile(expense);
    expensesFile.loadExpensesFromAFileForTheLoggedinUser(expenses, loggedInUsersId);
}

vector<Expense> Expenses::getExpensesFromSelectedPeriod(int startDate, int endDate)
{
    vector<Expense> selectedExpenses;

    if (!expenses.empty())
    {
        for (vector<Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            if (itr->Expense::getDate() >= startDate && itr->Expense::getDate() <= endDate)
            {
                selectedExpenses.push_back(*itr);
            }
        }
    }

    return selectedExpenses;
}

void Expenses::sortExpensesByDateInAscendingOrder(vector<Expense> &selectedExpenses)
{
   /* sort(selectedExpenses.begin(), selectedExpenses.end(), [](Expense& firstExpense, Expense& secondExpense)
    {
       return firstExpense.getDate() < secondExpense.getDate();
    });*/
}

void Expenses::showSelectedExpenses(vector<Expense> &selectedExpenses)
{
    if (!selectedExpenses.empty())
    {
        sortExpensesByDateInAscendingOrder(selectedExpenses);

        for (vector<Expense>::iterator itr = selectedExpenses.begin(); itr != selectedExpenses.end(); itr++)
        {
            cout << "Data:       " << date.convertDateFromIntToStringWithDash(itr->Expense::getDate()) << endl;
            cout << "Element:    " << itr->Expense::getItem() << endl;
            cout << "Wartosc:    " << itr->Expense::getAmount() << endl << endl;
        }
    }
    else
        cout << endl << "Nie posiadasz wydatkow z podanego okresu." << endl << endl;
}

float Expenses::getExpensesSum(vector<Expense> &selectedExpenses)
{
    float sum = 0.0f;

    for (vector<Expense>::iterator itr = selectedExpenses.begin(); itr != selectedExpenses.end(); itr++)
    {
        sum += itr->Expense::getAmount();
    }

    return sum;
}
