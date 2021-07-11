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
    string masuk;
    char data;
    
    while(cin.get(data)){
        if(data == '\n'){
            break;
        }
        if(data != ' '){
            masuk.push_back(data);
        }
    }
    int length = masuk.length();

    for(int i = 0; i < length; i++){
        if(masuk[i] == '(' ||
           masuk[i] == ')'){
            if(temp.length() != 0){
                infix.push_back(temp);
                temp.clear();
            }
            infix.push_back(masuk.substr(i, 1));
        }
        if(isdigit(masuk[i]) ||
           (masuk[i] == '-' &&
            i == 0 &&
            isdigit(masuk[i+1]))){
            
            temp.push_back(masuk[i]);
            continue;
        }
        if(isOperator(masuk[i])){
            if(temp.length() != 0){
                
                infix.push_back(temp);
                temp.clear();
            }
            if((masuk[i] == '-' &&
                isOperator(masuk[i-1])) ||
               (masuk[i] == '-' &&
                i == 0 && masuk[i+1] == '(') ||
               (masuk[i] == '-' &&
                masuk[i-1] == '(')){
                
                infix.push_back("-1");
                infix.push_back("*");
            }else{
                infix.push_back(masuk.substr(i, 1));
            }
        }
    }
}
