#pragma once
#include "Nod.h"

#define MAX 301 //numarul maxim de locatii din tabela

#include <vector>

typedef int TCheie;
typedef int TValoare;

#include <utility>
typedef std::pair<TCheie, TValoare> TElem;

using namespace std;

class IteratorMDO;
class IteratorValori;
class Nod;
typedef Nod* PNod;
typedef bool(*Relatie)(TCheie, TCheie);

class MDO {
	friend class IteratorMDO;
	friend class IteratorValori;
	friend class Nod;

private:
	/* aici e reprezentarea */

	Relatie rel;
	int m; //numarul de locatii din tabela de dispersie
	PNod l[MAX];

	//Functia de dipersie prin metoda diviziunii
	//
	//Complexitate: teta(1) - constanta
	int d(TCheie ch);

public:


	// constructorul implicit al MultiDictionarului Ordonat
	//
	//Complexitate: teta(m) - liniara
	MDO(Relatie r);

	// adauga o pereche (cheie, valoare) in MDO
	//
	//Complexitate: O(n) - liniara 
	//Caz favorabil: teta(1) - constant - cand lista este goala sau noul element trebuie 
	//adaugat la inceputul listei
	//Caz defavorabil: teta(n) - liniar - daca noul element trebuie adaugat la sfarsitul listei
	//Caz mediu - teta(1)  - constant (in ipoteza dispersiei uniforme simple) sau teta(n) altfel
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	//
	//Complexitate: teta(n) - liniara, unde n este numarul de elemente al listei inlantuite 
	//corespunzatoare cheii c
	vector<TValoare> cauta(TCheie c) ;

	//cauta pozitia unui element in MDO
	//
	//Complexitate: O(n) - liniara, unde n este numarul de elemente al listei inlantuite 
	//corespunzatoare cheii c
	//Caz favorabil: teta(1) - elementul cautat de afla pe prima pozitie din lista
	//Caz defavorabil: teta(n) - elementul cautat se afla pe ultima pozitie din lista
	//Caz mediu: teta(n)
	int cautaPoz(TCheie c, TValoare v);

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	//
	//Complexitate: O(n) - liniara, unde n este numarul de elemente al listei inlantuite
	//corespunzatoare cheii c
	//Caz favorabil - teta(1) elementul este pe prima pozitie in multime
	//Caz defavorabil - teta(n) elementul nu se afla in multime/se afla pe ultima pozitie
	//Caz mediu - teta(n) 
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MDO 
	//
	//Complexitate: teta(n+m) - liniara, unde containerul are n elemente si este reprezentat folosind 
	//o TD cu m locatii si liste independente
	int dim() const;

	//verifica daca MultiDictionarul Ordonat e vid 
	//
	//Complexitate: teta(n+m) - liniara, unde containerul are n elemente si este reprezentat folosind 
	//o TD cu m locatii si liste independente
	bool vid() const;

	// se returneaza iterator pe MDO
	// iteratorul va returna perechile in ordine in raport cu relatia de ordine
	//
	//Complexitate: teta(1) - constanta
	IteratorMDO iterator() const;

	// se returneaza iterator pe valorile din MDO
	// iteratorul va returna lista de valori corespunzatoare cheii ch in raport cu relatia de ordine
	//
	//Complexitate: teta(1) - constanta
	IteratorValori iteratorValori(TCheie ch) const;

	// destructorul 
	// 	
	//Complexitate: teta(n+m) - liniara, unde containerul are n elemente si este reprezentat folosind 
	//o TD cu m locatii si liste independente
	~MDO();

};
