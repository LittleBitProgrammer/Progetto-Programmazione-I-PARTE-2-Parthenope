//
//  utility.c
//  Dizionario dei contrari
//
//  Created by Roberto Vecchio on 05/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#include "utility.h"

void cleanBuffer(void){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
