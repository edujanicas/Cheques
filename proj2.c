#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ST.c"
#include "queue.c"

#define CMD_LENGTH 30

static STlink clientes;
static Q cheques;

void adiciona_cheque(int valor,long int refe,long int refb,long int refc)
{
    Cliente emp, rec;
    Cheque a;
    a = criaCheque(valor,refe,refb,refc);

    QUEUEput(cheques, a);
    if (STsearch(clientes, refe) != NULL) {
        emp = (STsearch(clientes, refe));
        emp -> val_emi += valor;
        emp -> num_emi += 1;
    }
    else
        STinsert(&clientes, criaCliente(refe,1,valor,0,0));

    if (STsearch(clientes, refb) != NULL) {
        rec = (STsearch(clientes, refb)); 
        rec -> val_rec += valor;
        rec -> num_rec += 1;
    }
    else
        STinsert(&clientes, criaCliente(refb,0,0,1,valor));
}

void processa_cheque()
{
	Cliente emp, rec;
    Cheque a;
    int valor;
    long int part, dest;

    a = QUEUEget(cheques);
    valor = a -> val;
    part = a -> part;
    dest = a -> dest;

    emp = STsearch(clientes, part);
    rec = STsearch(clientes, dest);
    emp -> val_emi -= valor;
    emp -> num_emi -= 1; 
    rec -> val_rec -= valor;
    rec -> num_rec -= 1; 

    if (((emp -> num_emi) == 0) && ((emp -> num_rec) == 0)) {
    	STdelete(&clientes, key(emp));
    }

    if (((rec -> num_emi) == 0) && ((rec -> num_rec) == 0)) {
    	STdelete(&clientes, key(rec));
    }

}


void processa_cheque_ref(long refc)
{

}

void info_cheque(long ref)
{

}

void info_cliente(long ref)
{

}

void clientes_activos() /* imprime num de clientes ativos (ncl) */
{
    
}

void cheques_por_processar() /* imprime num (nch) e valor (vch) total de cheques por processar */
{

}

int main(){

    int valor;
    long int refe, refb, refc, ref;
    char command[CMD_LENGTH] = "";

    STinit(&clientes);
    cheques = QUEUEinit(10);
    scanf("%s",command);

    while(strcmp(command,"sair")){

        if(!strcmp(command,"cheque")){
            scanf("%d%ld%ld%ld",&valor,&refe,&refb,&refc);
            adiciona_cheque(valor,refe,refb,refc);
        }

        else if(!strcmp(command,"processa"))
            processa_cheque();

        else if(!strcmp(command,"processaR")){
            scanf("%ld",&refc);
            processa_cheque_ref(refc);
        }

        else if(!strcmp(command,"infocheque")){
            scanf("%ld",&ref);
            info_cheque(ref);
        }

        else if(!strcmp(command,"infocliente")){
            scanf("%ld",&ref);
            info_cliente(ref);
        }

        else if(!strcmp(command,"info"))
            STsort(clientes, infoCliente);

        else
            printf("ERROR: Unknown command\n");

        scanf("%s",command);
        
    }

    clientes_activos();
    cheques_por_processar();
    STfree(&clientes);

    return 0;
}
