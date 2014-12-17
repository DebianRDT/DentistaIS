#include "fechas.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


namespace agenda{

    /** Constructor por defecto
     */
    Fecha::Fecha(){
        day_ = 0;
        month_ = 0;
        year_ = 0;
    }

    Fecha::Fecha(int day, int month, int year) {
        if(validar(day, month, year)) {
            day_=day;
            month_=month;
            year_=year;
        }
        else {
            day_=month_=year_=0;
        }
    }

    string Fecha::getFecha() {
        stringstream streamdia, streammes, streamanio;
        string dia, mes, anio;

        cout << "Dia_: " << day_ << endl;
        streamdia << day_;
        dia=streamdia.str();
        cout << "Dia: " << dia << endl;

        cout << "Mes_: " << month_ << endl;
        streammes << month_;
        mes=streammes.str();
        cout << "Mes: " << mes << endl;

        cout << "Año_: " << year_ << endl;
        streamanio << year_;

        anio=streamanio.str();
        cout << "Año: " << anio << endl;

        string cadena=dia + "/" + mes + "/" + anio;
        return cadena;
    }

    void Fecha::setFecha(const int &day, const int &month, const int &year) {
        if(validar(day, month, year)) {
            day_=day;
            month_=month;
            year_=year;
        }
    }

    bool Fecha::validar() {
        bool validez=false;

        cout << day_ << endl;
        cout << month_ << endl;
        cout << year_ << endl;

        switch(month_) {

        //Meses con 31 días
        case 1:
        case 3:
        case 5:
        case 7:
        case 10:
        case 12: if (day_ <= 31 && day_ >= 1) {
                validez=true;
            }

        //Meses con menos de 31 días
        case 2: if ((year_%4) == 0) {
                //Años bisiestos
                if(day_ <= 29 && day_ >= 1) {
                    validez=true;
                }
            }
            //Años no bisiestos
            else {
                if(day_ <= 28 && day_ >= 1) {
                    validez=true;
                }
            }

        case 4:
        case 6:
        case 8:
        case 9:
        case 11: if (day_ <= 30 && day_ >= 1) {
                validez=true;
            }
        }

        return validez;
    }

    bool Fecha::validar(const int &day, const int &month, const int &year) {
        bool validez=false;
        cout << day_ << endl;
        cout << month_ << endl;
        cout << year_ << endl;
        switch(month) {

        //Meses con 31 días
        case 1:
        case 3:
        case 5:
        case 7:
        case 10:
        case 12: if (day <= 31 && day >= 1) {
                validez=true; break;
            }

        //Meses con menos de 31 días
        case 2: if ((year%4) == 0) {
                //Años bisiestos
                if(day <= 29 && day >= 1) {
                    validez=true;
                }
            }
            //Años no bisiestos
            else {
                if(day <= 28 && day >= 1) {
                    validez=true;
                }
            } break;

        case 4:
        case 6:
        case 8:
        case 9:
        case 11: if (day <= 30 && day >= 1) {
                validez=true; break;
            }
        }

        return validez;
    }
}
