#include <iostream>
#include "intervalo.h"
using namespace std;


bool Intervalo::valido(double cinf,double csup, bool cerrinf, bool cerrsup){
   return (( cinf < csup ) || ( cinf == csup && cerrinf == cerrsup));
}

double Intervalo::getCotaSup() const {
	return cotaSup;
}

bool Intervalo::dentroCotaInf() const {
	return cerradoInf;
}

bool Intervalo::dentroCotaSup() const {
	return cerradoSup;
}

void escribir(const Intervalo & obj) {
    if (obj.esVacio())
        cout << "(0)";
    else {
        if (obj.dentroCotaInf())
         cout << '[';
        else cout << '(';
        cout << obj.getCotaInf() << "," << obj.getCotaSup();
        if (obj.dentroCotaSup())
            cout << ']';
        else cout << ')';
    }
}

void leer(Intervalo & obj){
    // Formato de lectura del intervalo: [|( x,y )|]
    bool cerradoInf = true;
    bool cerradoSup = true;
    double cotaInf, cotaSup;
    char car;
    cin >> car;
    if (car == '(')
        cerradoInf = false;
    cin >> cotaInf;
    cin >> car;
    cin >> cotaSup;
    cin >> car;
    if (car == ')')
        cerradoSup = false;
    obj.setIntervalo(cotaInf, cotaSup, cerradoInf, cerradoSup);
}

void comprobarVacio(Intervalo obj){
	 escribir(obj);
    if (obj.esVacio())
        cout << " Vacio";
    else  cout << " NO Vacio";
    cout << endl;
}
