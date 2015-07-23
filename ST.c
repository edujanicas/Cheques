#include "ST.h"

STlink NEWST(Cliente item, STlink l, STlink r)
{ 
    STlink x = (STlink)malloc(sizeof(struct STnode)); 
    x->item = item; 
    x->l = l; 
    x->r = r; 
    return x;
}

void STinit(STlink*sthead)
{
    *sthead = NULL;
}

Cliente searchR(STlink h, Key v) 
{ 
    if (h == NULL) 
        return NULLcliente;
    if (eq(v, key(h->item))) 
        return h -> item;
    if (less(v, key(h->item))) 
        return searchR(h->l, v);
    else 
        return searchR(h->r, v); 
} 

Cliente STsearch(STlink sthead, Key v)
{
	return searchR(sthead, v);
}

STlink insertR(STlink h, Cliente item)
{ 
    if (h == NULL)
        return NEWST(item, NULL, NULL);
    if (less(key(item), key(h->item)))
        h->l = insertR(h->l, item);
    else 
        h->r = insertR(h->r, item); 
    return h;
}

void STinsert(STlink*sthead, Cliente item)
{
	*sthead = insertR(*sthead, item);
}

STlink max(STlink h) {
    if (h==NULL || h->r==NULL) return h;
    else return max(h->r);
}

STlink deleteR(STlink h, Key k) 
{
    if (h == NULL) 
        return h;
    else if (less(k, key(h->item))) 
        h->l=deleteR(h->l,k);
    else if (less(key(h->item), k)) 
        h->r=deleteR(h->r,k) ;
    else {
        if (h->l != NULL && h->r !=NULL){
            STlink aux = max(h->l);
            {Cliente x; x = h->item; h->item = aux->item; aux->item = x; }
            h->l= deleteR(h->l, key(aux->item));
        }
        else {
            STlink aux = h;
            if ( h->l == NULL && h->r == NULL ) h=NULL;
            else if (h->l==NULL) h=h->r;
            else h=h->l;
            apagaCliente(aux->item);
            free(aux);
        }
    }
    return h;
}

void STdelete(STlink*sthead, Key v)
{
	*sthead = deleteR(*sthead, v);
}

int count(STlink h) {
    if (h==NULL) 
        return 0;
    else
        return STcount(h->r) + STcount(h->l) + 1;
}

int STcount(STlink sthead)
{
    return count(sthead);
}

void sortR(STlink h, void (*visit)(Cliente))
{
    if (h == NULL)
        return;
    sortR(h->l, visit);
    visit(h -> item);
    sortR(h->r, visit);
}

void STsort(STlink sthead, void (*visit)(Cliente))
{
	sortR(sthead, visit);
}

STlink freeR(STlink h)
{
    if (h==NULL)
        return h;
    h->l=freeR(h->l);
    h->r=freeR(h->r);
    return deleteR(h,key(h->item));
}

void STfree(STlink* sthead)
{
    *sthead=freeR(*sthead);
}

