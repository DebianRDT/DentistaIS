#include "fechas.h"
#include <iostream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


namespace agenda{

  /** Constructor por defecto
   */
  Fecha::Fecha(){
    _day = 0;
    _month = 0;
    _year = 0;
  }

  Fecha::Fecha(int d, int m, int y) {
    _day = d;
    _month = m;
    _year = y;

  }

  Fecha::~Fecha(){}

  string Fecha::getFecha(){
    
    ostringstream ss;
    ss<<_day<<"/"<<_month<<"/"<<_year;
    return ss.str();
    
  }
  
  void Fecha::setFecha(int d, int m, int y) {
    _day= d;
    _month = m;
    _year = y;
  }
  

  bool Fecha::operator==(const Fecha& f){
    if(_day == f._day, _month == f._month && _year == f._year)
      return true;
    else
      return false;
  }



}
