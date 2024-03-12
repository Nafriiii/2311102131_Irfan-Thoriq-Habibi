/*
oleh Irfan Thoriq Habibi - 2311102121
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    char op;
    float num1,num2;
    // it allows user to enter operator i.e.+,-,*,/
    cout << "enter operator (+,-,*,/): ";
    cin >> op;
    //it allows user to enter the operands
    cout << "enter two operands: ";
    cin >> num1>> num2;
    //switch statemant begins 
    switch (op){
        //if user enters +
        case '+':
        cout << "result: "<< num1+num2;
        break;
        // if user enters -
        case '-':
        cout << "result: "<<num1-num2;
        break;
        //if user enters *
        case '*':
        cout << "result: "<<num1 *num2;
        break;
        //if user enters /
        case '/':
        if (num2 !=0){
            cout <<"result: "<< fixed<<setprecision(2)<<num1/num2;
        }else {
            cout <<"error ! Devision by zero is not allowed.";
        }
        break;
        //if the operator is other than +,-,*,/
        //eror message will display
        default:
        cout << " Error! Operator is not correct";
    }//switch statment ends.
    return 0;
}
