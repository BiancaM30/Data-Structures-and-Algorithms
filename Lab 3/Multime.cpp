#include "Multime.h"
#include "IteratorMultime.h"
#include "Nod.h"

#include <iostream>

typedef Nod* PNod;

Multime::Multime() {
	/* de adaugat */
	head = nullptr;
	nr_elem = 0;
}


bool Multime::adauga(TElem elem) {
	/* de adaugat */
	
	if (cauta(elem) == true) //verificam daca elementul exista deja in multime
		return false;

	PNod aux = new Nod(elem, nullptr);
	aux->next = head;
	head = aux;

	nr_elem++;
	return true;
}


bool Multime::sterge(TElem elem) {
	/* de adaugat */
	if (cauta(elem) == false) //verificam daca elementul exista deja in multime
		return false;
	else {
		int poz_elem = cautaPoz(elem); //cautam pozitia pe care se afla elementul
		PNod aux1 = head;
		if (poz_elem == 0) {
			head = aux1->next;
			delete aux1;
			nr_elem --;
			return true;
		}
		
		int i = 0;
		for (i = 0; i < poz_elem - 1; i++) {
			aux1 = aux1->next; 
		}//aux1 pointeaza catre elementul poz-1

		PNod aux2 = aux1->next;
		aux1->next = aux2->next; //aux1 pointeaza catre elementul de pe poz+1

		nr_elem--;
		delete aux2;
		return true;
	} 

}


bool Multime::cauta(TElem elem) const {
	/* de adaugat */
	IteratorMultime im = this->iterator();
	im.prim();
	while (im.valid()) {
		TElem e = im.element();
		if (e == elem)
			return true;
		im.urmator();
	}
	return false;
}

int Multime::cautaPoz(TElem elem) const {
	/* de adaugat */
	int poz = 0;
	IteratorMultime im = this->iterator();
	im.prim();
	while (im.valid()) {
		TElem e = im.element();
		if (e == elem)
			return poz;
		poz++;
		im.urmator();
	}
}


int Multime::dim() const {
	/* de adaugat */
	return nr_elem;
}

bool Multime::vida() const {
	/* de adaugat */
	if (nr_elem == 0)
		return true;
	return false;
}

int Multime::diferentaMaxMin() const {
	if (vida() == true)  //verificam daca multimea este vida
		return -1;

	int mini = 0, maxi = 0;
	TElem e;

	IteratorMultime im = this->iterator();
	im.prim();
	if (im.valid()) {
		e = im.element();
		//initializam minimul si maximul cu primul element din multime
		mini = e;
		maxi = e; 
		im.urmator();
	}

	//parcurgem elementele pana la capat si comparam cu minimul si maximul
	while (im.valid()) {
		e = im.element();
		if (e < mini)
			mini = e;
		if (e > maxi)
			maxi = e;
		im.urmator();
	}
	return maxi - mini;
}

Multime::~Multime() {
	/* de adaugat */
	//se elibereaza memoria alocata nodurilor listei
	while (head != nullptr) {
		PNod p = head;
		head = head->next;
		delete p;
	}
}



IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

