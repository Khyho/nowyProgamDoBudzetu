#include <iostream>
#include <windows.h>
#include "Expense.h"

using namespace std;

Expense::Expense(){
    expenseID = 0;
    userID = 0;
    date = 19000101;
    item = "";
    amount = 0.0;
}

Expense::~Expense(){};

int Expense::getExpenseID(){
    return expenseID;
}

int Expense::getUserID(){
    return userID;
}

int Expense::getDate(){
    return date;
}

string Expense::getItem(){
    return item;
}

float Expense::getAmount(){
    return amount;
}

void Expense::setExpenseID (int expenseID){
    this->expenseID = expenseID;
}

void Expense::setUserID (int userID){
    this->userID = userID;
}

void Expense::setDate(int date){
    this->date = date;
}

void Expense::setItem (string item){
    this->item = item;
}
void Expense::setAmount (float amount){
    this->amount = amount;
}

void Expense::enterDate(){

    char choice;
    Date date;

    do{
        cout<<"Podaj date wydatku: "<<endl;
        cout<<"1. Dzisiejsza."<<endl;
        cout<<"2. Inna data."<<endl;
        cin >>choice;

        if (choice == '1'){
            this ->date = date.downloadTodaysDate();
        } else if (choice == '2'){
            this ->date = date.enterAnyDate();
        }
    system ("cls");
    cin.sync();
    }while (choice!='1' && choice!='2');
}

void Expense::enterItem(){
    cout << "Podaj czego dotyczy wydatek: "<<endl;
    getline(cin, this->item);
}

void Expense::enterAmount(){
    Amount amount;
    string am;
    int i=0;
    while (i<1){
        am = "";
        cout << "Podaj wartosc wydatku: "<<endl;
        cin >> am;
        if (amount.checkTheAmount(am)==true){
            this->amount = amount.setTheDot(am);
            i++;
        }else if (amount.checkTheAmount(am)==false){
            system ("cls");
            cout<< "Blednie podana wartosc wydatku."<<endl;
        }
    }
}


