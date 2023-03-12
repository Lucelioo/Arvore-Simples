#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *esq;
    struct no *dir;
}NO;

NO* raiz = NULL;

NO* busca(int x, NO* aux){
    if(aux == NULL){
        return NULL; 
    }else if(x == aux->chave){
        return aux; 
    }else if(x<aux->chave){ 
        if(aux->esq != NULL){
            return busca(x, aux->esq);
        }else{
            return aux;
        }
    }else{
        if(aux->dir != NULL){
            return busca(x, aux->dir);
        }else{
            return aux; 
        }
    }
}


void add(int x){
    NO* resp = busca(x, raiz);
    if(resp == NULL || resp->chave != x){
        NO* novo = malloc (sizeof(NO));
        novo->chave = x;
        novo->esq = NULL;
        novo->dir = NULL;
        
        if(resp == NULL){ 
            raiz = novo;
        }else{
            if(x < resp->chave){
                resp->esq = novo;
            }else{
                resp->dir = novo;
            }
        }
    }else{
        printf("Add invalida. Chave duplicada");
    }
    
}


void in_ordem(NO* aux){
    if(aux != NULL){
        in_ordem(aux->esq);
        printf("%d\n",aux->chave);
        in_ordem(aux->dir);
    }
}


void pre_ordem(NO* aux){ 
    if(aux != NULL){
        printf("%d\n",aux->chave);
        in_ordem(aux->esq);
        in_ordem(aux->dir);
    }
}


void pos_ordem(NO* aux){
    if(aux != NULL){
        in_ordem(aux->esq);
        in_ordem(aux->dir);
        printf("%d\n",aux->chave);
    }
}


int main(){
    add(11);
    add(8);
    add(12);
    add(7);
    add(9);
    add(10);
    in_ordem(raiz);
    printf("\n");
    pre_ordem(raiz);
    printf("\n");
    pos_ordem(raiz);
    return 0;
}