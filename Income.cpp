#include <iostream>
#include <windows.h>
#include "Income.h"

using namespace std;

Income::Income(){
    incomeID = 0;
    userID = 0;
    date = 19000101;
    item = "";
    amount = 0.0;
}

Income::~Income(){};

int Income::getIncomeID(){
    return incomeID;
}

int Income::getUserID(){
    return userID;
}

int Income::getDate(){
    return date;
}

string Income::getItem(){
    return item;
}

float Income::getAmount(){
    return amount;
}

void Income::setIncomeID (int incID){
    incomeID = incID;
}

void Income::setUserID (int usID){
    userID = usID;
}

void Income::setDate(int d){
    date = d;
}

void Income::setItem (string ite){
    item = ite;
}
void Income::setAmount (float am){
    amount = am;
}

void Income::enterDate(){

    char choice;
    Date date;

    do{
        cout<<"Podaj date przychodu: "<<endl;
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

void Income::enterItem(){
    cout << "Podaj czego dotyczy przychod: "<<endl;
    getline(cin, this->item);
}

void Income::enterAmount(){
    string am;
    cout << "Podaj wartosc przychodu: "<<endl;
    cin >> am;
    this->amount = setTheDot(am);
}

float Income::setTheDot (string amount){

int i = 0;
    while (i<amount.length()){
       if (amount [i] != 46 && amount [i] !=44){
        i++;
       }else if (amount [i]==46){
        i++;
       }else if (amount [i]==44){
        amount [i] = '.';
        i++;
       }
    }
return atof(amount.c_str());
}
