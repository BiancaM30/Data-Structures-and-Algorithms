#pragma once

#include "MDO.h"
#include "Nod.h"
typedef Nod* PNod; //se defineste tipul PNod ca fiind adresa unui Nod

class IteratorValori {
	friend class MDO;
	friend class Nod;

private:

	/*d : multidictionar
	 pozCurent : Intrg
	 curent : | nod
	k : TCheie
	*/

	//pre : i: IteratorValori, d : multidictionar
	//post : deplaseaza iteratorul pe prima pozitie din lista inlantuita corespunzatoare locatiei de dispersie pe care se regaseste cheia
	//daca cheia nu exista in multidictionar arunca exceptie
	// 
	//PSEUDOCOD
	/*
	Subalgoritm creeaza(i, d, k)

	i.dict<-d
	i.k<-k
	i.pozCurent <-dispersie(k)
	curent <-dict.l[pozCurent]
	catTimp(i.curent != NIL) ^ (i.curent.data.first != k) executa
		i.curent < -[i.curent].next
	sfarsit CatTimp

	daca(!i.valid()) atunci
		@arunca exceptie
	sfarsitDaca

	sfarsit Subalgoritm*/
    //
	//Complexitate O(n) - liniara
	//Caz favorabil: teta(1) - gasim cheia pe prima pozitie
	//Caz defavorabil: teta(n)
	IteratorValori(const MDO& dictionar, TCheie k);

	//contine o referinta catre containerul pe care il itereaza
	const MDO& dict;
	TCheie k;

	/* aici e reprezentarea  specifica a iteratorului */
	int pozCurent; //pozitia curenta pozCurent din tabela (indica lista inlantuita iterata)
	PNod curent; //adresa unui nod curent din lista inlantuita de la pozitia pozCurent 


public:

	//pre : i: IteratorValori, d : multidictionar
	//post : deplaseaza iteratorul pe prima pozitie din lista inlantuita corespunzatoare locatiei de dispersie pe care se regaseste cheia
	//daca cheia nu exista in multidictionar arunca exceptie
	// 
	//PSEUDOCOD
	/*Subalgoritm prim(i, d, k)

	i.pozCurent < -dispersie(k)
	curent < -dict.l[pozCurent]
	catTimp(i.curent != NIL) ^ (i.curent.data.first != k) executa
		i.curent < -[i.curent].next
	sfarsit CatTimp

	daca(!i.valid()) atunci
		arunca exceptie
	sfarsit CatTimp

	sfarsit Subalgoritm*/
	//
	//Complexitate O(n) - liniara
	//Caz favorabil: teta(1) - gasim cheia pe prima pozitie
	//Caz defavorabil: teta(n)
	void prim();

	
	//pre : i: IteratorValori, d : multidictionar
	//post: muta iteratorul in container
	//arunca exceptie daca iteratorul nu e valid
	// 
	// 
	//PSEUDOCOD
	/*Subalgoritm urmator(i,d)
	
	daca(!i.valid()) atunci
		arunca exceptie
	sfarsitDaca
	i.curent < -[i.curent].next

	sfarsit Subalgoritm*/
	//
	//Complexitate: O(1) - constanta
	void urmator();

	
	//pre : i: IteratorValori, d : multidictionar
	//post: verifica daca iteratorul e valid (indica un element al containerului)
	// 
	//PSEUDOCOD
	/*
	* subalgoritm valid(i,d)
			returneaza ((i.pozCurent<dict.m) ^ (curent != NIL) ^ ([i.curent].data.first == k))
	sfarsitSubalgoritm
	*/
	//
	//Complexitate: teta(1) - constanta
	bool valid() const;

	
	//pre : i: IteratorValori, d : multidictionar
	//post: returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	//
	//PSEUDOCOD
	/*Subalgoritm element(i,d)

		daca(!i.valid()) atunci
			arunca exceptie
		sfarsitDaca

		returneaza [i.curent].data.second

	sfarsit Subalgoritm*/

	//Complexitate: teta(1) - constanta
	TValoare element() const;
};

