#include "Iterator.h"
#include "DO.h"
#include <iostream>

using namespace std;

Iterator::Iterator(const DO& d) : dict(d) {
	/* de adaugat */
	curent = dict.index_rad;

	
	//se adauga in stiva ramura stanga a elementului curent
	while (curent != NULL_TVALOARE) {
		stiva.push(curent);
		curent = dict.stanga[curent];
	}
	
	
	if (!stiva.empty()) {
		curent = stiva.top();
		//se sterge nodul din varful stivei
		stiva.pop();
	}
}


void Iterator::prim() {
	/* de adaugat */
	
}

void Iterator::urmator() {
	/* de adaugat */
	
	if (!valid()) {
		throw exception();
	}

	if (dict.dreapta[curent] != NULL_TVALOARE) {
		curent = dict.dreapta[curent];
		int curent_anterior = curent;
		while (curent != NULL_TVALOARE) {
			//se adauga in stiva ramura stanga a elementului curent
			stiva.push(curent);
			curent_anterior = curent;
			curent = dict.stanga[curent];
		}
		curent = curent_anterior;
	}
	 if (!stiva.empty()) {
		//se sterge nodul din varful stivei
		 curent = stiva.top();
		 stiva.pop();
		
	}
	else
	{
		curent = NULL_TVALOARE;
	}
}

bool Iterator::valid() const {
	/* de adaugat */
	if (curent != NULL_TVALOARE) {
		return true;
	}
	return false;
}

TElem Iterator::element() const {
	/* de adaugat */

	if (!valid()) {
		throw exception();
	}

	return dict.e[curent];

}
