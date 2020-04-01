/**************************************************************************************************************************/
/****************************************** CREATED BY : ******************************************************************/
/**************************************************************************************************************************/
/*********************************** - OUFRAD Mohamed                 *****************************************************/
/*********************************** - FERGOUCH Younes                *****************************************************/
/*********************************** - RAMI mohamed                   *****************************************************/
/*********************************** - AIT OUAKRIM Abdessamad         *****************************************************/
/*********************************** - ESSADIK Lahcen                 *****************************************************/
/**************************************************************************************************************************/
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


/**********************************Les Structure des Listes **************************************************/
struct MaillonList{
	int e;
	struct MaillonList *suivant;
};
typedef struct MaillonList MaillonList;

struct List {
	MaillonList *tete;
	MaillonList *queue;
};
typedef struct List list;


/*************************************Les fonction des Listes *************************************************/
list* CreerList(){
	list *L;
	L=new list;
	L->tete=NULL;
	L->queue=NULL;
	return L;
}

bool ListVide(list* L){
	return (L->tete == NULL);
}


int LongList(list* L){
	MaillonList *p;
	int i=0;
	p = L->tete;
	while(p != NULL){
		p=p->suivant;
		i++;
	}
	return i;
}


MaillonList* CreerMaillonList(int e){
	MaillonList *m;
	m=new MaillonList;
	m->e=e;
	m->suivant=NULL;
	return m;
}

bool inserTete(list *L, int e){
	MaillonList* m = CreerMaillonList(e);
    MaillonList* t;
	if (m == NULL) return false;
	t = L->tete;
	L->tete = m;
	m->suivant = t;
	if (LongList(L) == 1) L->queue = L->tete;
	return true;
}

bool inserQueue(list *L, int e){
	if (ListVide(L))
	{
		L->tete = CreerMaillonList(e);
		L->queue = L->tete;
	}else{
		MaillonList* m = CreerMaillonList(e);
		MaillonList* t;
		if (m == NULL) return false; 
		t = L->queue;
		t->suivant = m;
		L->queue = m;
	}
	return true;
}

bool inserMaillonList(list *L , int e  , int position){
	MaillonList *t,*p;
	p = CreerMaillonList(e);
	if(position < 1 || position > LongList(L)+1)  return false;

	if(position == 1)
	{ 
 	    inserTete(L,e);
	    return true;
	}
	if(position == LongList(L)+1){
		inserQueue(L,e);
		return true;
	}
	t = L->tete; 
	int i=1;
	while(i != position-1)
	{
	    t = t->suivant;
		i++;	
	}
		p->suivant = t->suivant;
		t->suivant = p;
		return true;
}

bool supprimerTete(list *L){
	MaillonList *t;
	if(ListVide(L)) return false;
	t=L->tete;
	L->tete=t->suivant;
	free(t);
	return true;
}

bool supprimerQueue(list *L){
	MaillonList *t,*p;	
	if(ListVide(L)) return false;
	if(LongList(L) == 1) {
		supprimerTete(L);
		return true;
	}
	p=L->tete;
	while(p->suivant != NULL){
		t = p;
		p = p->suivant;	
	}
	L->queue = t;
	t->suivant = NULL;
	free(p);
	return true;
}

bool supprimerMaillonList(list *L, int position){
	MaillonList *t,*P;
	if(position < 1 || position > LongList(L) )  return false;	
	
	if(position == 1)
	{
		supprimerTete(L);
		return true;
	}
	int i=1;
	t=L->tete;
	while (i != position)
	{
		P=t;
		t=t->suivant;
		i++;
	}
	P->suivant = t->suivant;
	free(t);
	return true;
	
}

int rangElement(list* L, int valeur){
	MaillonList *m;
	if(!ListVide(L)){
		m = L->tete ;
		int i=1;
		while(m != NULL){
			if((m->e) == valeur) return i;	
			i++;
			m = m->suivant;
		}
	}
	return -1;
}

void AfficheList(list *L){
	MaillonList *m;
	if(ListVide(L)) cout<<"[---] : La liste est vide !!"<<endl;
	else{
	m = L->tete;
	cout<<"[  ";
    while(m->suivant != NULL)
	{
		printf("%d->",m->e);
		m=m->suivant;
	}
	cout<<L->queue->e<<"->NULL  ]"<<endl;  	
	} 
}

