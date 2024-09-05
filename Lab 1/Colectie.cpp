#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;

void Colectie::init_interval(int mini_init, int maxi_init) {
	TElem* nou = new int[maxi_init - mini_init + 1];

	nou[0] = 1;
	nou[maxi_init - mini_init] = 1;

	for (int i = 1; i < maxi_init-mini_init; i++) {
		nou[i] = 0;
	}
	
	cp = maxi_init - mini_init + 1;
	maxi = maxi_init;
	mini = mini_init;

	delete[] e;
	e = nou;

}

void Colectie::redim_stanga(int new_cp, int new_mini) {

	TElem* eNou = new int[new_cp]; //alocam un spatiu de capacitate dorita

	//punem pe prima pozitie frecventa noului minim
	eNou[0] = 1;

	for (int i = 1; i < mini-new_mini; i++) { //populam cu 0 vectorul pana ajungem la vechiul minim
		eNou[i] = 0;
	}

	//copiem vechile valori in continuare
	int poz = 0;
	for (int i = mini-new_mini; i < new_cp; i++) {
		eNou[i] = e[poz];
		poz++;
	}
		
	cp = new_cp; //actualizam capacitatea
	mini = new_mini; //actualizam minimul

	delete[] e; //eliberam vechea zona

	e = eNou; //vectorul indica spre noua zona
}

void Colectie::redim_dreapta(int new_cp, int new_maxi) {

	TElem* eNou = new int[new_cp]; //alocam un spatiu de capacitate dorita

	//copiem vechile valori in noul vector
	for (int i = 0; i < maxi - mini + 1; i++) {
		eNou[i] = e[i];
	}
	
	//populam cu 0 vectorul pana ajungem la noul maxim
	for (int i = maxi - mini + 1; i < new_cp - 1; i++) {
		eNou[i] = 0;
	}

	//punem pe ultima pozitie frecventa noului minim
	eNou[new_cp-1] = 1;

	cp = new_cp; //actualizam capacitatea
	maxi = new_maxi; //actualizam maximul

	delete[] e; //eliberam vechea zona

	e = eNou; //vectorul indica spre noua zona

}

Colectie::Colectie() {
	/* de adaugat */

	this->cp = 1; //setam capacitatea

	e = new TElem[cp]; //alocam spatiu de memorare pentru vector

	this->n = 0;  //setam numarul de elemente

	this->mini = MAX; //initializam minimul cu constanta MAX

	this->maxi = MIN; //initializam maximul cu constanta MIN
}


void Colectie::adauga(TElem elem) {
	/* de adaugat */

	if (vida()) {
		mini = elem;
	}
	else if (n == 1){
		if (elem > mini) maxi = elem;
		else {
			maxi = mini;
			int aux = elem;
			elem = mini;
			mini = aux;
		}
		init_interval(mini, maxi);
		if (elem == mini) e[0]++;
		
	}
		
	//daca elementul este cuprins intre mini si maxi atunci vom creste frecventa pe pozitia corespunzatoare
	else if (elem >= mini && elem <= maxi) {
			int index = cautaPozElem(elem);
			this->e[index]++;
		}

	else if (elem < mini) {
		//daca elementul este mai mic decat mini trebuie sa facem redimensionare la stannga si sa mutam elementele 
		//vechi pe noile pozitii
		int new_cp = cp + mini - elem; //noua capacitate dupa care vom face redimensionare
		redim_stanga(new_cp, elem);
	}
	
		else {
			//daca elementul este mai mare decat maxi trebuie sa facem redimensionare la dreapta si sa mutam elementele 
			//vechi pe noile pozitii
			int new_cp = cp + elem - maxi; //noua capacitate dupa care vom face redimensionare
			redim_dreapta(new_cp, elem);
		}
	this->n++; //la final crestem numarul de elemente nenule
}

int Colectie::cautaPozElem(TElem elem) {
	/* de adaugat */

	return elem - mini;
}

bool Colectie::sterge(TElem elem) {
	/* de adaugat */
	if (dim() == 0 || cauta(elem) == false) return false; 
	int index = cautaPozElem(elem);

	if (e[index] == 0) return false; //elementul nu exista

	//daca frecventa elementului e mai mare decat 1, o scadem cu o unitate
	if (e[index] > 1) {
		e[index]--;
		n--;
		return true;
	}
	
	//daca frecventa elementului e 1 si acesta nu reprezinta un capat al vectorului, o scadem cu o unitate
	if (e[index] == 1 && elem > mini && elem < maxi) {
		e[index] = 0;
		n--;
		return true;
	}

	//daca frecventa elementului e 1 si acesta reprezinta un capat al vectorului, trebuie sa redimensionam
	if (e[index] == 1 && elem == mini) {
		e[index] = 0;
		//trebuie sa cautam primul numar nenul mai mare decat mini pentru a sterge toate elementele pana la el
		int poz = -1;
		for (int i = 1; i < maxi - mini + 1; i++) {
			if (e[i] != 0) {
				poz = i;
				break;
			}	
		}
	
		//stergem elementele pana la poz
		TElem* eNou = new int[cp-poz]; //alocam un spatiu de capacitate dorita
		int j = poz;
		for (int i = 0; i < cp - poz; i++) {
			eNou[i] = e[j];
			j++;
		}
		delete[] e;
		e = eNou;
		n--;
		mini = mini + poz;
		return true;
	}

	if (e[index] == 1 && elem == maxi) {
		e[index] = 0;
		//trebuie sa cautam primul numar nenul mai mic decat maxi pentru a sterge toate elementele de dupa la el
		int poz = -1;
		for (int i = maxi - mini; i >= 0; i--) {
			if (e[i] != 0) {
				poz = i;
				break;
			}
			maxi--;
		}	
		
		//stergem elementele de dupa poz
		TElem* eNou = new int[poz+1]; //alocam un spatiu de capacitate dorita
		for (int i = 0; i < poz+1; i++) {
			eNou[i] = e[i];
		}
		delete[] e;
		e = eNou;
		n--;
		//maxi = maxi - poz + 2;
		return true;
	}
	
}


bool Colectie::cauta(TElem elem) const {
	/* de adaugat */
	if (elem < mini || elem > maxi) return false;
	if (nrAparitii(elem) > 0) return true;
	return false;
}

int Colectie::nrAparitii(TElem elem) const {
	/* de adaugat */
	int nr_aparitii = 0;

	IteratorColectie ic = this->iterator();
	ic.prim();
	while (ic.valid()) {
		TElem e = ic.element();
		if (e == elem)
			nr_aparitii++;
		ic.urmator();
	}
	return nr_aparitii;
}


int Colectie::dim() const {
	/* de adaugat */
	return n;
}


bool Colectie::vida() const {
	/* de adaugat */
	if (n == 0) return true;
	return false;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}



Colectie::~Colectie() {
	/* de adaugat */

	delete[] e; //eliberam zona de memorare alocata vectorului
}

