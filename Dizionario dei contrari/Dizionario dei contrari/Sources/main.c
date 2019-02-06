//
//  main.c
//  Dizionario dei contrari
//
//  Created by Roberto Vecchio on 03/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "../Headers/utility.h"
#include "../Headers/dictionarylib.h"

typedef enum { ricerca = 1, frase } choice;

int main(int argc, const char * argv[]) {
    
    choice user_choice;
    
    char word_searched[MAX_WORD_LENGHT];
    char phrase[MAX_PHRASE_LENGHT];
    
    printf("\n============================================\n");
    printf("=                                          =\n");
    printf("=  Benvenuto nel Dizionario dei contrari!  =\n");
    printf("=                                          =");
    printf("\n============================================\n");
    
    printf("\nPosso svolgere diverse funzioni: \n\n");
    printf("- Ricercare significato e contrario di una parola\n");
    printf("- trovare il contrario di una frase\n\n");
    
    printf("--------------------------------------------\n\n");
    
    printf("Cosa vuoi fare?\n");
    printf("Digita:\n\n1 per ricercare significato e contrario di una parola\n2 per trovare il contrario di una frase\n\n");
    
    printf("inserisci la tua scelta qui: ");
    scanf("%d", &user_choice);
    
    switch (user_choice) {
        case ricerca:
            
            printf("Hai scelto di cercare il significato e contrario di una parola!\n");
            printf("Inserisci la parola che vuoi cercare: \n");
            
            cleanBuffer();
            scanf("%s", word_searched);
            
            resword(word_searched);
            
            break;
        case frase:
            
            printf("Hai scelto di cercare il contrario di una frase!\n");
            printf("Inserisci la frase di cui vuoi cercare il contrario: \n");
            
            cleanBuffer();
            fgets(phrase, 4096, stdin);
            
            opphrase(phrase);
            break;
        default:
            printf("**Debug: dentro default\n");
            break;
    }
    
    return 0;
}
