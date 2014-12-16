#ifndef FECHAS_H
#define FECHAS_H

class Fecha {
private:
    int month_;
    int day_;
    int year_;

public:
    Fecha(int day, int month, int year);
    bool validar();
    bool validar(int day, int month, int year);
    void setFecha(int day, int month, int year);
    string getFecha();

};



#endif
