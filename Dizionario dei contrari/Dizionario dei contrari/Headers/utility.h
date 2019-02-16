//
//  utility.h
//  Dizionario dei contrari
//
//  Created by Roberto Vecchio on 05/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

                                                                 /* - Scopo della libreria - */
                                                           /*-----------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
                                                                -----------------------------
                                                       |---->  |          utility.h         |  <----|
                                                               -----------------------------
 
                         La libreria in questione nasce con lo scopo di semplificare alcune operazioni a carattere generale
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

                                                              /* - definisco la libreria - */
                                                          /*-----------------------------------*/
#ifndef utility_h
#define utility_h

                                    /* - inclusione di libererie necessarie per la completezza di alcune funzioni - */
                               /*---------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Includo le librerie standard e non, utili per lo sviluppo di alcune funzioni, sono state incluse quindi le librerie :
 
 - stdio.h : "standard input-output header" che contiene definizioni di macro, costanti e dichiarazioni di funzioni e tipi usati per gestire le varie operazioni di
 input/output. In particolare è stata inclusa allo scopo di utilizzare le funzioni : printf e scanf.
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>


                                                             /* - prototipi di funzioni - */
                                                        /*------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Qui definisco i prototipi di funzioni che vengono discussi nel dettaglio nel file source utility.c
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*rimuove lo \n da input*/
void cleanBuffer(void);
/*stampa logo del programma*/
void pntlogo(void);

#endif /* utility_h */
