//
//  main.c
//  Dizionario dei contrari
//
//  Created by Roberto Vecchio on 03/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

                                                      /* Roberto Vecchio - I anno informatica - mat. 0124001871 */

                                         /* https://github.com/robertove93/Progetto-Programmazione-I-PARTE-2-Parthenope*/

                                                                    /* - Traccia progetto - */
                                                            /*-----------------------------------*/


/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Si vuole simulare la gestione di un dizionario dei contrari.Il dizionario è indicizzato tramite lettere dell'alfabeto ed ogni parola contiene il significato e i suoi
 contrari (massimo 5)(e.g. gestione matriciale).
 
 Permettere all'utente di:
 
 - inserire una parola e chiedere all'utente quale contrario vuole cercare nel dizionario. Ricercare il contrario e visualizzare il significato.
 
 - Provvedere all'implementazione dell'algoritmo che data una frase ritorna una nuova frase con i contrari al posto delle parole decise dall'utente.
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


                                                           /* - Spiegazione finalità del programma - */
                                                     /*-------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Il programma in questione, scritto in linguaggio C, ha lo scopo di simulare l'utilizzo di un dizionario virtuale dove l'utente ha la possibilità non solo di cercare
 una parola e mostrarne significato e contrari ma anche di dare in input una frase qualsiasi e di cercare il suo esatto contrario. La lista di parole disponibili per
 il dizionario virtuale è presente nel file dictionarylib.h
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


                                                             /* - Inclusione di librerie standard - */
                                                       /*-----------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Includo le librerie standard utili per lo sviluppo del file main.c, quindi:
 
 - stdio.h : "standard input-output header" che contiene definizioni di macro, costanti e dichiarazioni di funzioni e tipi usati per gestire le varie operazioni di
 input/output. In particolare è stata inclusa allo scopo di utilizzare le funzioni : printf e scanf.
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>


                                                            /* - Inclusione di librerie non stardard - */
                                                       /*--------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Includo le librerie non standard, ovvero create da me, utili per lo sviluppo del file main.c, sono state incluse quindi le seguenti :
 
 - utility.h       : libreria creata allo scopo di gestire operazioni di utilità generale come la stampa del logo e altro (spiegazione dettagliata nell'header file).
 
 - dictionarylib.h : libreria creata allo scopo di gestire le varie operazioni che il dizionario deve svolgere (spiegazione dettagliata nell'header file).
 
 --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include "../Headers/utility.h"
#include "../Headers/dictionarylib.h"



                                                              /* - definizioni di nuovi tipi enum - */
                                                         /*---------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Qui definisco il tipo booleano, dove false assume il valore di 0 e true assume il valore di 1, utile per gestire alucune logiche del software.
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef enum { false, true} bool;

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Definisco un nuovo tipo enumerativo chiamato choice, che in particolare può assumere 3 valori :
 
 - ricerca
 - frase
 - exit
 
 Utile per gestire le casistiche del menu, ovvero viene utilizzato nello switch per permettere all'utente di svolgere diverse azioni previste dal dizionario.
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef enum { ricerca = 1, frase, exit } choice;


                                                                           /* - main - */
                                                               /*-----------------------------------*/

