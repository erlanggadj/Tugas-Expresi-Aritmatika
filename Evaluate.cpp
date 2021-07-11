//Erlangga Dwi Jiwantoro 2017051020
//Aniisah Mufiidah Suharso 2017051012
//Muhammad Hanif 2017051004
#include <bits/stdc++.h>
using namespace std;

vector <string> infix;
vector <string> postfix;
string simpan, temp, add;
char input;
stack <string> P;
stack <string> V;

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

vector <string>::iterator j;

void toPostfix(){
	int y = 0;
	for (j = infix.begin(); j != infix.end(); j++, y++){
		if (isdigit(infix[y].back())){
			postfix.push_back(infix[y]);
			continue;
		}
		if (infix[y] == "("){
			P.push(infix[y]);
			continue;
		}
		if (infix[y] == ")"){
			while (!P.empty() && (P.top() != "(")){
				add = P.top();
				postfix.push_back(add);
				P.pop();
			}
			P.pop();
			continue;
		}
		if (isOperator(infix[y][0])){
			if (P.empty() || (P.top() == "(")){
				P.push(infix[y]);
			}
			else {
				while (!P.empty() && (P.top() != "(") && precedence(infix[y], P.top())){
					add = P.top();
					postfix.push_back(add);
					P.pop();
				}
				P.push(infix[y]);
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

int v1, v2, v3;
string v4;
vector <string>::iterator k;

void evaluate(){
	stringstream ss;
	int l = 0;
	for (k = postfix.begin(); k != postfix.end(); k++, l++){
		if (isOperand(postfix[l].back())){
			V.push(postfix[l]);
			continue;
		}
		if (isOperator(postfix[l][0])){
			v1 = atoi ((V.top()).c_str());
			V.pop();
			v2 = atoi ((V.top()).c_str());
			V.pop();
			if (postfix[l] == "+"){
				v3 = v2 + v1;
				ss << v3;
				string str = ss.str();
				V.push(str);
			}
			else if (postfix[l] == "-"){
				v3 = v2 - v1;
				ss << v3;
				string str = ss.str();
				V.push(str);
			}
			else if (postfix[l] == "*"){
				v3 = v2 * v1;
				ss << v3;
				string str = ss.str();
				V.push(str);
			}
			else if (postfix[l] == "/"){
				v3 = v2 / v1;
				ss << v3;
				string str = ss.str();
				V.push(str);
			}
			else if (postfix[l] == "%"){
				v3 = v2 % v1;
				ss << v3;
				string str = ss.str();
				V.push(str);
			}
			continue;
		}
	}
	v4 = V.top();
	V.pop();
	cout << v4;
}


int main(){
	
	inputInfix();
	//cout << "Print : ";
	//for (auto x = infix.begin(); x != infix.end(); ++x){
	//	cout << *x << " ";
	//}
	toPostfix();
	//cout << "Print : ";
	//for (auto x = postfix.begin(); x != postfix.end(); ++x){
	//	cout << *x << " ";
	//}
	evaluate();
	
	return 0;
}
