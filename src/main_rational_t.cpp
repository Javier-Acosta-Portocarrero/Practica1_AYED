/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2023-2024
  * Practica nº 1
  
  * @file main_rational_t.cpp
  * @author Javier Acosta Portocarrero alu0101660769@ull.edu.es
  * @version 1.0
  * @date feb 7 2024
  * @brief Este programa muestra el funcionamiento de una clase que imita el 
  *        comportamiento de los numeros reales.
  * @bug There are no known bugs
  */

// pauta de estilo [92]: comentarios multilínea usando solo "//"
// Segun la guia de estilo de google: Puedes usar tanto el formato // como el 
// formato /* */.

#include <iostream>
#include <cmath>

// pauta de estilo [41]: ficheros de cabecera agrupados y separados
// Segun la guia de estilo de google: Incluye las cabeceras en el siguiente 
// orden: Cabeceras relacionadas, cabeceras del sistema de C, las cabeceras de 
// la libreria estandar de c++, las cabeceras de otras librerias y las 
// cabeceras de tu proyecto. Separa cada grupo no vacio con una linea en blanco.
#include "rational_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3), c;

  cout << "a.value()= " << a.value() << endl;
  cout << "b.value()= " << b.value() << endl;
  cout << "c.value()= " << c.value() << endl;

  cout << "a: ";
  a.write();
  cout << "b: ";
  b.write();

  c.read();
  cout << "c: ";
  c.write();

  // FASE II
  rational_t x(1, 3), y(2, 3);
  x.write();
  y.write();
  cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl;
  cout << "x < y? " << (x.is_greater(y) ? "true" : "false") << endl;
  cout << "x > y? " << (x.is_less(y) ? "true" : "false") << endl;

  // FASE III
  cout << "a + b: ";
  a.add(b).write();
  
  cout << "b - a: ";
  b.substract(a).write();

  cout << "a * b: ";
  a.multiply(b).write();
  
  cout << "a / b: ";
  a.divide(b).write();
  
  return 0;
}