#include <iostream>
#include <vector>
#include "Income.h"
#include "TypeConversion.h"

using namespace std;

class IncomesFile{

private:
    string fileName;
    TypeConversion typeConversion;

public:
    IncomesFile();
    virtual ~IncomesFile();
    void loadAllIncomesFromFile (vector <Income> &incomes);
    void loadIncomesFromAFileForTheLoggedinUser (vector <Income> &incomes, int loggedInUsersId);
    void addIncomeToFile (Income income);
};

