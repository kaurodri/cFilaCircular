//ED1 BSI 2024
//
//Primeiro trabalho extra:
//  Com base nas instrucoes apresentadas em aula e no codigo da fila simples implemente uma fila circular.
//  Envie apenas o codigo fonte, em um arquivo compactado ou arquivos individuais

//Circular Queue
//variação da linear, onde o último elemento está conectado de volta ao primeiro, formando um circulo
//isso resolve o problema de desperdício de espaço na fila linear
//
//Entrega: 05.09.2024

#include <stdlib.h>
#include <stdio.h>

typedef unsigned int uint;

typedef struct Elemento{
    struct  Elemento *ant;
    int    data;
} Elemento; 

typedef struct Fila{
    struct Elemento *cab;
    struct Elemento *rab;
    uint tamanho;
} Fila;

//--------------------------------------------
Fila *criaFila(){
    Fila *f = (Fila*) malloc( sizeof( Fila ) );

    f->tamanho = 0;
    f->cab = NULL;
    f->rab = NULL;
    
    return f;
}
//--------------------------------------------
int ehVazia( Fila *pt )
{
    if ( pt != NULL ) //a ED existe
        if ( pt->tamanho > 0 )
            return 0;
        else
            return 1;    
}
//--------------------------------------------
void insereFila( Fila *f, int data )
{
    Elemento *e = ( Elemento* )malloc( sizeof( Elemento ) );
    e->ant = NULL;
    e->data = data;

    if( ehVazia( f ) ){
        //caso A - A fila estah vazia
        f->cab = e;
        f->rab = e;

        //alteração
        e->ant = e; //ultimo elemento apontado para ele mesmo 

    } else {
        //caso B - A fila nao estah vazia

        //alteração
        e->ant = f->cab; //elemento aponta para cabeça
        f->rab->ant = e; //rabo que aponta para elemento
        f->rab = e; //rabo recebe elemento
    }
    f->tamanho++;
}
//--------------------------------------------
int removeDaFila( Fila *f ){
    if( ! ehVazia( f ) )
    {
        Elemento *tmp = f->cab;
        if( f->tamanho == 1 )
        {
            f->cab = NULL;
            f->rab = NULL;
        }else{
            f->cab = f->cab->ant;

            //alteração - mantém o ciclo
            f->rab->ant = f->cab; //rabo que recebe cabeça
        }
        f->tamanho--;
        int tmpd = tmp->data;
        free( tmp );
        return tmpd;
    }
}