#ifndef FECHAS_H
#define FECHAS_H
#include <iostream>
namespace agenda{

class Fecha {
private:
    int month_;
    int day_;
    int year_;

public:
	Fecha();
    Fecha(int day, int month, int year);
    bool validar();
    bool validar(const int &day, const int &month, const int &year);
    void setFecha(const int &day, const int &month, const int &year);
    std::string getFecha();

};

}


#endif
