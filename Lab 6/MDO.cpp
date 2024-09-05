#include "IteratorMDO.h"
#include "IteratorValori.h"
#include "MDO.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <exception>

using namespace std;

//functia care da hashCode-ul unuei element
int hashCode(TCheie e) {
	//pentru moment numarul e intreg
	return abs(e);
}

int MDO::d(TCheie ch) {
	//return hashCode(ch) % m;
	return ch % m;
	//return 1; //vom dispersa toate elementele in aceeasi locatia pentru a pastra ordinea
			  // in multidictionarul ordonat
}

MDO::MDO(Relatie r) {
	/* de adaugat */
	this->rel = r;
	this->m = MAX; //initializam cu o valoare predefinita

	for (int i = 0; i < m; i++) {
		l[i] = nullptr;
	}
}


void MDO::adauga(TCheie c, TValoare v) {
	/* de adaugat */
	int head = d(c); //locatia de dispersie a cheii

	TElem e = make_pair(c, v);
	
	PNod new_nod = new Nod(e, nullptr); //se creeaza un nod

	//Cazul 1: lista este goala
	if (l[head] == nullptr) {
		l[head] = new_nod;
		new_nod->next = nullptr; 
	}

	//Cazul 2: nodul trebuie adaugat la inceputul listei 
	else if (rel(c, l[head]->data.first)) {
		new_nod->next = l[head];
		l[head] = new_nod;
	}
	else {
		//Cazul 3: nodul trebuie adaugat inaintea unei pozitii
		PNod aux = l[head];
		PNod prec = aux;
		while (aux != nullptr && rel(c, aux->data.first) == 0) {
			prec = aux;
			aux = aux->next;
		}
		
		
		if(prec==aux) prec->next = new_nod;
		else {
			 prec->next = new_nod;
			 new_nod->next = aux;
			}
	}

}

vector<TValoare> MDO::cauta(TCheie c) {
	/* de adaugat */

	vector<TValoare> v = {};

	int poz = d(c); //cautam in lista inlantuita corespunzatoare cheii c
	if (poz < 0) return v; //cheile pot fi doar numere naturale
	auto elem = l[poz];

	while (elem != nullptr) {
		PNod p = elem;
		if (elem->data.first == c) v.push_back(p->element().second);
		elem = elem->next;
	}

	return v;
}

int MDO::cautaPoz(TCheie c, TValoare v) {
	int poz = d(c); //cautam in lista inlantuita corespunzatoare cheii c
	if (poz < 0) return v; //cheile pot fi doar numere naturale
	auto elem = l[poz];

	int poz_elem = 0;
	while (elem != nullptr) {
		PNod p = elem;
		if (elem->data.first == c && elem->data.second == v) {
			return poz_elem;
		}
		elem = elem->next;
		poz_elem++;
	}
	return -1;
}

bool MDO::sterge(TCheie c, TValoare v) {
	/* de adaugat */

	int poz_elem = cautaPoz(c, v);
	
	if (poz_elem == -1)
		return false;

	auto head = d(c);
	PNod aux1 = l[head];

	//daca elemetul este primul din lista
	if (poz_elem == 0) {
		l[head] = aux1->next;
		delete aux1;
		return true;
	}

	//daca elementul nu este primul din lista
	int i = 0;
	for (i = 0; i < poz_elem - 1; i++) {
		aux1 = aux1->next;
	}//aux1 pointeaza catre elementul poz-1
	
	PNod aux2 = aux1->next;
	aux1->next = aux2->next; //aux1 pointeaza catre elementul de pe poz+1

	delete aux2;
	return true;
}

int MDO::dim() const {
	/* de adaugat */
	int nrElem = 0;

	IteratorMDO it = this->iterator();
	it.prim();
	while (it.valid()) {
		nrElem++;
		it.urmator();
	}
	return nrElem;
}

bool MDO::vid() const {
	/* de adaugat */
	if (dim() == 0) {
		return true;
	}
	return false;
}

IteratorMDO MDO::iterator() const {
	return IteratorMDO(*this);
}

IteratorValori MDO::iteratorValori(TCheie ch) const {
	return IteratorValori(*this, ch);
}

MDO::~MDO() {
	/* de adaugat */
	//eliberam memoria alocata listelor
	for (int i = 0; i < m; i++) {
		//eliberam memoria alocata listei i
		while (l[i] != NULL) {
			PNod p = l[i];
			l[i] = l[i]->next;
			delete p;
		}
	}
}
