#include "Nod.h"

Nod::Nod(TElem data, Nod* next) {
	this->data = data;
	this->next = next;
}

TElem Nod::element() {
	return this->data;
}

Nod* Nod::urmator() {
	return this->next;
}

