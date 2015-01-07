#ifndef FECHAS_H
#define FECHAS_H
#include <iostream>
namespace agenda{

class Fecha {
private:
    int month_;
    int day_;
    int year_;
    bool validar();
    bool validar(const int &day, const int &month, const int &year);

public:
	Fecha();
    Fecha(int day, int month, int year);
    Fecha(std::string fecha);
    void setFecha(const int &day, const int &month, const int &year);
    void setFecha(std::string fecha);
    const std::string& getFecha();
    bool operator==(const Fecha& f);

};

}


#endif
