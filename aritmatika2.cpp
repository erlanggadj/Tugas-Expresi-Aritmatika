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
