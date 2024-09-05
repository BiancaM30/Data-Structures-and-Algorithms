#pragma once

#include "Colectie.h"

class Colectie;
typedef int TElem;

class IteratorColectie
{
	friend class Colectie;
	//Iteratorul va itera prin elementele nenule din vectorl de frecvente

private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container

	IteratorColectie(const Colectie& c); //constructor

	//contine o referinta catre containerul pe care il itereaza
	const Colectie& col;
	/* aici e reprezentarea specifica a iteratorului*/

	int curent;  //pozitia curenta in iterator
	int frecv_curent;
	int nr_elem;

public:


	//reseteaza pozitia iteratorului la inceputul containerului
	// 	   
	//Complexitate: teta(1) - constanta
	void prim();

	//muta iteratorul in container
	//
	//Complexitate: teta(n) - liniara
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	// 	   
	//Complexitate: teta(1) - constanta
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	// 
	//Complexitate: teta(1) - constanta
	TElem element();
};