#ifndef _CHEQUE_
#define _CHEQUE_

#include <stdio.h>
#include <stdlib.h>

#define key(A) (A != NULL ? A->ref : 0)
#define less(A, B) (A < B)
#define eq(A, B) (A == B)
#define NULLcheque NULL

typedef struct cheque
{
    long int ref;
    int val;
    long int part;
    long int dest;
} *Cheque;

Cheque criaCheque(int valor, long int refe, long int refb, long int refc);
void apagaCheque(Cheque a);
void visitCheque(Cheque a);

#endif

