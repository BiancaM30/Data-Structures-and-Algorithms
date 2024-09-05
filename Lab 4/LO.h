#pragma once

class Iterator;

typedef int TComparabil;
typedef TComparabil TElement;

typedef bool (*Relatie)(TElement, TElement);

#define NULL_TELEMENT -1

class LO {
private:
	friend class Iterator;
	
	Relatie rel; //relatia de ordine intre elemente

	int cp; //capacitatea vectorului dinamic
	
	TElement* e; //elementele listei
	
	int* urm; //vectorul dinamic pentru legaturile urmatoare
	
	int* prec; //vectorul dinamic pentru legaturile precedente
	
	int prim; //referinta catre primul element al listei

	int ultim; //referinta catre ultimul element al listei
	
	int primLiber; //referinta catre primul element din lista spatiului liber

	//redimensionarea vectorului dinamic
	//
	//Complexitate: teta(n) - liniara, unde n = noua capacitate
	//Caz favorabil = Caz defavorabil = Caz mediu
	void redim(); 

	//initializarea spatiului liber -  marcam toate pozitiile din vector ca fiind libere
	//
	//Complexitate: teta(n) - liniara, unde n = capacitatea listei
	//Caz favorabil = Caz defavorabil = Caz mediu
	void initSpatiuLiber(TElement* lista, int cp);

	//alocarea unui nod
	//
	//Complexitate: teta(1) - constanta
	//Caz favorabil = Caz defavorabil = Caz mediu
    int aloca();

	//dealocarea unui nod
	//
	//Complexitate: teta(1) - constanta
	//Caz favorabil = Caz defavorabil = Caz mediu
	void dealoca(int i);

public:
	// constructor
	//
	//Complexitate: teta(n) - liniara, unde n = capacitatea listei (deoarece trebuie sa initializam spatiul liber)
	//Caz favorabil = Caz defavorabil = Caz mediu
	LO(Relatie r);

	// returnare dimensiune
	//
	//Complexitate: teta(n) - liniara, unde n = numarul de elemente al listei
	//Caz favorabil = Caz defavorabil = Caz mediu
	int dim() const;

	// verifica daca LO e vida
	//
	//Complexitate: teta(1) - constanta 
	//Caz favorabil = Caz defavorabil = Caz mediu
	bool vida() const;

	// returnare element
	//arunca exceptie daca i nu e valid
	//
	//Complexitate: O(n) - liniara 
	//Caz favorabil: teta(1) - constanta, cand elementul se afla pe prima pozitie din lista
	//Caz defavorabil: teta(n) - liniara, cand elementul se afla pe ultima pozitie din lista
	//Caz mediu: teta(n)
	TElement element(int i) const;

	//se creeaza un nod in lista cu informatia TElement, returneaza indicele pe care s a inserat
	//
	//Complexitate: O(n) - liniara
	//Caz favorabil : teta(1) - constanta, cand primul element liber este diferit de -1
	//Caz defavorabil: teta(n) - liniara, unde n = noua capacitate a listei, cand primul element liber este -1 si trebuie 
	//sa redimensionam
	//Caz mediu: teta(n)
	int creeazaNod(TElement e);

	//adauga elementul e inainte indicelui i
	//
	//Complexitate: teta(1) - constanta 
	//Caz favorabil = Caz defavorabil = Caz mediu
	void adaugaInainte(TElement e, int i);

	// adaugare element in LO a.i. sa se pastreze ordinea intre elemente
	//
	//Complexitate: O(n) - liniara
	//Caz favorabil : teta(1) - constanta, cand primul element liber este diferit de -1
	//Caz defavorabil: teta(n) - liniara, unde n = noua capacitate a listei, cand primul element liber este -1 si trebuie 
	//sa redimensionam
	//Caz mediu: teta(n)
	void adauga(TElement e);

	// sterge element de pe o pozitie i si returneaza elementul sters
	//arunca exceptie daca i nu e valid
	//
	//Complexitate: teta(n) - liniara, unde n = capacitatea listei
	//Caz favorabil = Caz defavorabil = Caz mediu
	TElement sterge(int i);

	// cauta element si returneaza prima pozitie pe care apare (sau -1)
	//
	//Complexitate: O(n) - liniara, unde n = numarul de elemente al listei
	//Caz favorabil: teta(1) - constanta, cand elementul se afla pe prima pozitie din lista
	//Caz defavorabil: teta(n) - liniara, cand elementul se afla pe ultima pozitie din lista
	//Caz mediu: teta(n)
	//Caz favorabil = Caz defavorabil = Caz mediu
	int cauta(TElement e) const;

	// returnare iterator
	//
	//Complexitate: teta(1) - constanta
	//Caz favorabil = Caz defavorabil = Caz mediu
	Iterator iterator() const;

	//destructor
	//
	//Complexitate: teta(1) - constanta 
	//Caz favorabil = Caz defavorabil = Caz mediu
	~LO();


	//Functia returneaza ultimul index al elementului primit ca parametru sau -1 daca elementul nu exista
	//param: elem(Telement)
	// 
	//Complexitate: teta(n) - liniara
	//Caz favorabil = Caz defavorabil = Caz mediu

	int ultimulIndex(TElement elem);
	/*Subalgoritm ultimulIndex(LO, elem: TElement, int poz)
	*
	* poz: Intreg
	* curent: Intreg
	* poz <- dim(LO) - 1
	* curent <- ultim
	*
	* CatTimp curent != -1 executa
	*
	*		Daca e[curent] = elem atunci
	*			returneaza poz
	*		SfDaca
	*		poz <- poz - 1
	*		curent <- prec[curent]
	*
	* sfarsit CatTimp
	*
	* returneaza -1
	*
	* SfSubalgoritm
	*/
};
