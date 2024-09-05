#include "IteratorValori.h"
#include "MDO.h"

int dispersie(TCheie ch) {
	//return hashCode(ch) % m;
	//return ch % m;
	return 1; //vom dispersa toate elementele in aceeasi locatia pentru a pastra ordinea
			  // in multidictionarul ordonat
}

IteratorValori::IteratorValori(const MDO& dictionar, TCheie k) : dict(dictionar), k{k}{
	/* de adaugat */
	
	pozCurent = dispersie(k);

	curent = dict.l[pozCurent];
	while (curent != nullptr && curent->data.first != k) {
		curent = curent->next;
	}

	if(!valid()){
		throw exception();
	}
	
}



void IteratorValori::prim() {
	/* de adaugat */
	
	pozCurent = dispersie(k);

	curent = dict.l[pozCurent];
	while (curent != nullptr && curent->data.first != k) {
		curent = curent->next;
	}

	if (!valid()) {
		throw exception();
	}
}

void IteratorValori::urmator() {
	/* de adaugat */
	if (!valid()) {
		throw exception();
	}

	curent = curent->next;
}


bool IteratorValori::valid() const {
	/* de adaugat */
	return (pozCurent < dict.m && curent != nullptr && curent->data.first == k);
}


TValoare IteratorValori::element() const {
	/* de adaugat */
	if (!valid()) {
		throw exception();
	}

	return curent->data.second;
}


