#include <iostream>
#include "Nod.h"

typedef int TElem;

Nod::Nod(TElem data, Nod* next) {
	this->data = data;
	this->next = next;
}

TElem Nod::element() {
	return data;
}

Nod* Nod::urmator() {
	return next;
}
