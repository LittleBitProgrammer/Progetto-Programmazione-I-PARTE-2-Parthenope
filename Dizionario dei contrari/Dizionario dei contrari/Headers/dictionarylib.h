//
//  dictionarylib.h
//  Dizionario dei contrari
//
//  Created by Roberto Vecchio on 05/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#ifndef dictionarylib_h
#define dictionarylib_h

/*    - definizione di costanti -    */

#define NUMBERS_OF_LETTERS 26
#define MAX_WORD_FOR_LETTER 5
#define MAX_PHRASE_LENGHT 150
#define MAX_WORD_LENGHT 15
#define MAX_MEANING_LENGHT 100
#define MAX_CONTRARY_NUMBERS 5
#define MAX_CONTRARY_LENGHT 20

#include <stdio.h>
#include <string.h>

/*    - definizione di nuovi tipi -    */

typedef enum { a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z } alphabet_index;

typedef struct word {
    char name[MAX_WORD_LENGHT];
    char meaning[MAX_MEANING_LENGHT];
    char contrary[MAX_CONTRARY_NUMBERS][MAX_CONTRARY_LENGHT];
} wordstruct;


/*    - prototipi di funzione -    */

void resword(char *);
void opphrase(char *);
int arrcount(wordstruct *);
alphabet_index returnLetIndex(char letter);


#endif /* dictionarylib_h */
