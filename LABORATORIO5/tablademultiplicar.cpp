#include <iostream>

using namespace std;

int main(void){
    cout << "Ingrese un nmero" <<endl;
    
    float num2 = 0;
    cin >> num2;
    for (float num1 = 1;  num1 <= 10; num1++)
    {
        cout <<num1<< "*" << num2 << "=" <<num1*num2 <<"" <<endl;
    }
    return 0;
}