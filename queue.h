#ifndef _QUEUE_
#define _QUEUE_

#include "cheque.c"
#include <stdlib.h>

typedef struct queue *Q;
typedef struct QUEUEnode* QUEUElink;
struct QUEUEnode 
{ 
    Cheque item; 
    QUEUElink next; 
};
struct queue { QUEUElink head; QUEUElink tail; };

Q    QUEUEinit(int maxN);
int QUEUEempty(Q);
void QUEUEput(Q, Cheque);
Cheque QUEUEget(Q);

#endif
