#include "cliente.h"

Cliente criaCliente(long int refe, int num_emi, int val_emi, int num_rec, int val_rec)
{
    Cliente pcliente = (Cliente)malloc(sizeof(struct cliente));

    pcliente -> val_rec = val_rec;
    pcliente -> num_rec = num_rec;
    pcliente -> val_emi = val_emi;
    pcliente -> num_emi = num_emi;
    pcliente -> ref = refe; 
    return pcliente;
} 

void apagaCliente(Cliente a)
{
	free(a);
}

void infoCliente(Cliente a)
{
	printf("%ld\n",a -> ref);
}
