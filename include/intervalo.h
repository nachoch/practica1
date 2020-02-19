/**
 * **
   @file intervalo.cpp
   @brief Se proporciona parte de la clase intervalo y es necesario definir ciertos métodos para darle operatividad
   @author MP Grupos B, C
   @warning Módulo no definitivo (creado para ser modificado)

   Un ejemplo de ejecución es:

    Cuantos intervalos (max 10):5
    Introduce [ o ( cotaInferior, cotaSuperior ) o ]: [0,10] (0,10] [0,10) (0,10) (10,10)
    Cuantos valores reales (max 10):6
    Introduce valor real: -1 -0.001 0 5.7  9.6  10
    Da como salida:

 [0,10] : 0 5.7 9.6 10
 (0,10] : 5.7 9.6 10
 [0,10) : 0 5.7 9.6
 (0,10) : 5.7 9.6
 (0) :

 */

// Alumno1: Lucas Jose Lara Garcia
// Alumno2: Ignacio Carvajal Herrera 
// meter esta cabecera en todos los .h

#ifndef _INTERVALO_H
#define _INTERVALO_H

class Intervalo{
private:
    bool cerradoInf;
    bool cerradoSup;
    double cotaInf;
    double cotaSup;
    
    /**
     * @brief comprueba que los argumentos definen un intervalo correcto
     * cotaInferior <= cotaSuperior y algo MAS
     * @param cotaInferior
     * @param cotaSuperior
     * @return @retval true si correcto
     */
    bool valido(double,double, bool, bool); 

public:
    /** 
     *  @brief Intervalo vacio por defectoSup
     *  valorInf = valorSup & abiertoInf + abierto
     */
    Intervalo();
    /** 
     * @brief Crea un Intervalo  cerrado por defecto
     * @param cotaInferior
     * @param cotaSuperior
     * @precond cotaInferior <= cotaSuperior
     */
    Intervalo(double cotaInferior, double cotaSuperior);
    /** 
     * @brief Crea Intervalo
     * @param cerradoInferior
     * @param cerradoSuperior
     * @param cotaInferior
     * @param cotaSuperior
     * @precond cotaInferior <= cotaSuperior
     */
    Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);
    /** 
     * @brief Devuelve la cota inferior del intervalo
     * @return El valor de la cota
     */
    double getCotaInf()const ;
    /** 
     * @brief Devuelve la cota superior del intervalo
     * @return El valor de la cota
     */
    double getCotaSup()const ;
    /** 
     * @brief Consulta si el intervalo es cerrado en su cota inferior
     * @return @retval true si es cerrado @retval false si es cerrado
     */
    bool dentroCotaInf()const ;
    /** 
     * @brief Consulta si el intervalo es cerrado en su cota superior
     * @return @retval true si es cerrado @retval false si es cerrado
     */
    bool dentroCotaSup()const ;
    /** 
     * @brief Define los valores del intervalo
     * @param cerradoInferior
     * @param cerradoSuperior
     * @param cotaInferior
     * @param cotaSuperior
     * @precond cotaInferior <= cotaSuperior
     */
    void setIntervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);
    /** 
     * @brief Consulta si el intervalo almacenado es vacío o no
     * @return @retval true si es un intervalo vacío, @retval false en otro caso 
     */
    bool esVacio()const ;
    /** 
     * @brief Consulta si un determinado valor está dentro del intervalo
     * @param n El valor consultado
     * @return @retval true si el valor @p n pertenece al intervalo, @retval false en otro caso 
     */
    bool estaDentro(double n)const ;
};

// funciones externas
/**
* @brief Imprime los valores de un intervalo de forma visual según lo indicado en el guión
* @param  El intervalo
*/
void escribir(const Intervalo &i);

/**
* @brief Lee los valores del intervalo según el formato indicado en el guión
* @param i El intervalo
*/
void leer(Intervalo &i);
/**
* @brief Muestra un mensaje en pantalla indicando si el intervalo es vacío o no
* @param i El intervalo
*/

void comprobarVacio(Intervalo i);

#endif
