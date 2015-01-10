#ifndef FECHAS_H
#define FECHAS_H

#include <iostream>
namespace agenda{

class Fecha {
private:
  int _month;
  int _day;
  int _year;
  
 public:
  Fecha();
  Fecha(int d, int m, int y);
  virtual ~Fecha();

  Fecha(std::string fecha);
  void setFecha(int d, int m, int y);
  std::string getFecha();

  bool operator==(const Fecha& f);
  
};


 
}


#endif
