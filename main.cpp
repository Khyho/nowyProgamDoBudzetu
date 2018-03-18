#include <iostream>
#include <vector>
#include <windows.h>
#include "Users.h"
#include "HomeBudget.h"

using namespace std;

int main(){
    Users users;
    char choice='0';

    while (true){
        if (users.getLoggedInUsersID()==0){
            system ("cls");
            cout << "Witaj w programie do organizacji domowego budzetu. Co chcesz zrobic?"<<endl;
            cout << "1. Logowanie"<<endl;
            cout << "2. Rejestracja"<<endl;
            cout << "9. Wyjscie"<<endl;
            cin>>choice;

            switch (choice){
            case '1':
                users.signIn();
                break;
            case '2':
                users.registration();
                break;
            case '9':
                cout << "Dziekuje za skorzystanie z programu. Do zobaczenia."<<endl;
                Sleep(2500);
                exit(0);
                break;
            default:
                cout << "Podano zly numer, wybierz ponownie."<<endl;
                Sleep(2500);
                break;
            }
        }else if (users.getLoggedInUsersID()!=0){
            system ("cls");
            cout << "1. Dodaj Przychod."<<endl;
            cout << "2. Dodaj Wydatek."<<endl;
            cout << "3. Bilanse."<<endl;
            cout << "8. Zmiana hasla."<<endl;
            cout << "9. Wylogowanie."<<endl;
            cin>>choice;
            HomeBudget homeBudget(users.getLoggedInUsersID());
            switch (choice){
                case '1':
                    homeBudget.addIncome();
                    break;
                case '2':
                    homeBudget.addExpense();
                    break;
                case '3':
                    homeBudget.TheBalance();
                    break;
                case '8':
                    users.changeUsersPassword();
                    break;
                case '9':
                    users.logOut();
                    break;
                default:
                    cout << "Podano zly numer, wybierz ponownie."<<endl;
                    Sleep(2500);
                    break;
            }
        }
    }
    return 0;
}
