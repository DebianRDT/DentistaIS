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

    Fecha::Fecha(string fecha) {
        char *cadena=strdup(fecha.c_str());
        char *ptr;

        ptr = strtok( cadena, "/" );
        day_ = atoi(ptr);

        ptr = strtok( NULL, "/" );
        month_ = atoi(ptr);

        ptr = strtok( NULL, "/" );
        year_ = atoi(ptr);
    }

    const string& Fecha::getFecha(){

        ostringstream ss;
        ss<<day_<<"/"<<month_<<"/"<<year_;
        return ss.str();

    }

    void Fecha::setFecha(const int &day, const int &month, const int &year) {
        if(validar(day, month, year)) {
            day_=day;
            month_=month;
            year_=year;
        }
    }

    void Fecha::setFecha(string fecha) {
        char *cadena=strdup(fecha.c_str());
        char *ptr;

        ptr = strtok( cadena, "/" );
        day_ = atoi(ptr);

        ptr = strtok( NULL, "/" );
        month_ = atoi(ptr);

        ptr = strtok( NULL, "/" );
        year_ = atoi(ptr);
    }

    bool Fecha::validar() {
        bool validez=false;



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

  bool Fecha::operator==(const Fecha& f){
    if(day_ == f.day_, month_ == f.month_ && year_ == f.year_)
      return true;
    else
      return false;
  }



}
