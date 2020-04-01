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

/**********************************Les Structure des File **************************************************/

struct maillon
{
	int e;
	struct maillon *Psuivant;
};
typedef struct maillon maillonFile;

struct file
{
	maillonFile *Ptete;
	maillonFile *Pqueue;
};
typedef struct file File;

/*************************************Les fonction des File *************************************************/

File* CreerFile(){
	File *F;
	F=new File;
	F->Ptete=NULL;
	F->Pqueue=NULL;
	return F;
}

bool FileVide(File* F){
	return(F->Ptete == NULL);
}

int Tete(File* f){
  if(!FileVide(f))
    return (f->Ptete)->e;	
}

maillonFile* CreerMaillon(int valeur){
  maillonFile *M = new maillonFile;
  M->e=valeur;
  M->Psuivant=NULL;
  return M;
}

int longFile(File* f){
	maillonFile *p;
	int i=0;
	p = f->Ptete;
	while(p != NULL){
		p = p->Psuivant;
		i++;
	}
	return i;
}

bool Emfiler(File *f,int Valeur){
	maillonFile *pm=CreerMaillon(Valeur);
    if(FileVide(f))	f->Pqueue = f->Ptete =pm;	
	else
	{
		(f->Pqueue)->Psuivant = pm;
		f->Pqueue = pm;
	}
	return true;
}

bool Defiler(File *f){
	if(FileVide(f))   return false; 
	
	maillonFile *m;
	m = f->Ptete;
	f->Ptete = m->Psuivant;
	free(m);	
}

void AfficheFile(File* f){
	maillonFile *m = f->Ptete;
	if(FileVide(f)) cout<<"[---] : La file est vide !!"<<endl;
	else{
	m = f->Ptete;
	cout<<"[  ";
    while(m->Psuivant != NULL)
	{
		printf("%d->",m->e);
		m = m->Psuivant;
	}
	cout<<f->Pqueue->e<<"->NULL  ]"<<endl;  	
	}  
}

