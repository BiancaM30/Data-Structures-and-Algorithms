#pragma once

typedef int TCheie;
typedef int TValoare;

#define NULL_TVALOARE -1
#define MAX_SIZE 7000;
#define NULL_TPERECHE pair<TCheie, TValoare>(-111111, -111111);


#include <utility>
typedef std::pair<TCheie, TValoare> TElem;

class Iterator;

typedef bool(*Relatie)(TCheie, TCheie);

class DO {
	friend class Iterator;
private:
	/* aici e reprezentarea */
	Relatie rel;
	int cp; //capacitatea tabelelor
	int primLiber; //prima locatie libera din tabela de elemente
	int index_rad; //indexul radacinii in tabela de elemente
	TElem e[7000];
	int stanga[7000];
	int dreapta[7000];

	void setPrimLiber();

public:
	

	// constructorul implicit al dictionarului
	//
	//Complexitate: teta(cp) - liniara, unde cp este capacitatea tabelelor
	//Caz favorabil = Caz defavorbail = Caz mediu
	DO(Relatie r);


	//functia adauga recursiv in intr-un subarbore de radacina index_rad, un element nou
	//
	//Complexitate: O(h) - unde h este inaltimea arborelui
	//Caz favorabil: teta(log2n) - daca arborele este plin
	//Caz defavorabil: teta(n) - daca arborele este degenerat(lant liniar)
	TValoare adauga_rec(int index_rad , TElem nou);

	// adauga o pereche (cheie, valoare) in dictionar
	//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
	// daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
	//
	//Complexitate: O(h) - unde h este inaltimea arborelui
	//Caz favorabil: teta(log2n) - daca arborele este plin
	//Caz defavorabil: teta(n) - daca arborele este degenerat(lant liniar)
	TValoare adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
	//
	//Complexitate: O(h) - unde h este inaltimea arborelui
	//Caz favorabil: teta(log2n) - daca arborele este plin
	//Caz defavorabil: teta(n) - daca arborele este degenerat(lant liniar)
	TValoare cauta(TCheie c) const;

	//Returneaza pozitia nodului avand cheia minima din subarborele de radacina e[rad]
	//
	//Complexitate: O(h) - unde h este inaltimea arborelui
	//Caz favorabil: teta(log2n) - daca arborele este plin
	//Caz defavorabil: teta(n) - daca arborele este degenerat(lant liniar)
	TElem minim(int rad);

	//functia sterge recursiv dintr-un subarbore de radacina rad, elementul cu cheia c
	// 
	//Complexitate: O(h) - unde h este inaltimea arborelui
	//Caz favorabil: teta(log2n) - daca arborele este plin
	//Caz defavorabil: teta(n) - daca arborele este degenerat(lant liniar)
	int sterge_rec(int rad, TCheie c);

	//sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
	//
	//Complexitate: O(h) - unde h este inaltimea arborelui
	//Caz favorabil: teta(log2n) - daca arborele este plin
	//Caz defavorabil: teta(n) - daca arborele este degenerat(lant liniar)
	TValoare sterge(TCheie c);

	//returneaza numarul de perechi (cheie, valoare) din dictionar
	//
	//Complexitate: O(h) - unde h este inaltimea arborelui
	//Caz favorabil: teta(log2n) - daca arborele este plin
	//Caz defavorabil: teta(n) - daca arborele este degenerat(lant liniar)
	int dim() const;

	//verifica daca dictionarul e vid
	//
	//Complexitate: O(h) - unde h este inaltimea arborelui
	//Caz favorabil: teta(log2n) - daca arborele este plin
	//Caz defavorabil: teta(n) - daca arborele este degenerat(lant liniar)
	bool vid() const;

	// se returneaza iterator pe dictionar
	// iteratorul va returna perechile in ordine dupa relatia de ordine (pe cheie)
	//
	//Complexitate: teta(1) - constanta
	Iterator iterator() const;

	/*Functia inlocuieste valoarea mapata in prezent cheii k cu valoarea valoareNoua, dar numai în cazul in care valoarea 
	curenta este egala cu valoareVeche

	//Complexitate: O(h) - unde h este inaltimea arborelui
	//Caz favorabil: teta(log2n) - daca arborele este plin
	//Caz defavorabil: teta(n) - daca arborele este degenerat(lant liniar)


	PSEUDOCOD

	pre : d : dictionar, k: TCheie, valoareVeche: TValoare, valoareNoua: TValoare
	post : d' : dictionarul in care a fost modificata valoarea de la cheia k cu valoareaNoua, daca valoarea veche este
	egala cu cea curenta, altfel d' coincide cu d
	
		Subalgoritm inlocuieste(d, k,valoareVeche, valoareNoua)
			rad: intreg
			rad<-d.index_rad
			catTimp rad != NULL_TVALOARE executa
				daca d.e[rad].first = k atunci
					daca d.e[rad].second = valoareVeche atunci
						d.e[rad].second <- valoareNoua
					altfel sfarsitCatTimp
					sfarsitDaca
				sfarsitDaca

				daca d.rel(k,d.e[rad].first) = true atunci
					rad<-d.stanga[rad]
				altfel rad<-d.dreapta[rad]
				sfarsitDaca

			sfarsitCatTimp
		sfarsitSubalgoritm
	*/


	void inlocuieste(TCheie k, TValoare valoareVeche, TValoare valoareNoua);

	// destructorul dictionarului
	~DO();

};
