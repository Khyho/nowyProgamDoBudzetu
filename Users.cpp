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

int Users::getLoggedInUsersID(){
    return loggedInUsersId;
}
void Users::setLoggedInUsersID (int userID){
    loggedInUsersId = userID;
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

void Users::signIn (){
    string login = "", password = "";
    int attempts = 3;

    vector <User>::iterator itr = users.begin();
    for (; attempts > 0; attempts--){
            cout << "LOGOWANIE."<<endl;
            cout <<  "Podaj login: "<<endl;
            cin >> login;

            cout << "Podaj haslo: "<<endl;
            cin >> password;

            for (;itr != users.end();itr++){
                if (itr -> User::getLogin() == login && itr -> User::getPassword() == password){
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    setLoggedInUsersID(itr -> User::getUserID());
                    attempts = 0;
                }
            }
            if (getLoggedInUsersID()==0){
                cout << "Blednie podany login i/lub haslo."<<endl;
                cout <<"Pozostalo: "<<attempts-1<<" proby."<<endl;
                system("pause");
                itr = users.begin();
                system("cls");
            }
    }if (attempts ==0&&getLoggedInUsersID()==0){
    cout << "Wprowadzono 3 razy bledne login i/lub haslo. Powrot do menu glownego." << endl;
    system("pause");
    }
}

void Users::changeUsersPassword (){
    string newPassword;
    if (getLoggedInUsersID()!=0){
        cout << "Wprowadz nowe haslo: ";
        cin >> newPassword;
        vector <User>::iterator itr = users.begin()+getLoggedInUsersID()-1;
        itr -> User::setPassword(newPassword);

        usersFile.changeTheUserInTheFile(users);
    }else{
    cout <<"Bledny uzytkownik. By zmienic haslo musisz byc zalogowany!"<<endl;
    }
}

void Users::logOut(){
    setLoggedInUsersID(0);
    system("cls");
    cout << "Wylogowano."<<endl;
    system("pause");
}
