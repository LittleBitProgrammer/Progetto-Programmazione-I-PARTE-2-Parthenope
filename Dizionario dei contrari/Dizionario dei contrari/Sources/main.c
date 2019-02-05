//
//  main.c
//  Dizionario dei contrari
//
//  Created by Roberto Vecchio on 03/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "../Headers/presenter.h"
#include "../Headers/utility.h"


#define MAX_PHRASE_LENGHT 150
#define MAX_WORD_LENGHT 15
#define MAX_MEANING_LENGHT 100
#define MAX_CONTRARY_NUMBERS 5
#define MAX_CONTRARY_LENGHT 20
#define SINGLE_SPACE " "


typedef enum { false, true } bool;
typedef enum { ricerca = 1, frase } choice;
typedef struct word {
    char name[MAX_WORD_LENGHT];
    char meaning[MAX_MEANING_LENGHT];
    char contrary[MAX_CONTRARY_NUMBERS][MAX_CONTRARY_LENGHT];
} wordstruct;

static wordstruct dictionary_words[] = {
    { "abbassare", "calare, far scendere, spostare verso il basso", { "alzare", "far salire", "innalzare"} },
    { "abbellire", "adornare, ornare, rendere più bello, decorare, arricchire, impreziosire, guarnire, ingentilire", { "imbruttire", "deturpare","rovinare" } },
    { "abbastanza", "sufficientemente, quanto basta, a sufficienza, bastantemnte", {"troppo poco", "insufficientemente", "scarsamente"} },
};


int main(int argc, const char * argv[]) {
    choice user_choice;
    char phrase[MAX_PHRASE_LENGHT];
    char phrase_two[MAX_PHRASE_LENGHT];
    char word_searched[MAX_WORD_LENGHT];
    char *token;
    char *array_of_strings[MAX_MEANING_LENGHT];
    bool isDefaultCase = true;
    bool isEqual;
    //divide the size in bytes of the array by the size in bytes of one element. The correct C syntax is:
    int struct_lenght = sizeof(dictionary_words) / sizeof(dictionary_words[0]);
    int for_index = 0;
    
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
            printf("Hai scelto di cercare il significato e contrario di una parola!\n");
            printf("Inserisci la parola che vuoi cercare: \n");
            cleanBuffer();
            scanf("%s", word_searched);
            
            int i;
            for (i = 0; i < struct_lenght; i++) {
                if (strcmp(word_searched, dictionary_words[i].name) == 0) {
                    printf("Il significato della parola cercata è: \n%s\n",dictionary_words[i].meaning);
                    printf("Il contrario della parola cercata è: \n");
                    int j;
                    for (j=0; j< 5; j++) {
                        printf("%s ", dictionary_words[i].contrary[j]);
                    }
                    printf("\n");
                }
            }
            break;
        case frase:
            printf("**Debug: dentro frase\n");
            printf("Hai scelto di cercare il contrario di una frase!\n");
            printf("Inserisci la frase di cui vuoi cercare il contrario: \n");
            cleanBuffer();
            fgets(phrase, 4096, stdin);
            printf("**Debug: frase = %s\n", phrase);
            token = strtok(phrase, SINGLE_SPACE);
            printf("============================================\n\n");
            
            while (token != NULL) {
                array_of_strings[for_index++] = token;
                token = strtok(NULL, SINGLE_SPACE);
                
            }
            
            int k;
            int l;
            for (k = 0; (k < MAX_PHRASE_LENGHT && array_of_strings[k] != NULL); k++){
                isEqual = false;
                for (l = 0; l < struct_lenght; l++) {
                    if (strcmp(array_of_strings[k], dictionary_words[l].name) == 0){
                        isEqual = true;
                        strcat(phrase_two, dictionary_words[l].contrary[0]);
                        strcat(phrase_two, " ");
                    }
                }
                printf("\n%d\n",isEqual);
                if (!isEqual) {
                    strcat(phrase_two, array_of_strings[k]);
                    strcat(phrase_two, " ");
                }
                
            }
            printf("%s", phrase_two );
            printf("\n");
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
