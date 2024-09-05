#include "Iterator.h"
#include "LO.h"

#include <exception>
using namespace std;

Iterator::Iterator(const LO& lo) : lista(lo) {
	/* de adaugat */
	curent = lo.prim;
}

void Iterator::prim() {
	/* de adaugat */
	curent = lista.prim;
}

void Iterator::urmator() {
	/* de adaugat */
	if (!valid()) {
		throw exception();
	}
	curent = lista.urm[curent];
}

bool Iterator::valid() const {
	/* de adaugat */
	return (curent != -1);
}

TElement Iterator::element() const {
	/* de adaugat */
	if (!valid()) {
		throw exception();
	}
	return lista.e[curent];
}


