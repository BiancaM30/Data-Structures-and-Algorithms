#pragma once

#include "DO.h"
#include <stack>


class Iterator {
	friend class DO;
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	//
	//Complexitate: teta(n) liniara
	Iterator(const DO& dictionar);

	//contine o referinta catre containerul pe care il itereaza
	const DO& dict;

	/* aici e reprezentarea specifica a iteratorului */
	int curent; //pozitia curenta

	std::stack <int> stiva;

public:

	//reseteaza pozitia iteratorului la inceputul containerului
	void prim();

	//muta iteratorul in container
	//arunca exceptie daca iteratorul nu e valid
	//
	//Complexitate: teta(n) - liniara
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

