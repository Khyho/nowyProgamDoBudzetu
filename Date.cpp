#include <iostream>
#include <windows.h>
#include "Date.h"

using namespace std;



int Date::downloadTodaysDate(){
    int date = 0;
    SYSTEMTIME st;
    GetLocalTime(&st);
    return date = st.wYear*10000+st.wMonth*100+st.wDay;
}

int Date::enterAnyDate(){
    string date;
    int i = 0;
    cout <<"Podaj date (w formacie RRRR-MM-DD): ";
    cin >> date;
        while (i < 1){
            if (checkTheCorrectnessOfTheDate(date)==true && date.length()==10){
                i++;
            }else {
            cout << "Blednie wprowadzona data. Wprowadz ponownie w formacie RRRR-MM-DD: ";
            date = "";
            cin >> date;
            i = 0;
            }
        }
return convertStringDateToInt(date);
}

int Date::convertStringDateToInt(string date){
    string auxiliaryWord ="";
    int year = 0;
    int month = 0;
    int day = 0;
    int counter = 0;

        for (int i = 0; i<=date.length();i++){
            if (date[i]!=45&&i!=10){
                auxiliaryWord+=date[i];
            } else {
                counter++;
                switch(counter){
                    case 1:
                        year = atoi(auxiliaryWord.c_str());
                        auxiliaryWord ="";
                        break;
                    case 2:
                        month = atoi(auxiliaryWord.c_str());
                        auxiliaryWord ="";
                        break;
                    case 3:
                        day = atoi(auxiliaryWord.c_str());
                        auxiliaryWord ="";
                        break;
                }
            }
        }
    return year*10000+month*100+day;
}

bool Date::checkTheCorrectnessOfTheDate (string date){
    int year = 0;
    int month = 0;
    int day = 0;
    string auxiliaryWord ="";
    int counter = 0;

        for (int i = 0; i<=date.length();i++){
            if (date[i]!=45&&i!=10){
                auxiliaryWord+=date[i];
            } else {
                counter++;
                switch(counter){
                    case 1:
                        year = atoi(auxiliaryWord.c_str());
                        auxiliaryWord ="";
                        break;
                    case 2:
                        month = atoi(auxiliaryWord.c_str());
                        auxiliaryWord ="";
                        break;
                    case 3:
                        day = atoi(auxiliaryWord.c_str());
                        auxiliaryWord ="";
                        break;
                }
            }
        }
    if (checkYear(year) == true && checkMonth (month) == true && checkDay (day, month, year) == true){
        return true;
    } else {
     return false;
    }
}

void Date::divideTheDateIntoYearMonthDay (string date, int &year, int &month, int &day){
    TypeConversion typeConversion;
    string auxiliaryWord ="";
        for (int i = 0; i <=7; i++){
                if (i==3){
                    auxiliaryWord+=date[i];
                    year = typeConversion.convertStringToInt(auxiliaryWord);
                    auxiliaryWord ="";
                }else if (i==5){
                    auxiliaryWord+=date[i];
                    month = typeConversion.convertStringToInt(auxiliaryWord);
                    auxiliaryWord ="";
                }else if (i==7){
                    auxiliaryWord+=date[i];
                    day = typeConversion.convertStringToInt(auxiliaryWord);
                } else {
                    auxiliaryWord+=date[i];
                }
            }
}

bool Date::checkYear (int year){
    if (year >=2000 && year <=2100){
        return true;
    }else{
    return false;
    }
}

bool Date::checkMonth (int month){
    if (month >=1 && month <=12){
        return true;
    }else {
    return false;
    }

}

bool Date::leapYear (int year){
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
        return true;
    } else {
    return false;
    }
}

bool Date::checkDay (int day, int month, int year){
    if (month == 2){
        if(leapYear(year) == true && day == 29){
            return true;
        }else if (leapYear(year)==false && day <=28){
            return true;}
        else {return false;}
    }else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if (day <=31){
            return true;
        }else {return false;}
    }else if (month == 4 || month == 6 || month == 9 || month == 11){
        if (day <=30){
            return true;
        }else {return false;}
    }else {return false;}
}

string Date::convertDateFromIntToStringWithDash(int d){
    TypeConversion typeConversion;
    string dateBeforeDivide = "";
    string dateAfterDivide = "";
    int year = 0;
    int month = 0;
    int day = 0;

    dateBeforeDivide = typeConversion.convertIntToString(d);
    divideTheDateIntoYearMonthDay(dateBeforeDivide, year, month, day);
    if (month <=9){
        if (day<=9){
        return dateAfterDivide = typeConversion.convertIntToString(year)+"-0"+typeConversion.convertIntToString(month)+"-0"+typeConversion.convertIntToString(day);
        }else if (day>9){
        return dateAfterDivide = typeConversion.convertIntToString(year)+"-0"+typeConversion.convertIntToString(month)+"-"+typeConversion.convertIntToString(day);
        }
    }else if (month >9){
        if (day<=9){
        return dateAfterDivide = typeConversion.convertIntToString(year)+"-"+typeConversion.convertIntToString(month)+"-0"+typeConversion.convertIntToString(day);
        }else if (day>9){
        return dateAfterDivide = typeConversion.convertIntToString(year)+"-"+typeConversion.convertIntToString(month)+"-"+typeConversion.convertIntToString(day);
        }
    }
}

int Date::getFirstDateInMonth (int month, int year){
    return year*10000+month*100+1;
}

int Date::getLastDateInMonth (int month, int year){
    if (month == 2){
        if(leapYear(year) == true){
            return year*10000+month*100+29;
        }else if (leapYear(year)==false){
            return year*10000+month*100+28;}
        else {return false;}
    }else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        return year*10000+month*100+31;
    }else if (month == 4 || month == 6 || month == 9 || month == 11){
        return year*10000+month*100+30;
    }
}
