#include <iostream>
#include "TypeConversion.h"

using namespace std;

class Date{

    bool checkYear (int year);
    bool checkMonth (int month);
    bool leapYear (int year);
    bool checkDay (int day, int month, int year);
    void divideTheDateIntoYearMonthDay (string date, int &year, int &month, int &day);
public:
    bool checkTheCorrectnessOfTheDate (string date);
    int downloadTodaysDate();
    int enterAnyDate();
    string convertDateFromIntToStringWithDash (int date);
    int changeStringDateToInt(string date);
    void setMonthAndYear (int date, int &year, int &month);

};
