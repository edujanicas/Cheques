#include "cheque.h"

Cheque criaCheque(int valor, long int refe, long int refb, long int refc)
{
    Cheque pcheque = (Cheque)malloc(sizeof(struct cheque));

    pcheque -> val = valor;
    pcheque -> part = refe;
    pcheque -> dest = refb;
    pcheque -> ref = refc;

    return pcheque;
} 

void apagaCheque(Cheque a)
{
	free(a);
}

void visitCheque(Cheque a)
{
	printf("%ld\n", a -> ref);
}
