#include <iostream>
#include <vector>
#include "Incomes.h"

using namespace std;

class HomeBudget {

    void showTheIncomes (vector <Income> incomes, int month, int year);
   // void sorting(vector <Income> &incomes);

    public:
    void showTheBalance(int loggedInUsersID);
    void showTheIncomesBalanceFromTheSelectedPeriod (vector <Income> incomes, int earlierDate, int laterDate);
};
