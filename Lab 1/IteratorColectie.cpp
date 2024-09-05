#include "IteratorColectie.h"
#include "Colectie.h"
#include <iostream>
using namespace std;


IteratorColectie::IteratorColectie(const Colectie& _c) : col(_c) {
	/* de adaugat */
	curent = 0; 
	frecv_curent = col.e[0];
	nr_elem = 0;
	
}

void IteratorColectie::prim() {
	/* de adaugat */
	curent = 0;  
	frecv_curent = col.e[0];
	nr_elem = 0;
}


void IteratorColectie::urmator() {
	/* de adaugat */
	
	frecv_curent = frecv_curent - 1;
	 //daca frecventa numarului curent a ajuns la 0 trebuie sa trecem la urmatorul element nenul
	if (frecv_curent == 0) {
		curent++;
		while (col.e[curent] == 0 && curent < col.maxi - col.mini + 1)
			curent++;
		frecv_curent = col.e[curent];
	}
}


bool IteratorColectie::valid() const {
	/* de adaugat */
	return (nr_elem < col.dim() + 1 && curent < col.maxi - col.mini + 1); //verifica daca iteratorul indica spre un element al vectorului

}



TElem IteratorColectie::element() {
	/* de adaugat */
	
	
	nr_elem++;
	return col.mini + curent; //elementul curent
		
}
