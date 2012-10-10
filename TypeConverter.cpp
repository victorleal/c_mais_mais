/* 
 * File:   TypeConverter.cpp
 * Author: victorleal
 *
 * Created on 8 de Outubro de 2012, 23:30
 */

#include "TypeConverter.h"
#include <iostream>
using namespace std;
string TypeConverter::convertFloatToString(float valor) {
    ostringstream buffer;
    buffer << valor;
    return buffer.str();
}

float TypeConverter::convertStringToFloat(string valor) {
    istringstream buffer(valor);
    float valorConvertido;
    buffer >> valorConvertido;
    return valorConvertido;
}

time_t TypeConverter::convertStringToTime(string valor) {
    time_t t;
    const char *c;
    c = valor.c_str();
    strptime(c, "%d/%m/%Y %k:%M:%S", &tm);
    tm.tm_hour = tm.tm_hour + 1; //Horário de verão kkk
    cout << "huera:" << tm.tm_hour;
    cout << "\n\n";
    t = mktime(&tm);
    return t;
}

string TypeConverter::convertTimeToString(time_t valor) {
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %k:%M:%S", &tm);
    return buffer;
}