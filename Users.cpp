#include <iostream>
#include <vector>
#include <windows.h>
#include "Users.h"


using namespace std;

Users::Users(){
    loggedInUsersId = 0;
    usersFile.loadAllUsersFromFile(users);
}

Users::~Users(){
    users.clear();
}

User Users::enterUserData(){
User user;
string login;
string password;
string name;
string surname;
int i=0;
    system ("cls");
    if (users.empty()==true){
        user.setUserID(1);
    }
    else{
        user.setUserID(users.back().getUserID() + 1);
    }

    cout << "Podaj Login: "<<endl;
    cin>> login;
    user.setLogin(login);

    cout <<"Podaj haslo: "<<endl;
    cin >> password;
    user.setPassword(password);

    while (i <users.size()){
        if (users[i].getLogin() == user.getLogin() && users[i].getPassword()==user.getPassword() ){
            system ("cls");
            cout << "Taki uzytkownik juz istnieje. Wprowadz ponownie."<<endl;
            cout << "Podaj Login: "<<endl;
            cin>> login;
            user.setLogin(login);

            cout <<"Podaj haslo: "<<endl;
            cin >> password;
            user.setPassword(password);
            i=0;
        }else{
            i++;
        }
    }
    cout << "Podaj imie: "<<endl;
    cin >> name;
    user.setName(name);

    cout <<"Podaj nazwisko: "<<endl;
    cin >> surname;
    user.setSurname(surname);

    return user;
}

void Users::registration(){
    User user = enterUserData();
	users.push_back(user);
    usersFile.addUserToFile(user);

	cout << endl << "Konto zostalo utoworzone. Teraz mozesz sie zalogowac :)" << endl << endl;

	system("pause");
}

int Users::signIn (){
    User user;
    string login = "", password = "";

    vector <User>::iterator itr = users.begin();
    for (int attempts = 3; attempts > 0; attempts--){
            cout << "LOGOWANIE."<<endl;
            cout <<  "Podaj login: "<<endl;
            cin >> login;

            cout << "Podaj haslo: "<<endl;
            cin >> password;

            for (;itr != users.end();itr++){
                if (itr -> getLogin() == login && itr -> getPassword() == password){
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return itr -> getUserID();
                }
            }
                cout << "Blednie podany login i/lub haslo."<<endl;
                cout <<"Pozostalo: "<<attempts-1<<" proby."<<endl;
                system("pause");
                itr = users.begin();
                system("cls");
    }
    cout << "Wprowadzono 3 razy bledne login i/lub haslo. Powrot do menu glownego." << endl;
    system("pause");
    return 0;
}

void Users::changeUsersPassword (int userID){
    User user;
    string newPassword;
    cout << "Wprowadz nowe haslo: ";
    cin >> newPassword;
    vector <User>::iterator itr = users.begin()+userID-1;
    itr -> setPassword(newPassword);

    usersFile.changeTheUserInTheFile(users);
}

int Users::logOut(){
    int userID;
    return userID=0;
}
