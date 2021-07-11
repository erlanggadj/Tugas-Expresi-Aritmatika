//Erlangga Dwi Jiwantoro 2017051020
//Aniisah Mufiidah Suharso 2017051012
//Muhammad Hanif 2017051004

#include <iostream>
#include  <string>
#include <cstring>
using namespace std;

int main (){
    string input;
    getline(cin, input);
    
    cout << "Print : ";

    for(int i = 0; i < (int) input.size(); i++){
        if(input[i] == '-' && (input[i-1] == '+' || input[i-1] == '-' ||input[i-1] == '*' || input[i-1] == '/'|| input[i-1] == '%' )){
            cout << "-1 * ";
        }
        else if (input[i] == '-' && (input[i-1] >= '0'|| input[i-2] >= '0')){
            cout << " " << input[i] << " ";
        } 
        else if (input[i] == '-' && input[i+1] >= '0'){
            cout << input[i];
        }
        else if (input[i-1] >= '0' && input[i] == '-' ){
            cout << " " << input[i] << " ";
        }
        else if (input[i] == '-' && input[i+1] == '(' ){ 
            cout << "-1 * ";
        }    
        else if (input[i] >= '0'){
            cout << input[i];
        }
        else if (input[i] == '('){
            cout << input[i] << " ";
        }
        else if (input[i] == ')'){
            cout << " " << input[i];
        }
        else if (input[i] == '-' && (input[i-1] == '*' || input[i-1] == '+' || input[i-1] == '-' || input[i-1] == '/' || input[i-1] == '%')){
            cout << "-1 * ";
        }
        else if (input[i] == '-' || input[i] == '+' || input[i] '*' || input[i] == '/' || input[i] == '%'){
            cout << " " << input[i] << " ";
        }
    }
    
    return 0;
}
