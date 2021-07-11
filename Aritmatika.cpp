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
    
    for (int i = 0; i < (int) simpan.size(); i++){
		
		if (isOperand(simpan[i]) || (simpan[i] == '-' && i == 0 && isOperand(simpan[i+1]))){
			temp.push_back(simpan[i]);
			continue;
		}
		if (isOperator(simpan[i])){
			if ((int) temp.size() != 0){
				infix.push_back(temp);
				temp.clear();
			}
			if ((simpan[i] == '-' && isOperator(simpan[i-1]))
			|| (simpan[i] == '-' && i == 0 && (simpan[i+1] == '('))
			|| (simpan[i] == '-' && (simpan[i-1] == '('))){
				infix.push_back("-1");
				infix.push_back("*");
			}
			else {
				infix.push_back(simpan.substr(i, 1));
			}
		}
		if (isParenthesis(simpan[i])){
			if ((int) temp.size() != 0){
				infix.push_back(temp);
				temp.clear();
			}
			infix.push_back(simpan.substr(i, 1));
		}
	}
	
	if ((int) temp.size() != 0){
		infix.push_back(temp);
		temp.clear();
	}
}

int main(){
    inputInfix();
    for (auto x = infix.begin(); x != infix.end(); ++x){
		cout << *x << " ";
	}
}
