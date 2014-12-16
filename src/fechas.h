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
    bool validar(const int &day, const int &month, const int &year);
    void setFecha(const int &day, const int &month, const int &year);
    string getFecha();

};



#endif
