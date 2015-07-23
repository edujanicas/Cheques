#ifndef _ST_
#define _ST_

#include <stdio.h>
#include <stdlib.h>
#include "cliente.c"

typedef struct STnode* STlink;
struct STnode 
{ 
    Cliente item; 
    STlink l, r;
    int N; 
};

void STinit(STlink*);
int STcount(STlink);
Cliente STsearch(STlink, Key);
void STinsert(STlink*, Cliente);
void STdelete(STlink*, Key);
void STsort(STlink, void (*visit)(Cliente));
void STfree(STlink*);

#endif
