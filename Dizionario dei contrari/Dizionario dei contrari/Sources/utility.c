//
//  utility.c
//  Dizionario dei contrari
//
//  Created by Roberto Vecchio on 05/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

                                                                /* - Scopo della libreria - */
                                                          /*-----------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
                                                                -----------------------------
                                                       |---->  |          utility.c         |  <----|
                                                               -----------------------------
 
 La libreria in questione nasce con lo scopo di semplificare alcune operazioni a carattere generale
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


                                                             /* - Inclusione header file - */
                                                         /*-----------------------------------*/
#include "utility.h"

/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        cleanBuffer
 
 * input:       nessuno
 
 * output:      pulisce input da \n
 
 * descrizione: spesso succede che dato in input un valore il c memorizzi anche lo \n, quesa procedura serve per rimuoverlo e risolvere eventuali imprevedibilità da esso
                causato.
 
 * versione:    1.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void cleanBuffer(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        pntLogo
 
 * input:       nessuno
 
 * output:      stampa a video il logo del programma
 
 * descrizione: procedura che permette di stampare a video il logo del programma disegnato in ascii
 
 * versione:    1.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void pntlogo(){
    printf("                                  _.             \n                         _.-----'' `\\             \n             __..-----'''            `.\n            <            `\\.           '\\\n            :.              `.           `\\\n             `:.              `.           `-.\n               `:\\ N  o         `.            `+.\n                 `:. A  s  i      `.  __.===::::;)\n .         r   I   `: c       ___.__>'::::::a:f/'\n       C          A   `.  _,===:::=-'-=-\"\"\"\"\n   i      d  t         '-/:::''\n                         ''\n           y");
}
