#include <iostream>
#include <vector>
#include <windows.h>
#include "HomeBudget.h"
#include <algorithm>


using namespace std;

void HomeBudget::showTheBalance (int loggedInUsersID){
    Incomes incomes (loggedInUsersID);
    Date date;
    SYSTEMTIME st;
    int setMonth = 0;
    int setYear = 0;
    string earlierDateString = "";
    string laterDateString = "";
    int earlierDate = 0;
    int laterDate = 0;
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
                    setMonth = st.wMonth;
                    setYear = st.wYear;
                    showTheIncomes(incomes.getIncomes(), setMonth, setYear);
                break;
                case '2':
                    GetLocalTime(&st);
                    if (st.wMonth>=2){
                        setMonth = st.wMonth-1;
                        setYear = st.wYear;
                    }else if (st.wMonth==1){
                        setMonth = 12;
                        setYear = st.wYear-1;
                    }
                    showTheIncomes(incomes.getIncomes(), setMonth, setYear);
                break;
                case '3':
                    cout<<"Podaj date od ktorej maja byc wyswietlone przychody (w formacie RRRR-MM-DD): ";
                    cin>>earlierDateString;
                    while (i <1){
                        if(date.checkTheCorrectnessOfTheDate(earlierDateString)==true && earlierDateString.length()==10){
                            earlierDate = date.changeStringDateToInt(earlierDateString);
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
                            laterDate = date.changeStringDateToInt(laterDateString);
                            i++;
                        }else {
                            cout << "Blednie wprowadzona data. Wprowadz ponownie w formacie RRRR-MM-DD: ";
                            laterDateString = "";
                            cin>>laterDateString;
                            i=0;}
                    }
                    cout<<endl;
                    showTheIncomesBalanceFromTheSelectedPeriod (incomes.getIncomes(), earlierDate, laterDate);
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

void HomeBudget::showTheIncomes (vector <Income> incomes, int month, int year){
    Income income;
    Date date;
    system("cls");
    cin.sync();
    int yearIncome = 0;
    int monthIncome = 0;

    float sumOfAmount = 0;

    //sorting(incomes);

    if (!incomes.empty())
    {   cout<<endl;
        cout<<"---PRZYCHODY---"<<endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {   date.setMonthAndYear(itr -> Income::getDate(), yearIncome, monthIncome);
            if (month == monthIncome && year == yearIncome){
                cout << "IncomeID:      " << itr -> Income::getIncomeID() << endl;
                cout << "Data:          " << date.convertDateFromIntToStringWithDash(itr -> Income::getDate()) << endl;
                cout << "Item:          " << itr -> Income::getItem() << endl;
                cout << "amount:        " << itr -> Income::getAmount() << endl;
                cout << "---------------" <<endl;
                sumOfAmount +=itr -> Income::getAmount();
            }
        }
        cout << endl;
        cout << "Suma przychodow: "<<sumOfAmount;
        cout << endl;

    }
    else
    {
        cout << "Brak przychodow." << endl << endl;
    }

system("pause");
}

void HomeBudget::showTheIncomesBalanceFromTheSelectedPeriod (vector <Income> incomes, int earlierDate, int laterDate){
    Date date;
    cin.sync();
    float sumOfAmount = 0;

   // sorting(incomes);

    if (!incomes.empty() && earlierDate<laterDate){
        cout<<endl;
        cout<<"---PRZYCHODY---"<<endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++){
            if (itr -> Income::getDate()>=earlierDate && itr -> Income::getDate() <= laterDate){
                cout << "IncomeID:      " << itr -> Income::getIncomeID() << endl;
                cout << "Data:          " << date.convertDateFromIntToStringWithDash(itr -> Income::getDate()) << endl;
                cout << "Item:          " << itr -> Income::getItem() << endl;
                cout << "amount:        " << itr -> Income::getAmount() << endl;
                cout << "---------------" <<endl;
                sumOfAmount +=itr -> Income::getAmount();
            }
        }
        cout << endl;
        cout << "Suma Przychodow: "<<sumOfAmount;
        cout << endl;
    }else
    {
        cout << "Brak przychodow." << endl << endl;
    }
    system("pause");
}
/*
void HomeBudget::sorting(vector <Income> &incomes){
    sort(incomes.begin(), incomes.end(), [](Income& left, Income& right){
         return left.getDate() < right.getDate();
        });
}*/

