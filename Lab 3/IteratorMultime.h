#pragma once


class Multime;
class Nod;
typedef int TElem;
typedef Nod* PNod;//se defineste tipul PNod ca fiind adresa unui Nod

class IteratorMultime
{
	
private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorMultime(const Multime& m);

	//contine o referinta catre containerul pe care il itereaza
	const Multime& multime;
	/* aici e reprezentarea  specifica a iteratorului */

	//retine pozitia curenta in interiorul colectiei - adresa Nodului curent din lista asociata
	PNod curent;

public:
	friend class Multime;
	friend class Nod;

	//reseteaza pozitia iteratorului la inceputul containerului
	//
	//Complexitate: teta(1) - constanta
	void prim();

	//muta iteratorul in container
	//
	//Complexitate: teta(1) - constanta
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	//
	//Complexitate: teta(1) - constanta
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//
	//Complexitate: teta(1) - constanta
	TElem element() const;
};

