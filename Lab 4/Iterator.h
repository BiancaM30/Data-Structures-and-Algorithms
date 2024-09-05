#pragma once

#include "LO.h"

class LO;

class Iterator {
	friend class LO;
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	Iterator(const LO& lo);

	//contine o referinta catre containerul pe care il itereaza
	const LO& lista;

	/* aici e reprezentarea  specifica a iteratorului */
	int curent;

public:
	friend class LO;
   
	//reseteaza pozitia iteratorului la inceputul containerului
	// 	   
	//Complexitate: teta(1) - constanta
	void prim();

	//Complexitate: teta(1) - constanta
		 
	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	//
	//Complexitate: teta(1) - constanta
	void urmator();

	 
	//verifica daca iteratorul e valid (indica un element al containerului)
	//
	//Complexitate: teta(1) - constanta
	bool valid() const;

	 
	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	//
	//Complexitate: teta(1) - constanta
	TElement element() const;
};


