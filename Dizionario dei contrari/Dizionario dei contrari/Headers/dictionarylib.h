//
//  dictionarylib.h
//  Dizionario dei contrari
//
//  Created by Roberto Vecchio on 05/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

                                                                    /* - Scopo della libreria - */
                                                              /*-----------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
                                                                    -----------------------------
                                                            |---->  |       dictionarylib.h     |  <----|
                                                                    -----------------------------
 
          La libreria in questione nasce con lo scopo di semplificare le operazioni che il dizionario virtuale deve eseguire durante il suo normale utilizzo.
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

                                                                  /* - definisco la libreria - */
                                                              /*-----------------------------------*/
#ifndef dictionarylib_h
#define dictionarylib_h

                                                                 /* - definizione di costanti - */
                                                              /*-----------------------------------*/


#define NUMBERS_OF_LETTERS 26    // numero delle lettere dell'alfabeto
#define MAX_WORD_FOR_LETTER 5    // numero massimo di parole per ogni lettera dell'alfabeto
#define MAX_PHRASE_LENGHT 150    // lunghezza massima della frase inserita
#define MAX_WORD_LENGHT 15       // lunghezza massima della parola da cercare
#define MAX_MEANING_LENGHT 100   // lunghezza massima del significato di una parola
#define MAX_CONTRARY_NUMBERS 5   // numero massimo di contrari
#define MAX_CONTRARY_LENGHT 20   // lunghezza massima della in termini di caratteri di un contrario


                                        /* - inclusione di libererie necessarie per la completezza di alcune funzioni - */
                                   /*---------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Includo le librerie standard e non, utili per lo sviluppo di alcune funzioni, sono state incluse quindi le librerie :
 
 - stdio.h : "standard input-output header" che contiene definizioni di macro, costanti e dichiarazioni di funzioni e tipi usati per gestire le varie operazioni di
             input/output. In particolare è stata inclusa allo scopo di utilizzare le funzioni : printf e scanf.
 
 - string.h : string.h è l'header file della libreria standard del C che contiene definizioni di macro, costanti e dichiarazioni di funzioni e tipi usati non solo
              nella manipolazione delle stringhe ma anche nella manipolazione della memoria.
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

                                                       /* - definizioni di nuovi tipi enum - */
                                                  /*---------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Definisco un nuovo tipo enumerativo chiamato alphabet_index, che in particolare può assumere 26 valori, ovvero le lettere di alfabeto.
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef enum { a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z } alphabet_index;


                                                     /* - definizioni di nuovi tipi struct - */
                                                 /*---------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Definisco il tipo wordstruct come struttura le cui variabili rappresentano :
 
 {
 - parola [lunghezza massima parola]
 - significato parola [lunghezza massima del significato]
 - array di contrari [massimo numero di contrari][massima lunghezza di un contrario]
 }
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef struct word {
    char name[MAX_WORD_LENGHT];
    char meaning[MAX_MEANING_LENGHT];
    char contrary[MAX_CONTRARY_NUMBERS][MAX_CONTRARY_LENGHT];
} wordstruct;


                                                            /* - prototipi di funzioni - */
                                                        /*------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Qui definisco i prototipi di funzioni che vengono discussi nel dettaglio nel file source dictionarylib.c
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*ricerca parola, significato e contrari*/
void resword(char *);
/*trova opposto di una frase*/
void opphrase(char *);
/*ritorna indice di una lettera*/
alphabet_index returnLetIndex(char letter);


#endif /* dictionarylib_h */
