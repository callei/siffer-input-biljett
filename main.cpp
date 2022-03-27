#include <iostream>

#include <string.h>

using namespace std;

int main()
{
    system("CHCP 1252");
cout << "hur gammal är du?" << endl;

  string s_heltal;

  cin >> s_heltal;
  for (int i=0; i<s_heltal.size(); i++) {

    if(s_heltal[i] == '-') {
        i = i * -1;
    }
    if(s_heltal[i] < '0' || s_heltal[i] > '9') {
        cout << "Felaktig inmatning" << endl;
        return 0;
    }
  }

    char *c_string = new char [s_heltal.length()+1];
    strcpy(c_string, s_heltal.c_str());
    int heltal = atoi(c_string);
     if ((heltal > 65) || (heltal < 12)) {
            cout <<"Det blir 20 kr att betala" << endl;
       }
    else {
            cout << "Det blir 30 kr att betala" << endl;
         }

 return 0;
}
