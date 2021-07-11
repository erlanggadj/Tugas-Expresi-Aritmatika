#include <bits/stdc++.h>
using namespace std;

vector <string> infix;
vector <string> postfix;
string simpan, temp, add;
char input, s;
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

int compare (char pre){
	int a;
	
	if (pre == '*' || pre == '/' || pre == '%'){
		a = 2;
	}
	else if (pre == '+' || pre == '-'){
		a = 1;
	}
	
	return a;
}

bool precedence (char a, char b){
	int value1, value2;
	value1 = compare(a);
	value2 = compare(b);
	
	return value1 <= value2;
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
	
	//for (auto x = infix.begin(); x != infix.end(); ++x){
	//	cout << *x << " ";
	//}
}

void toPostfix(){
	for (auto j = infix.begin(); j != infix.end(); ++j){
		if (isOperand(infix[j])){
			postfix.push_back(infix[j]);
			continue;
		}
		if (infix[j] == '('){
			P.push_back(infix[j]);
			continue;
		}
		if (infix[j] == ')'){
			while (!P.empty() && (P.top() != '(')){
				add = P.top();
				postfix.push_back(add);
				P.pop()
			}
			P.pop();
			continue;
		}
		if (isOperator(infix[j])){
			if (P.empty() || (P.top() == '(')){
				P.push_back(infix[j]);
			}
			else {
				while (!P.empty() && (P.top() != '(') && precedence(infix[j], P.top())){
					add = P.top();
					postfix.push_back(add);
					P.pop();
				}
				s = infix[j]
				P.push_back(s);
			}
			continue;
		}
	}
	
	while (!P.empty()){
		add = P.top();
		postfix.push_back(add);
		P.pop();
	}
}

int main(){
	
	inputInfix();
	for (auto x = postfix.begin(); x != postfix.end(); ++x){
		cout << *x << " ";
	}
	
	return 0;
}
