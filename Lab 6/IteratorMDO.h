#pragma once

#include "MDO.h"
#include "Nod.h"
typedef Nod* PNod; //se defineste tipul PNod ca fiind adresa unui Nod

class IteratorMDO {
	friend class MDO;
	friend class Nod;

private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorMDO(const MDO& dictionar);

	//contine o referinta catre containerul pe care il itereaza
	const MDO& dict;
	/* aici e reprezentarea  specifica a iteratorului */
	int pozCurent; //pozitia curenta pozCurent din tabela (indica lista inlantuita iterata)
	PNod curent; //adresa unui nod curent din lista inlantuita de la pozitia pozCurent 


	//daca lista de la locatia curenta pozCurent a fost iterata pana la final, deplasam pozCurent la 
	//urmatoarea locatie din tabela care contine o lista nevida si pozitionam curent pe prima pozitie din aceasta
	//
	//Complexitate: O(m) - liniara
	//Caz favorabil: teta(1) - constanta, cand adresa listei cautate se afla pe urmatoarea pozitie dupa cea curenta
	//Caz defavorabil: teta(m) - liniara, cand nu mai exista nicio lista nevida de iterat
	//Caz mediu: teta(m) - liniara
	void deplasare() {
		while (pozCurent < dict.m && dict.l[pozCurent] == NULL)
		{
			pozCurent++;
		}
		if (pozCurent < dict.m) { //daca nu am ajuns la final
			curent = dict.l[pozCurent]; //mergem la adresa unei noi listei inlanuite nevide
		}
	}

public:


	//reseteaza pozitia iteratorului la inceputul containerului
	//
	//Complexitate: O(m) - liniara (aceeasi complexitate ca la functia de deplasare)
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	//
	//Complexitate: O(m) - liniara (aceeasi complexitate ca la functia de deplasare)
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	//
	//Complexitate: teta(1) - constanta
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	//
	//Complexitate: teta(1) - constanta
	TElem element() const;
};

