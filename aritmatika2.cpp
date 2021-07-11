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
