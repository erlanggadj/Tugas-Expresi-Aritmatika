//Erlangga Dwi Jiwantoro 2017051020
//Aniisah Mufiidah Suharso 2017051012
//Muhammad Hanif 2017051004

//HACKERRANK

#include <bits/stdc++.h>
using namespace std;

vector <string> infix;
string simpan, temp;
char input;

bool isOperand (char op){
    int ascii = (int) op;
    if (ascii >= 48 && ascii <= 57){
        return true;
    }
    else {
        return false;
    }
}

bool isParenthesis (char p){
    if (p == '(' || p == ')'){
        return true;
    }
    else {
        return false;
    }
}

bool isOperator (char ch){
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '%'){
        return true;
    }
    else {
        return false;
    }
}

void inputInfix(){
    
    //menyimpan inputan infix tanpa spasi
    while (cin.get(input)){
        if (input != ' '){
            simpan.push_back(input);
        }
        if (input == '\n'){
            break;
        }
    }
    
    //
}

int main(){
    inputInfix();
}
