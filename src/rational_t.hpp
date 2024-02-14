/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2023-2024
  * Practica nº 1
  * 
  * @file rational_t.hpp
  * @author Javier Acosta Portocarrero alu0101660769@ull.edu.es
  * @version 1.0
  * @date feb 7 2024
  * @brief Este programa muestra el funcionamiento de una clase que imita el 
  *        comportamiento de los numeros reales.
  * @bug There are no known bugs
  */

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
#define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
  // Segun la guia de estilo de google: La declaracion de una clase debe, 
  // normalmente, inicar con public: seguido de protected: y despues private:, 
  // omitiendo los espacios de acceso vacios.
public:
  rational_t(const int = 0, const int = 1);
  ~rational_t() {}
  
  // pauta de estilo [71]: indentación a 2 espacios
  // Segun la guia de estilo de google: El indentado horizontal por defecto 
  // dentro de un nuevo ambito es de dos espacios menos en algunos casos 
  // especificos.

  // getters
  int get_num() const;
  int get_den() const;
  
  // setters
  void set_num(const int);
  void set_den(const int);

  double value(void) const;

  // FASE II
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;
  
  // FASE III
  rational_t add(const rational_t&);
  rational_t substract(const rational_t&);
  rational_t multiply(const rational_t&);
  rational_t divide(const rational_t&);
  
  void write(ostream& = cout) const;
  void read(istream& = cin);
  
private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  // Segun la guia de estilo de google: Los atributos de una clase deben de 
  // seguir el formato snake_case ademas de añadir adicionalmente un guion bajo 
  // al final del nombre de la variable.
  int num_, den_;
};
