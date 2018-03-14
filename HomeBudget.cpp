#include <iostream>
#include <vector>
#include <windows.h>
#include "HomeBudget.h"
#include <algorithm>


using namespace std;

HomeBudget::HomeBudget(int loggedInUsersID)
{
    try
    {
        if (loggedInUsersID <= 0)
        {
            throw 0;
        }
        else
        {
            this->userID = loggedInUsersID;
            incomes = new Incomes(userID);
        }
    }
    catch (int incorrectUserId)
    {
        cout << endl << "Blad! Nie jestes zalogowany!" << endl << endl;
        system("pause");
        exit(0);
    }
}

HomeBudget::~HomeBudget()
{
    delete incomes;
}

void HomeBudget::addIncome()
{
    incomes->addIncome();
}

void HomeBudget::TheBalance (){
    SYSTEMTIME st;
    int month = 0;
    int year = 0;
    string earlierDateString = "";
    string laterDateString = "";
    int startDate = 0;
    int endDate = 0;

    char choice = 0;
    int i=0;

    while (choice!='9'){
        system ("cls");
        cout << "---BILANSE---"<<endl;
        cout << "1. Wyswietl bilans z biezacego miesiaca."<<endl;
        cout << "2. Wyswietl bilans z zeszlego miesiaca."<<endl;
        cout << "3. Wyswietl bilans z wybranego okresu"<<endl;
        cout << "9. Wroc do wczesniejszego menu"<<endl;
        cin >> choice;
            switch (choice){
                case '1':
                    GetLocalTime(&st);
                    month = st.wMonth;
                    year = st.wYear;
                    startDate = date.getFirstDateInMonth(month, year);
                    endDate = date.getLastDateInMonth(month, year);
                    showBalance(startDate, endDate);
                break;
                case '2':
                    GetLocalTime(&st);
                    if (st.wMonth>=2){
                        month = st.wMonth-1;
                        year = st.wYear;
                    }else if (st.wMonth==1){
                        month = 12;
                        year = st.wYear-1;
                    }
                    startDate = date.getFirstDateInMonth(month, year);
                    endDate = date.getLastDateInMonth(month, year);
                    showBalance(startDate, endDate);
                break;
                case '3':
                    cout<<"Podaj date od ktorej maja byc wyswietlone przychody (w formacie RRRR-MM-DD): ";
                    cin>>earlierDateString;
                    while (i <1){
                        if(date.checkTheCorrectnessOfTheDate(earlierDateString)==true && earlierDateString.length()==10){
                            startDate = date.convertStringDateToInt(earlierDateString);
                            i++;
                        }else {
                            cout << "Blednie wprowadzona data. Wprowadz ponownie w formacie RRRR-MM-DD: ";
                            earlierDateString = "";
                            cin>>earlierDateString;
                            i=0;}
                    }
                    cout<<endl;
                    i=0;
                    cout<<"Podaj date do ktorej maja byc wyswietlone przychody (w formacie RRRR-MM-DD): ";
                    cin>>laterDateString;
                    while (i <1){
                        if(date.checkTheCorrectnessOfTheDate(laterDateString)==true && laterDateString.length()==10){
                            endDate = date.convertStringDateToInt(laterDateString);
                            i++;
                        }else {
                            cout << "Blednie wprowadzona data. Wprowadz ponownie w formacie RRRR-MM-DD: ";
                            laterDateString = "";
                            cin>>laterDateString;
                            i=0;}
                    }
                    cout<<endl;
                    showBalance (startDate, endDate);
                break;
                case '9':

                break;
                default:
                    cout << "Podano zly numer, wybierz ponownie: "<<endl;
                    system ("Pause");
                break;
                }
    }
}

void HomeBudget::showBalance(int startDate, int endDate)
{
    vector<Income> selectedIncomes;

    float difference = 0.0f;
    float incomesSum = 0.0f;


    selectedIncomes = incomes->getIncomesFromSelectedPeriod(startDate, endDate);


    incomesSum = incomes->getIncomesSum(selectedIncomes);

    cout << "               >>> PRZYCHODY <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    incomes->showSelectedIncomes(selectedIncomes);

    cout << "-----------------------------------------------" << endl;
    cout << "SUMA PRZYCHODOW: " << incomesSum << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;


    system("pause");
}
