#include "queue.h"

QUEUElink NEWQUEUE(Cheque item, QUEUElink next)      
{ 
    QUEUElink x = (QUEUElink)malloc(sizeof(struct QUEUEnode));
    x->item = item; 
    x->next = next;     
    return x;                         
}    

Q QUEUEinit(int maxN) 
{ 
    Q q = (Q)malloc(sizeof(struct queue));
    q->head = NULL;
    q->tail = NULL;
    return q; 
}

int QUEUEempty(Q q)
{ 
    return q->head == NULL; 
}

void QUEUEput(Q q, Cheque item)
{ 
    if (q->head == NULL) {
        q->tail = NEWQUEUE(item, q->head);
        q->head = q->tail;
        return;
    }
    q->tail->next = NEWQUEUE(item, q->tail->next);
    q->tail = q->tail->next;
}

Cheque QUEUEget(Q q)
{ 
    Cheque item = q -> head -> item;
    QUEUElink t = q -> head -> next; 
    free(q->head); 
    q->head = t;
    return item;
}
