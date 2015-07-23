#ifndef _CLIENTE_
#define _CLIENTE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define key(A) (A != NULL ? A->ref : 0)
#define less(A, B) (A < B)
#define eq(A, B) (A == B)
#define NULLcliente NULL

typedef long int Key;
typedef struct cliente
{
    long int ref;
    int num_emi;
    int val_emi;
    int num_rec;
    int val_rec;
}* Cliente;

Cliente criaCliente(long int refe, int num_emi, int val_emi, int num_rec, int val_rec);
void apagaCliente(Cliente a);
void infoCliente(Cliente a);

#endif
