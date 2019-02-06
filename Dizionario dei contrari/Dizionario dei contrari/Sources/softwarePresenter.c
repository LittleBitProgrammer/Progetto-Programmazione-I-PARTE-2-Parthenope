//
//  presenter.c
//  Dizionario dei contrari
//
//  Created by Roberto Vecchio on 03/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#include "softwarePresenter.h"

void doPresentation(char *software_name, char *functionOne, char *functionTwo){
    printLogo(software_name);
    printFunctionList(functionOne, functionTwo);
}

void printEqualLine(){
    printf("\n============================================\n");
}

void printLogo(char *logo_name){
    printEqualLine();
    printf("=                                          =\n");
    printf("=  Benvenuto nel %s!  =\n", logo_name);
    printf("=                                          =");
    printEqualLine();
}

void printFunctionList(char *functionOne, char *functionTwo){
    printf("\nPosso svolgere diverse funzioni: \n\n");
    printf("• %s\n", functionOne);
    printf("• %s\n\n", functionTwo);
}


