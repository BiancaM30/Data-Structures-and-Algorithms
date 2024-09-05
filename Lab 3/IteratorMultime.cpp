#include "IteratorMultime.h"
#include "Multime.h"
#include "Nod.h"

IteratorMultime::IteratorMultime(const Multime& m) : multime(m) {
	/* de adaugat */
	curent = m.head;
}


void IteratorMultime::prim() {
	/* de adaugat */
	curent = multime.head;
}


void IteratorMultime::urmator() {
	/* de adaugat */
		curent = curent->urmator();
		
}


TElem IteratorMultime::element() const {
	/* de adaugat */
	return curent->element();
}

bool IteratorMultime::valid() const {
	/* de adaugat */
	return curent != nullptr;
}
