#include <bits/stdc++.h>
using namespace std;

bool oibreoir(char r){
    if(r == '+' || 
       r == '-' || 
       r == '*' || 
       r == '/' || 
       r == '%'   ){
        return true;
    }
    else{
        return false;
    }
}

int prioritet(string r){
    if(r == "+" ||
       r == "-"   ){
        return 1;
    }
    else if(r == "*" ||
            r == "/" ||
            r == "%"   ){
        return 2;
    }
    return 0;
}

bool grande(string r, string s){
    int Nilai1, Nilai2;
    Nilai1 = prioritet(r); Nilai2 = prioritet(s);
    
    return Nilai1 <= Nilai2;
}

vector <string> infix; vector <string> postfix; string temp; vector <string>::iterator remake; vector <string>::iterator itu;
