#include <iostream>
#include <vector>
#include <windows.h>
#include "Incomes.h"


using namespace std;

Incomes::Incomes(int userID){
    loggedInUsersId = userID;
    incomesFile.loadIncomesFromAFileForTheLoggedinUser(incomes, loggedInUsersId);
}

Incomes::~Incomes(){};

vector <Income> Incomes::getIncomes (){
    return incomes;
}

int Incomes::specifyID (){
    int id = 0;

    if (incomes.empty()==true){
        id = 1;
    }
    else{
        id = incomes.back().Income::getIncomeID() + 1;
    }
    return id;
}

void Incomes::addIncome(){
    Income income;
    IncomesFile incomesFile;
    system("cls");

    incomesFile.loadAllIncomesFromFile(incomes);
    income.setIncomeID(Incomes::specifyID());
    income.setUserID(loggedInUsersId);
    income.enterDate();
    income.enterItem();
    income.enterAmount();

    incomes.push_back(income);

    cout << "Zapisano przychod nr: "<<income.getIncomeID()<<"."<<endl;
    system ("pause");

    incomesFile.addIncomeToFile(income);
    incomesFile.loadIncomesFromAFileForTheLoggedinUser(incomes, loggedInUsersId);
}

