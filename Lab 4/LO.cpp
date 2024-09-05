#include "Iterator.h"
#include "LO.h"

#include <iostream>
using namespace std;

#include <exception>

void LO::redim() {
	TElement* eNou = new TElement[2 * cp]; //alocam un spatiu de capacitate dubla
	int* urmNou = new int[2 * cp];
	int* precNou = new int[2 * cp];
	
	//copiem vechile valori in noua zona
	for (int i = 0; i < cp; i++) {
		urmNou[i] = urm[i];
		precNou[i] = prec[i];
		eNou[i] = e[i];
	}

	
	//initialziam lista spatiului liber - marcam toate pozitiile din vector ca fiind libere
	for (int i = cp; i < 2 * cp - 1; i++) {
		urmNou[i] = i + 1;
	}

	urmNou[2 * cp - 1] = -1;

	//initializam vectorul prec
	for (int i = 2 * cp - 1; i >= cp; i--) {
		precNou[i] = i - 1;
	}
	
	primLiber = cp;
	cp = 2 * cp;

	
	delete[] e;//eliberam vechea zona
	delete[] urm;
	delete[] prec;
	
	e = eNou; //vectorul indica spre noua zona
	urm = urmNou;
	prec = precNou;
	
}

void LO::initSpatiuLiber(TElement* lista, int cp) {

	//initialziam lista spatiului liber - marcam toate pozitiile din vector ca fiind libere
	for (int i = 0; i < cp - 1; i++) {
		urm[i] = i + 1;
	}

	urm[cp - 1] = -1;

	//initializam vectorul prec
	for (int i = cp - 1; i > 0; i--) {
		prec[i] = i - 1;
	}
	prec[0] = -1;

}

int LO::aloca() {
	//se aloca un spatiu liber de indice i, i=-1 daca nu mai exista spatiu liber
	
	int i = primLiber;
	if (i != -1) {
		primLiber = urm[primLiber];
	}
	return i;
	
}

void LO::dealoca(int i) {
	//adauga i la inceputul liste de spatii libere

	urm[i] = primLiber;
	primLiber = i;

}

LO::LO(Relatie r) {
	/* de adaugat */
	
	this->rel = r;

	this->cp = 5; //setam capacitatea
	
	this->prim = -1; //lista e vida

	this->ultim = -1;

	this->primLiber = 0;

	e = new TElement[cp];

	urm = new int[cp];

	prec = new int[cp];

	initSpatiuLiber(e, cp); 

	
}

// returnare dimensiune
int LO::dim() const {
	/* de adaugat */

	if (vida()) return 0;

	int nr_elem = 0;
	Iterator it = this->iterator();
	while (it.valid()) {
		nr_elem++;
		it.urmator();
	}
	return nr_elem;
}

// verifica daca LO e vida
bool LO::vida() const {
	/* de adaugat */
	if (prim == -1)
		return true;
	return false;
}

// returnare element
//arunca exceptie daca i nu e valid
TElement LO::element(int i) const {
	/* de adaugat */
	int poz = 0;
	Iterator it = this->iterator();
	while (it.valid()) {
		if (poz == i)
			return it.element();
		poz++;
		it.urmator();
	}
	throw exception();


}

// sterge element de pe o pozitie i si returneaza elementul sters
//arunca exceptie daca i nu e valid
TElement LO::sterge(int i) {
	/* de adaugat */
	TElement elem = element(i);

	//gasim indexul elementului de pe pozitia i din lista
	int index = 0, poz;
	for (poz = 0; poz < cp; poz++) {
		if (e[poz] == elem)
			index = poz;
	}
	

	if (prim == ultim) {
		prim = -1;
		ultim = -1;
	}
	else {
		if (index == prim) {
			prec[prim] = -1;
			prim = urm[index];
		}
		else if (index == ultim) {
			ultim = prec[ultim];
			urm[ultim] = -1;
		}
		else {
			urm[prec[index]] = urm[index];
			prec[urm[index]] = prec[index];
		}
	}
	
	dealoca(index);

	return elem;
}

// cauta element si returneaza prima pozitie pe care apare (sau -1)
int LO::cauta(TElement elem) const {
	/* de adaugat */
	int poz = 0;
	Iterator it = this->iterator();
	while (it.valid()) {
		if (it.element() == elem)
			return poz;
		poz++;
		it.urmator();
	}
	return -1;
}

int LO::creeazaNod(TElement elem) {
	//se creeaza un nod in lista cu informatia TElement, returneaza indicele pe care s a inserat
	
	if (primLiber == -1)
	{
		redim();
		
	}
	
	int i = aloca();
	if (i != -1) { //exista spatiu liber in lista
		e[i] = elem;
		urm[i] = -1;
		prec[i] = -1;
	}
	return i;
}

void LO::adaugaInainte(TElement elem, int i) {
	
	int indice_nod = creeazaNod(elem);
	
	urm[prec[i]] = indice_nod;
	prec[indice_nod] = prec[i];
	urm[indice_nod] = i;
	prec[i] = indice_nod;

}

// adaugare element in LO
void LO::adauga(TElement elem) {
	/* de adaugat */

	//cazul 1: lista este vida, trebuie sa setam prim
	if (vida()) {
		int indice_nod = creeazaNod(elem);
		prim = 0;
		ultim = 0;
	}
	//cazul 2: lista are un singur element, trebuie sa setam ultim
	else if (prim == ultim) {
		int indice_nod = creeazaNod(elem);
		urm[ultim] = indice_nod;
		prec[indice_nod] = ultim;
		ultim = indice_nod;
		
		if (rel(e[prim], elem) == false){
			//interschimbam
			e[ultim] = e[prim];
			e[prim] = elem;
		}
		
	}
	else if (rel(e[ultim], elem)) {//cazul 3: daca elementul curent trebuie sa devina noul ultim
		int indice_nod = creeazaNod(elem);
		urm[indice_nod] = -1;
		urm[ultim] = indice_nod;
		prec[indice_nod] = ultim;
		ultim = indice_nod;
	}
	else if (rel(elem, e[prim])) {//cazul 4: daca elementul curent trebuie sa devina noul prim
		int indice_nod = creeazaNod(elem);
	
		urm[indice_nod] = prim;
		prec[indice_nod] = -1;
		prec[prim] = indice_nod;
		prim = indice_nod;
	}
	else {//cazul 5: trebuie sa cautam pozitia inaintea careia sa inseram noul element
		int poz = prim;
		while (rel(e[poz], elem)) {
			poz = urm[poz];
		}
		
		adaugaInainte(elem, poz);
	}
}

// returnare iterator
Iterator LO::iterator() const{
	return Iterator(*this);
}


//destructor
LO::~LO() {
	/* de adaugat */

	delete[] e;
	delete[] urm;
	delete[] prec;
}

int LO::ultimulIndex(TElement elem) {
	int poz = dim() - 1; //pornim de la ultima pozitie

	int curent = ultim;
	while (curent != -1) {
		if (e[curent] == elem) {
			return poz;
		}
		poz--;
		curent = prec[curent];
	}
	return -1;
	

}