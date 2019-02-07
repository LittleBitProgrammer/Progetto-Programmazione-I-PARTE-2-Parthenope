//
//  utility.c
//  Dizionario dei contrari
//
//  Created by Roberto Vecchio on 05/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#include "utility.h"
#include <stdio.h>

void cleanBuffer(void){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
void pntlogo(){
    printf("                                  _.             \n                         _.-----'' `\\             \n             __..-----'''            `.\n            <            `\\.           '\\\n            :.              `.           `\\\n             `:.              `.           `-.\n               `:\\ N  o         `.            `+.\n                 `:. A  s  i      `.  __.===::::;)\n .         r   I   `: c       ___.__>'::::::a:f/'\n       C          A   `.  _,===:::=-'-=-\"\"\"\"\n   i      d  t         '-/:::''\n                         ''\n           y");
}
