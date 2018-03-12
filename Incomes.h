#include <iostream>
#include <vector>
#include "IncomesFile.h"


using namespace std;

class Incomes {

private:
    vector <Income> incomes;
    int loggedInUsersId;
    IncomesFile incomesFile;
    int specifyID();

public:
    Incomes(int loggedInUsersId);
    virtual ~Incomes ();
    vector <Income> getIncomes();

    void addIncome();
};


