//
//  main.c
//  Dizionario dei contrari
//
//  Created by Roberto Vecchio on 03/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#include <stdio.h>

#define MAX_PHRASE_LENGHT 300
#define MAX_WORD_LENGHT 15
#define MAX_MEANING_LENGHT 100
#define MAX_CONTRARY_NUMBERS 5
#define MAX_CONTRARY_LENGHT 20

typedef enum { false, true } bool;
typedef enum { ricerca = 1, frase } choice;
typedef struct word {
    char name[MAX_WORD_LENGHT];
    char meaning[MAX_MEANING_LENGHT];
    char contrary[MAX_CONTRARY_NUMBERS][MAX_CONTRARY_LENGHT];
} wordstruct;

static wordstruct dictionary_words[] = {
    { "abbassare", "calare, far scendere, spostare verso il basso", { "alzare", "far salire", "innalzare"} },
    { "abbellire", "adornare, ornare, rendere più bello, decorare, arricchire, impreziosire, guarnire, ingentilire", { "imbruttire", "deturpare","rovinare" } }
};

int main(int argc, const char * argv[]) {
    choice user_choice;
    char phrase[MAX_PHRASE_LENGHT];
    bool isDefaultCase = true;
    
    printf("\n============================================\n");
    printf("=                                          =\n");
    printf("=  Benvenuto nel dizionario dei contrari!  =\n");
    printf("=                                          =\n");
    printf("============================================\n");
    printf("\nPosso svolgere diverse funzioni: \n\n");
    printf("• Ricercare significato e contrario di una parola\n");
    printf("• Trovare il contrario di una frase\n\n");
    
    printf("============================================\n\n");
    
    printf("Cosa vuoi fare?\n");
    printf("Digita:\n\n1 per ricercare significato e contrario di una parola\n2 per trovare il contrario di una frase\n\n");
    
    printf("inserisci la tua scelta qui: ");
    scanf("%d", &user_choice);
    
    switch (user_choice) {
        case ricerca:
            printf("**Debug: dentro ricerca\n");
            //fai cose
            //isDefaultCase = false;
            break;
        case frase:
            printf("**Debug: dentro frase\n");
            printf("Hai scelto di cercare il contrario di una frase!\n");
            printf("Inserisci la frase di cui vuoi cercare il contrario: \n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            fgets(phrase, 4096, stdin);
            printf("**Debug: frase = %s\n", phrase);
            //fai altre cose
            //isDefaultCase = false;
            break;
        default:
            printf("**Debug: dentro default\n");
            isDefaultCase = true;
            break;
    }
    
    printf("**Debug: EXIT\n");
    return 0;
}
