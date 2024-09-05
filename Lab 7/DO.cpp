#include "Iterator.h"
#include "DO.h"
#include <iostream>

#include <exception>


using namespace std;

DO::DO(Relatie r) {
	/* de adaugat */
	this->rel = r;
	this->index_rad = NULL_TVALOARE;
	this->primLiber = 1;
	this->cp = MAX_SIZE;
	for (int i = 0; i < cp; i++) {
		e[i] = NULL_TPERECHE;
		stanga[i] = NULL_TVALOARE;
		dreapta[i] = NULL_TVALOARE;
	}

}

void DO::setPrimLiber() {
	for (int i = 1; i < cp; i++) {
		if (e[i].first == -111111) {
			primLiber = i;
			break;
		}
	}
	
}

//rad - radacina unui subarbore, nou-elementul de adaugat
//se adauga nou in subarborele de radacina index si se returneaza radacina noului subarbore

TValoare DO::adauga_rec(int index, TElem nou) {

	//daca s-a ajuns la subarborele vid se adauga
	if (index == NULL_TVALOARE) {
		index = primLiber;
		e[primLiber] = nou;
		setPrimLiber();
	}

	//se adauga in subarborele stang
	else if (rel(nou.first, e[index].first) && nou.first!=e[index].first) {
		stanga[index] = adauga_rec(stanga[index], nou);
	}
	//se adauga in subarborele drept
	else if (!rel(nou.first, e[index].first) && nou.first != e[index].first) {
		dreapta[index] = adauga_rec(dreapta[index], nou);
	}
	
	else {
		e[index] = nou;
	}
	//se returneaza radacina subarborelui*/
	return index;
}


//adauga o pereche (cheie, valoare) in dictionar
//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
//daca nu exista cheia, adauga perechea si returneaza null
TValoare DO::adauga(TCheie c, TValoare v) {
	/* de adaugat */
	
	//cream o pereche de tip <TCheie, TValoare>
	TElem nou;
	nou.first = c;
	nou.second = v;
	
	//verificam daca elementul exista deja si ii retinem vechea valoare inainte sa il adaugam in dictionar
	auto val_veche = cauta(c);

	//apelam functia recursiva de adaugare
	index_rad = adauga_rec(index_rad, nou);
	
	return val_veche;
}

//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
TValoare DO::cauta(TCheie c) const {
	/* de adaugat */
	int rad = this->index_rad;
	while (rad != NULL_TVALOARE) {
		if (e[rad].first == c) {
			return e[rad].second;
		}
		//se cauta in subarborele stang
		if (rel(c, e[rad].first)) {
			rad = stanga[rad];
		}
		//se cauta in subarborele drept
		else {
			rad = dreapta[rad];
		}
	}
	
	return NULL_TVALOARE;
}

//se returneaza adresa nodului avand cheia minima din subarborele de radacina rad
TElem DO::minim(int rad) {
	while (stanga[rad] != NULL_TVALOARE) {
		rad = stanga[rad];
	}
	return e[rad];
}

//se sterge nodul avand cheia egala cu cheia lui e din subarborele de radacina p si se returneaza radacina noului subarbore
int DO::sterge_rec(int rad, TCheie c) {
	//daca s-a ajuns la un subarbore vid
	if (rad == NULL_TVALOARE) {
		
		return NULL_TVALOARE;
	}
	
	if (rel(c, e[rad].first) && c != e[rad].first) {
		//se sterge din subarborele stang
		
		stanga[rad] = sterge_rec(stanga[rad], c);
		
		return rad;
	}
	
	else if (!rel(c, e[rad].first) && c!= e[rad].first) {
		//se sterge din subarborele drept
		dreapta[rad] = sterge_rec(dreapta[rad], c);

		return rad;
	}
	
	else {
		//am ajuns la nodul care trebuie sters
		e[rad] = NULL_TPERECHE;
		primLiber = rad;

		if (stanga[rad] != NULL_TVALOARE && dreapta[rad] != NULL_TVALOARE) {
			//nodul are si subarbore stang si subarbore drept
			TElem temp = minim(dreapta[rad]);
			//se muta cheia minima in rad
			e[rad] = temp;
			//se sterge nodul cu cheia minima din subarborele drept
			dreapta[rad] = sterge_rec(dreapta[rad], e[rad].first);
			return rad;
		}
		else {
			auto temp = rad;
			int repl = 0;
			if (stanga[rad] == NULL_TVALOARE) {
				//nu exista subarbore stang
				repl = dreapta[rad];
				dreapta[rad] = NULL_TVALOARE;
			}
			else {
				//nu exista subarbore drept
				repl = stanga[rad];
				stanga[rad] = NULL_TVALOARE;
			}
			return repl;
		}
	}
}

//sterge o cheie si returneaza valoarea asociata (daca exista) sau null
TValoare DO::sterge(TCheie c) {
	/* de adaugat */


	//apelam functia recursiva de stergere
	int gasit = cauta(c);
	index_rad = sterge_rec(index_rad, c);
	return gasit;
}

//returneaza numarul de perechi (cheie, valoare) din dictionar
int DO::dim() const {
	/* de adaugat */
	int nr = 0;
	Iterator it = iterator();
	it.prim();
	while (it.valid()) {
		TElem e = it.element();
		nr++;
		it.urmator();
	}
	return nr;
}

//verifica daca dictionarul e vid
bool DO::vid() const {
	/* de adaugat */

	if (dim() == 0)
		return true;
	return false;
}


void DO::inlocuieste(TCheie k, TValoare valoareVeche, TValoare valoareNoua) {
	/* de adaugat */
	int rad = this->index_rad;
	while (rad != NULL_TVALOARE) {
		if (e[rad].first == k) {
			if (e[rad].second == valoareVeche) {
				e[rad].second = valoareNoua;
			}
			else break;
		}
		//se cauta in subarborele stang
		if (rel(k, e[rad].first)) {
			rad = stanga[rad];
		}
		//se cauta in subarborele drept
		else {
			rad = dreapta[rad];
		}
	}


}


Iterator DO::iterator() const {
	return  Iterator(*this);
}

DO::~DO() {
	/* de adaugat */
}
