/* 
 * File:   Interfaces.h
 * Author: victorleal
 *
 * Created on 14 de Outubro de 2012, 23:14
 */

#ifndef INTERFACES_H
#define	INTERFACES_H

#include <iostream>
#include <string>
#include <sstream>
#include <dirent.h>
#include <stdio.h>
#include "Bilhete.h"
#include "Cliente.h"
#include "Espetaculo.h"
#include "TypeConverter.h"

using namespace std;

class Interfaces {
public:
    Interfaces();

    //Chamadas funções classe - INICIO
    void cadastrarCliente();
    void cadastrarEspetaculo();
    void cadastrarBilhete();
    void editarCliente();
    void editarEspetaculo();
    void editarBilhete();
    void excluirCliente();
    void excluirEspetaculo();
    void excluirBilhete();
    void listarCliente();
    void listarEspetaculo();
    void listarBilhete();
    //Chamadas funções classe - FIM

    Interfaces(const Interfaces& orig);
    virtual ~Interfaces();
    void limpaBuffer();
private:

};

#endif	/* INTERFACES_H */

