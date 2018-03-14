#include <iostream>
#include <sstream>
#include "TypeConversion.h"

using namespace std;

string TypeConversion::convertIntToString(int number){
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int TypeConversion::convertStringToInt (string text){
    int i;
    istringstream iss(text);
    iss >> i;
    return i;
}

string TypeConversion::convertFloat (float value) {
  ostringstream o;
  if (!(o << value))
    return "";
  return o.str();
}
