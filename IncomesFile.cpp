#include <iostream>
#include <vector>
#include <windows.h>
#include "IncomesFile.h"
#include "Markup.h"


using namespace std;

IncomesFile::IncomesFile(){
    fileName = "Incomes.xml";
}

IncomesFile::~IncomesFile(){};

void IncomesFile::loadAllIncomesFromFile (vector <Income> &incomes){
    incomes.clear();
    Income income;
    Date date;
    TypeConversion typeConversion;
    CMarkup xml;
    bool bSuccess = xml.Load(fileName);

            xml.FindElem("Incomes");
            xml.IntoElem();
            while ( xml.FindElem("Income")){
                xml.IntoElem();
                xml.FindElem( "incomeID" );
                    income.setIncomeID(typeConversion.convertStringToInt(xml.GetData()));
                xml.FindElem( "userID" );
                    income.setUserID(typeConversion.convertStringToInt(xml.GetData()));
                xml.FindElem( "date" );
                    income.setDate(date.convertStringDateToInt(xml.GetData()));
                xml.FindElem( "item" );
                    income.setItem(xml.GetData());
                xml.FindElem( "amount" );
                    income.setAmount(atof(MCD_2PCSZ(xml.GetData())));
                xml.OutOfElem();
                incomes.push_back(income);
            }
}

void IncomesFile::loadIncomesFromAFileForTheLoggedinUser (vector <Income> &incomes, int loggedInUsersId){
    incomes.clear();
    Income income;
    Date date;
    TypeConversion typeConversion;
    CMarkup xml;
    bool bSuccess = xml.Load(fileName);

            xml.FindElem("Incomes");
            xml.IntoElem();
            while ( xml.FindElem("Income")){
                xml.IntoElem();
                xml.FindElem( "incomeID" );
                    income.setIncomeID(typeConversion.convertStringToInt(xml.GetData()));
                xml.FindElem( "userID" );
                    income.setUserID(typeConversion.convertStringToInt(xml.GetData()));
                xml.FindElem( "date" );
                    income.setDate(date.convertStringDateToInt(xml.GetData()));
                xml.FindElem( "item" );
                    income.setItem(xml.GetData());
                xml.FindElem( "amount" );
                    income.setAmount(atof(MCD_2PCSZ(xml.GetData())));
                xml.OutOfElem();
                if (income.getUserID()==loggedInUsersId){
                    incomes.push_back(income);
                }
            }
}

void IncomesFile::addIncomeToFile (Income income){
    CMarkup xml;
    TypeConversion typeConversion;
    Date date;

    bool bSuccess = xml.Load(fileName);
    if (bSuccess == true){
        xml.FindElem("Incomes");
    }else if (bSuccess == false){
        xml.AddElem( "Incomes" );
    }
        xml.IntoElem();

            xml.AddElem( "Income" );
            xml.IntoElem();
            xml.AddElem( "incomeID", income.getIncomeID());
            xml.AddElem( "userID", income.getUserID());
            xml.AddElem( "date", date.convertDateFromIntToStringWithDash(income.getDate()));
            xml.AddElem( "item", income.getItem());
            xml.AddElem( "amount", typeConversion.convertFloat(income.getAmount()));
            xml.OutOfElem();
            xml.Save( fileName );
}
