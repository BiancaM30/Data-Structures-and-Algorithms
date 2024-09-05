#include "IteratorMDO.h"
#include "MDO.h"

IteratorMDO::IteratorMDO(const MDO& d) : dict(d) {
	/* de adaugat */

	pozCurent = 0;
	deplasare();
}

void IteratorMDO::prim() {
	/* de adaugat */
	pozCurent = 0;
	deplasare();
}

void IteratorMDO::urmator() {
	/* de adaugat */
	if (!valid()) {
		throw exception();
	}

	curent = curent->next;
	if (curent == NULL) {
		pozCurent = pozCurent + 1;
		deplasare();
	}
}

bool IteratorMDO::valid() const {
	/* de adaugat */
	return (pozCurent < dict.m && curent != NULL);
}

TElem IteratorMDO::element() const {
	/* de adaugat */
	if (!valid()) {
		throw exception();
	}

	return curent->data;
}


