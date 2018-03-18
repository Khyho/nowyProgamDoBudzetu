#include <iostream>
#include <vector>
#include <windows.h>
#include "ExpensesFile.h"
#include "Markup.h"


using namespace std;

ExpensesFile::ExpensesFile(){
    fileName = "Expenses.xml";
}

ExpensesFile::~ExpensesFile(){};

void ExpensesFile::loadAllExpensesFromFile (vector <Expense> &expenses){
    expenses.clear();
    Expense expense;
    Date date;
    TypeConversion typeConversion;
    CMarkup xml;
    bool bSuccess = xml.Load(fileName);

            xml.FindElem("Expenses");
            xml.IntoElem();
            while ( xml.FindElem("Expense")){
                xml.IntoElem();
                xml.FindElem( "expenseID" );
                    expense.setExpenseID(typeConversion.convertStringToInt(xml.GetData()));
                xml.FindElem( "userID" );
                    expense.setUserID(typeConversion.convertStringToInt(xml.GetData()));
                xml.FindElem( "date" );
                    expense.setDate(date.convertStringDateToInt(xml.GetData()));
                xml.FindElem( "item" );
                    expense.setItem(xml.GetData());
                xml.FindElem( "amount" );
                    expense.setAmount(atof(MCD_2PCSZ(xml.GetData())));
                xml.OutOfElem();
                expenses.push_back(expense);
            }
}

void ExpensesFile::loadExpensesFromAFileForTheLoggedinUser (vector <Expense> &expenses, int loggedInUsersId){
    expenses.clear();
    Expense expense;
    Date date;
    TypeConversion typeConversion;
    CMarkup xml;
    bool bSuccess = xml.Load(fileName);

            xml.FindElem("Expenses");
            xml.IntoElem();
            while ( xml.FindElem("Expense")){
                xml.IntoElem();
                xml.FindElem( "expenseID" );
                    expense.setExpenseID(typeConversion.convertStringToInt(xml.GetData()));
                xml.FindElem( "userID" );
                    expense.setUserID(typeConversion.convertStringToInt(xml.GetData()));
                xml.FindElem( "date" );
                    expense.setDate(date.convertStringDateToInt(xml.GetData()));
                xml.FindElem( "item" );
                    expense.setItem(xml.GetData());
                xml.FindElem( "amount" );
                    expense.setAmount(atof(MCD_2PCSZ(xml.GetData())));
                xml.OutOfElem();
                if (expense.getUserID()==loggedInUsersId){
                    expenses.push_back(expense);
                }
            }
}

void ExpensesFile::addExpenseToFile (Expense expense){
    CMarkup xml;
    TypeConversion typeConversion;
    Date date;

    bool bSuccess = xml.Load(fileName);
    if (bSuccess == true){
        xml.FindElem("Expenses");
    }else if (bSuccess == false){
        xml.AddElem( "Expenses" );
    }
        xml.IntoElem();

            xml.AddElem( "Expense" );
            xml.IntoElem();
            xml.AddElem( "expenseID", expense.getExpenseID());
            xml.AddElem( "userID", expense.getUserID());
            xml.AddElem( "date", date.convertDateFromIntToStringWithDash(expense.getDate()));
            xml.AddElem( "item", expense.getItem());
            xml.AddElem( "amount", typeConversion.convertFloat(expense.getAmount()));
            xml.OutOfElem();
            xml.Save( fileName );
}
