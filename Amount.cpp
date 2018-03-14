#include <iostream>
#include <windows.h>
#include "Amount.h"


using namespace std;

float Amount::setTheDot (string amount){

int i = 0;
    while (i<amount.length()){
       if (amount [i] != 46 && amount [i] !=44){
        i++;
       }else if (amount [i]==46){
        i++;
       }else if (amount [i]==44){
        amount [i] = '.';
        i++;
       }
    }
return atof(amount.c_str());
}

