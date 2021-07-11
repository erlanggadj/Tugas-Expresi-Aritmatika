#include <iostream>
#include <stack>
#include <ctype.h>
using namespace std;

vector <string> infix;
vector <string> postfix;
string simpan, temp, add;
char input;
stack <string> P;

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

int compare (string pre){
	int a;
	
	if (pre == "*" || pre == "/" || pre == "%"){
		a = 2;
	}
	else if (pre == "+" || pre == "-"){
		a = 1;
	}
	
	return a;
}

bool precedence (string a, string b){
	int value1, value2;
	value1 = compare(a);
	value2 = compare(b);
	
	return value1 <= value2;
}

int main(){
  
}
