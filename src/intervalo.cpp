#include <iostream>
#include "intervalo.h"
using namespace std;


bool Intervalo::valido(double cinf,double csup, bool cerrinf, bool cerrsup){
   return (( cinf < csup ) || ( cinf == csup && cerrinf == cerrsup));
}

Intervalo::Intervalo(){
	cotaInf = 0;
	cotaSup = 0;
}

Intervalo::Intervalo(double cotaInferior, double cotaSuperior){
	cerradoInf = true;
   cerradoSup = true;
	if (cotaInferior <= cotaSuperior) {
		cotaInf = cotaInferior;
    	cotaSup = cotaSuperior;
	}
}

Intervalo::Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior){
   if (cotaInferior <= cotaSuperior) {
      cerradoInf = cerradoInferior;
      cerradoSup = cerradoSuperior;
      cotaInf = cotaInferior;
      cotaSup = cotaSuperior;
   }
}

double Intervalo::getCotaInf()const {
   return cotaInf;
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

void Intervalo::setIntervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior){
	cerradoInf = cerradoInferior;
	cerradoSup = cerradoSuperior;

	if ( cotaInferior <= cotaSuperior){
		cotaInf = cotaInferior;
		cotaSup = cotaSuperior;
	}
}

bool Intervalo::esVacio() const {
	bool vacio = false;

	if (cotaInf == cotaSup && (cerradoInf == false) && (cerradoSup == false))
		vacio = true;

	return vacio;
}

bool Intervalo::estaDentro(double n)const {
   bool dentro;
   if (cerradoInf == true && cerradoSup == true) {
      if (cotaInf <= n && n <= cotaSup) {
         dentro = true;
      } else{
         dentro = false;
      }
   }
   else if (cerradoInf == false && cerradoSup == true) {
      if (cotaInf < n && n <= cotaSup) {
         dentro = true;
      } else{
         dentro = false;
      }
   }
   else if (cerradoInf == true && cerradoSup == false) {
      if (cotaInf <= n && n < cotaSup) {
         dentro = true;
      } else{
         dentro = false;
      }
   }
   else if (cerradoInf == false && cerradoSup == false){
      if (cotaInf < n && n < cotaSup) {
         dentro = true;
      } else{
         dentro = false;
      }
   }

   return dentro;
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
