#include <iostream>
#include <vector>
#include <windows.h>
#include "Users.h"

using namespace std;

int main()
{
    Users users;

    char choice='0';
    int userID=0;

    while (true){
            system ("cls");
            cout << "Witaj w programie do organizacji domowego budzetu. Co chcesz zrobic?"<<endl;
            cout << "1. Logowanie"<<endl;
            cout << "2. Rejestracja"<<endl;
            cout << "3. Zmiana hasla"<<endl;
            cout << "4. Wylogowanie"<<endl;
            cout << "9. Wyjscie"<<endl;
            cin>>choice;

            switch (choice){
            case '1':
                userID = users.signIn();
                break;
            case '2':
                users.registration();
                break;
            case '3':
                users.changeUsersPassword(userID);
                break;
            case '4':
                userID = users.logOut();
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
    }
    return 0;
}
