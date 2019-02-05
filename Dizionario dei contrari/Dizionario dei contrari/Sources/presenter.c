//
//  presenter.c
//  Dizionario dei contrari
//
//  Created by Roberto Vecchio on 03/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#include "presenter.h"

void doPresentation(char *software_name){
    printLogo(software_name);
}

void printEqualLine(){
    printf("\n============================================\n");
}

void printLogo(char *logo_name){
    printEqualLine();
    printf("=                                          =\n");
    printf("=  Benvenuto nel %s!  =\n", logo_name);
    printf("=                                          =\n");
    printEqualLine();
}

void printFunctionList(char *functionOne, char *functionTwo){
    printf("\nPosso svolgere diverse funzioni: \n\n");
    printf("• %s\n", functionOne);
    printf("• %s\n\n", functionTwo);
}


