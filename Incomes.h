#include <iostream>
#include <vector>
#include "IncomesFile.h"


using namespace std;

class Incomes {

private:
    vector <Income> incomes;
    int loggedInUsersId;
    IncomesFile incomesFile;
    Date date;
    int specifyID();

public:
    Incomes(int loggedInUsersId);
    virtual ~Incomes ();

    void addIncome();
    vector<Income> getIncomesFromSelectedPeriod(int startDate, int endDate);
    void sortIncomesByDateInAscendingOrder(vector<Income> &selectedIncomes);
    void showSelectedIncomes(vector<Income> &selectedIncomes);
    float getIncomesSum(vector<Income> &selectedIncomes);
};


