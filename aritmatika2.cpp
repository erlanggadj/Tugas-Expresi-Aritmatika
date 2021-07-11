#include <bits/stdc++.h>
using namespace std;

bool isOperator (char op){
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%'){
        return true;
    }
    else{
        return false;
    }
}

int compareOp (char com){
    int a;
    
    if (com == "+" || com == "-"){
        a = 1;
    }
    else if (com == "*" || com == "/" || com == "%"){
        a = 2;
    }
    
    return a;
}

bool precedence (char a, char b){
    int N1, N2;
    N1 = conpareOp(a);
    N2 = compareOp(b);
    
    return N1 <= N2;
}

vector <string> infix;
vector <string> postfix;
string temp;
vector <string>::iterator remake;
vector <string>::iterator that;

void pushData(){
}
