#include <iostream>
using namespace std;

int main(void){
    
    float numsecreto = 23;
    float nuevonum = 0;
    
    do
    {
    cout << "Ingrese el número secreto" <<endl;
    cin >>nuevonum;
    if (nuevonum > numsecreto)
    cout << "El numero" "" << nuevonum << "" "Es mayor al numero secreto" << endl;
    else if (nuevonum < numsecreto)
    {
    cout << "Numero es menor al numero secreto";
    }

    }while (nuevonum != numsecreto);  
    return 0;
}


