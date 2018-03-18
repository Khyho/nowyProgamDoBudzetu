#include <iostream>
#include <vector>
#include <windows.h>
#include "Incomes.h"
#include <algorithm>


using namespace std;

Incomes::Incomes(int userID){
    loggedInUsersId = userID;
    incomesFile.loadIncomesFromAFileForTheLoggedinUser(incomes, loggedInUsersId);
}

Incomes::~Incomes(){
    incomes.clear();
};

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

vector<Income> Incomes::getIncomesFromSelectedPeriod(int startDate, int endDate)
{
    vector<Income> selectedIncomes;

    if (!incomes.empty())
    {
        for (vector<Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if (itr->Income::getDate() >= startDate && itr->Income::getDate() <= endDate)
            {
                selectedIncomes.push_back(*itr);
            }
        }
    }

    return selectedIncomes;
}

void Incomes::sortIncomesByDateInAscendingOrder(vector<Income> &selectedIncomes)
{
   /* sort(selectedIncomes.begin(), selectedIncomes.end(), [](Income& firstIncome, Income& secondIncome)
    {
       return firstIncome.getDate() < secondIncome.getDate();
    });*/
}

void Incomes::showSelectedIncomes(vector<Income> &selectedIncomes)
{
    if (!selectedIncomes.empty())
    {
        sortIncomesByDateInAscendingOrder(selectedIncomes);

        for (vector<Income>::iterator itr = selectedIncomes.begin(); itr != selectedIncomes.end(); itr++)
        {
            cout << "Data:       " << date.convertDateFromIntToStringWithDash(itr->Income::getDate()) << endl;
            cout << "Element:    " << itr->Income::getItem() << endl;
            cout << "Wartosc:    " << itr->Income::getAmount() << endl << endl;
        }
    }
    else
        cout << endl << "Nie posiadasz przychodow z podanego okresu." << endl << endl;
}

float Incomes::getIncomesSum(vector<Income> &selectedIncomes)
{
    float sum = 0.0f;

    for (vector<Income>::iterator itr = selectedIncomes.begin(); itr != selectedIncomes.end(); itr++)
    {
        sum += itr->Income::getAmount();
    }

    return sum;
}
