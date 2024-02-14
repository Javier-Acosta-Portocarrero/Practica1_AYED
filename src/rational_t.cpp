/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2023-2024
  * Practica nº 1
  * 
  * @file rational_t.cpp
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
#include <cmath>

#include "rational_t.hpp"

/**
  * @brief Este metodo el es constructor de la clase rational_t, encargado 
  *        de inicializar sus atributos.
  *
  * @param n El valor con el cual sera inicializado el atributo num_.
  * @param d El valor con el cual sera inicializado el atributo den_.
  * @return El objeto ya construido.
  */

rational_t::rational_t(const int n, const int d) 
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos
// Segun la guia de estilo de google: El identado vertical debe de evitarse y 
// solo usarse si es necesario para mejorar la leebilidad del codigo, sin poner
// mas de 1 o dos espacios.

// pauta de estilo [83]: tipo retornado en línea anterior al método
// Segun la guia de estilo de google: El tipo retornado debe ir antes del 
// nombre de la funcion o metodo, es decir, en la misma linea.

/**
  * @brief Este metodo es el getter que permite obtener el valor del atributo num_.
  *
  * @return El valor del atributo num_ de la clase rational_T.
  */

int 
rational_t::get_num() const 
{
  return num_;
}


/**
  * @brief Este metodo es el getter que permite obtener el valor del atributo den_.
  *
  * @return El valor del atributo den_ de la clase rational_T.
  */

int 
rational_t::get_den() const 
{
  return den_;
}


/**
  * @brief Este metodo es el setter que permite cambiar el valor del atributo num_.
  *
  * @param n El valor que será asginado al atributo num_.
  */

void 
rational_t::set_num(const int n) 
{
  num_ = n;
}


/**
  * @brief Este metodo es el setter que permite cambiar el valor del atributo den_.
  *
  * @param d El valor que será asginado al atributo den_.
  */

void 
rational_t::set_den(const int d) 
{
  assert(d != 0);
  den_ = d;
}


/**
  * @brief Este metodo permite obtener el valor decimal de un real.
  *
  * @return El valor decimal resultado de realizar la division entre el numerador y el denominador.
  */

double 
rational_t::value() const 
{ 
  return double(get_num()) / get_den();
}



// comparaciones
/**
  * @brief Este metodo decide si dos reales son equivalentes o no.
  *
  * @param r El segundo real a comparar con el objeto que llame al metodo.
  * @param precision El valor que limita el error permitido entre dos reales para que sean iguales.
  * @return 0 si son iguales y 1 si no lo son.
  */

bool 
rational_t::is_equal(const rational_t& r, const double precision) const
{
  double real1{static_cast<double>(get_num()) / static_cast<double>(get_den())};
  double real2{static_cast<double>(r.get_num()) / static_cast<double>(r.get_den())};
  if (abs(real1 - real2) < precision)  {
    return 1;
  } 
  return 0;    
}


/**
  * @brief Este metodo decide si un real es mayor que otro.
  *
  * @param r El segundo real a comparar con el objeto que llame al metodo.
  * @param precision El valor que limita el error permitido para que un real sea mayor a otro.
  * @return 0 si el segundo real es mayor al primero y 1 si no.
  */

bool 
rational_t::is_greater(const rational_t& r, const double precision) const
{
  double real1{static_cast<double>(get_num()) / static_cast<double>(get_den())};
  double real2{static_cast<double>(r.get_num()) / static_cast<double>(r.get_den())};
  if (real1 - real2 > precision)  {
    return 0;
  } 
  return 1;
}


/**
  * @brief Este metodo decide si un real es menor que otro.
  *
  * @param r El segundo real a comparar con el objeto que llame al metodo.
  * @param precision El valor que limita el error permitido para que un real sea menpr a otro.
  * @return 0 si el segundo real es menor al primero y 1 si no.
  */

bool 
rational_t::is_less(const rational_t& r, const double precision) const
{
  double real1{static_cast<double>(get_num()) / static_cast<double>(get_den())};
  double real2{static_cast<double>(r.get_num()) / static_cast<double>(r.get_den())};
  if (real1 - real2 < (-1 * precision))  {
    return 0;
  } 
  return 1; 
}


// operaciones
/**
  * @brief Este metodo realiza la suma entre dos reales.
  *
  * @param r El segundo real a sumar con el objeto que llame al metodo.
  * @return El real resultante de la suma.
  */

rational_t 
rational_t::add(const rational_t& r)
{
  rational_t resultado_suma;
  resultado_suma.set_num(get_num() * r.get_den() + r.get_num() * get_den());
  resultado_suma.set_den(get_den() * r.get_den());
  return resultado_suma;
}


/**
  * @brief Este metodo realiza la resta entre dos reales.
  *
  * @param r El segundo real a restar al objeto que llame al metodo.
  * @return El real resultante de la resta.
  */

rational_t 
rational_t::substract(const rational_t& r)
{
  rational_t resultado_resta;
  resultado_resta.set_num(get_num() * r.get_den() - r.get_num() * get_den());
  resultado_resta.set_den(get_den() * r.get_den());
  return resultado_resta;
}


/**
  * @brief Este metodo realiza la multiplicacion entre dos reales.
  *
  * @param r El segundo real a amultiplicar con el objeto que llame al metodo.
  * @return El real resultante de la multiplicacion.
  */

rational_t 
rational_t::multiply(const rational_t& r)
{
  rational_t resultado_multiplicacion;
  resultado_multiplicacion.set_num(get_num() * r.get_num());
  resultado_multiplicacion.set_den(get_den() * r.get_den());
  return resultado_multiplicacion;
}


/**
  * @brief Este metodo realiza la division entre dos reales.
  *
  * @param r El segundo real que dividira al objeto que llame al metodo.
  * @return El real resultante de la division.
  */

rational_t 
rational_t::divide(const rational_t& r)
{
  rational_t resultado_division;
  resultado_division.set_num(get_num() * r.get_den());
  resultado_division.set_den(get_den() * r.get_num());
  return resultado_division;
}



// E/S
/**
  * @brief Este metodo permite escribir un real por pantalla.
  *
  * @param os El flujo de salida que sera modificado.
  */

void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}


/**
  * @brief Este metodo permite leer un real por teclado.
  *
  * @param n El flujo de entrada que sera modificado,
  */

void 
rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