int main(int argc, const char * argv[]) {
    
                                                                  /* - Dichiarazione variabili - */
                                                             /*---------------------------------------*/
    
    char word_searched[MAX_WORD_LENGHT];  //array monodimensionale di caratteri utile per memorizzare la parola di cui si vuole cercare significato e contrario.
    
    char phrase[MAX_PHRASE_LENGHT];       //array monodimensionale di caratteri utile per memorizzare la frase di cui si vuole cercare il contrario.
    
    bool would_exit = false;              //variabile di tipo booleano inizializzata a false per gestire il loop del programma, infatti, lo switch delle scelte si
                                          //ripeterà fino a quando la variabile non diventa true (1).
    
    choice user_choice;                   // variabile di tipo choice, ovvero, enum definito precedentemente, utile per gestire le opzioni utente, come ricerca parole,
                                          // ricerca contrario di una frase, uscita dall'utilizzo del dizionario.
    
    
                                                            /* - Stampa inteerfaccia utente iniziale - */
                                                       /*--------------------------------------------------*/
    
    /* --------------------------------------------------------------------------------------------------------------------------------------------------------------------
     
     Stampa del logo (disegnato in ascii) attraverso la funzione definita in utility.h
     
     --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    pntlogo();
    
    /* --------------------------------------------------------------------------------------------------------------------------------------------------------------------
     
     Serie di printf, funzione utile per stampare a video (output) alcune informazioni.
     
     --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printf("\n\n\n\n      Benvenuto nel Dizionario dei contrari!\n");
    printf("<------------------------------------------------->\n");
    
    printf("\nPosso svolgere diverse funzioni: \n\n");
    printf("- Ricercare significato e contrario di una parola\n");
    printf("- trovare il contrario di una frase\n\n");
    
    printf("___________________________________________________\n\n");
    
    printf("Cosa vuoi fare?\n");
    printf("Digita:\n\n1 per ricercare significato e contrario di una parola\n2 per trovare il contrario di una frase\n3 per uscire\n\n\n");
    
                                                                 /* - Operazioni ripetute - */
                                                    /*--------------------------------------------------*/
    
    
    /* --------------------------------------------------------------------------------------------------------------------------------------------------------------------
     
     Al centro di questo programma risiede questo ciclo while, che si occupa di ripetere le operazioni in esso contenute finchè il software non riconosce che
     l'utente ha voglia di uscire da esso, ovvero, finchè le variabile would_exit è falsa, se quest'ultima è vera, allora l'utente ha selezionato la scelta numero 3,
     quindi la simulazione necessita di terminare.
     
     --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    while (!would_exit) {
        
        /* ------------------------------------------------------------------------------------------------------------------------------------------------------------
         
         Ogni volta che questo ciclo while si ripete l'utente dovrà decidere cosa fare, quindi inserire in input la sua scelta
         
         -------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        printf("inserisci la tua scelta qui: ");
        scanf("%d", &user_choice);
        
        /* ------------------------------------------------------------------------------------------------------------------------------------------------------------
         
         A questo punto user_choice sarà inizializzata attraverso input da utente, quindi viene sfruttato uno switch case per gestire le varie casistiche in funzione del
         valore assunto user_choice.
         
         -------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        switch (user_choice) {
            //caso in cui l'utente voglia ricercare il significato e i contrari di una parola
            case ricerca:
                
                printf("<------------------------------------------------->\n\n");
                printf("Hai scelto di cercare il significato e contrario di una parola!\n");
                printf("Inserisci la parola che vuoi cercare: \n");
                //rimuovo lo \n preso in input da scanf() e richiedo di inserie la parola di cui si vuole cercare significato e contrario
                cleanBuffer();
                scanf("%s", word_searched);
                
                //ricerco la parola (spiegazione dettagliata nell'header file di appartenenza)
                resword(word_searched);
                printf("<------------------------------------------------->\n\n");
                printf("vuoi fare altro? Digita:\n\n1 per ricercare significato e contrario di una parola\n2 per trovare il contrario di una frase\n3 per uscire\n\n\n");
                
                break;
            //caso in cui l'utente voglia ricercare il contrario di una frase
            case frase:
                
                printf("<------------------------------------------------->\n\n");
                printf("Hai scelto di cercare il contrario di una frase!\n");
                printf("Inserisci la frase di cui vuoi cercare il contrario: \n");
                
                //rimuovo lo \n preso in input da scanf() e richiedo di inserie la parola di cui si vuole cercare significato e contrario
                cleanBuffer();
                fgets(phrase, 4096, stdin);
                
                //trovo l'opposto di una frase (spiegazione dettagliata nell'header file di appartenenza)
                opphrase(phrase);
                printf("<------------------------------------------------->\n\n");
                printf("vuoi fare altro? Digita:\n\n1 per ricercare significato e contrario di una parola\n2 per trovare il contrario di una frase\n3 per uscire\n\n\n");
                
                break;
            //caso in cui l'utente voglia uscire dalla simulazione
            case exit:
                printf("\nGrazie per aver utilizzato il nostro dizionario dei contrari, alla prossima!\n\n");
                would_exit = true;
                break;
            //caso in cui l'utente abbia scelto di eseguire un'opzione non valida
            default:
                printf("\nhai inserito un opzione valida\n\n");
                break;
        }
    }
    return 0;
}
