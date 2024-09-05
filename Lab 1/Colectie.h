#pragma once
#define NULL_TELEM -1
#define MAX 999999  //definim elementul maxim
#define MIN -999999 //definim elementul minim

typedef int TElem;

class IteratorColectie;

class Colectie
{
	friend class IteratorColectie;

private:
	/* aici e reprezentarea */

	int cp;  //capacitate

	int n;  //numarul de elemente nenule din colectie

	TElem* e; //elemente

	int mini; //elementul minim din colectie

	int maxi; //elementul maxim din colectie

	void init_interval(int, int);//pentru initializarea intervalului, complexitate liniara teta(n),
								//unde n este numarul de elemente situate intre minim si maxim

	void redim_stanga(int, int); //pentru redimensionare la stanga, complexitate liniara teta(n),
								//unde n este noua capacitate	

	void redim_dreapta(int, int); //pentru redimensionare la dreapta, complexitate liniara teta(n),
								//unde n este noua capacitate

public:
	//constructorul implicit
	//
	//Complexitate totala: teta(1)
	//Caz favorabil = Caz defavorabil = Caz mediu
	Colectie();

	//adauga un element in colectie
	//
	//Complexitate totala: O(n)
	//Caz favorabil: teta(1) -  elementul se afla in intervalul [mini, maxi]
	//Caz defavorabil: teta (n) - toate celelalte cazuri, in care trebuie sa initializam intervalul sau sa redimensionam
	//Caz mediu: teta(n)
	void adauga(TElem e);

	//cauta pozitia pe care se gaseste frecventa elementulului in colectie
	//
	//Complexitate totala: teta(1)
	//Caz favorabil = Caz defavorabil = Caz mediu
	int cautaPozElem(TElem elem);
	

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	//
	//Complexitate totala: teta(n) - liniara
	//Caz favorabil = Caz defavorabil = Caz mediu
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	//
	//Complexitate totala: O(n) 
	//Caz favorabil: teta(1) - elementul este situat in afara intervalului [mini, maxi]
	//Caz defavorabil: teta(n) - elementul este situat in intervalul [mini, maxi] si trebuie sa 
	//ii aflam numarul de aparitii
	//Caz mediu: teta(n)
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	//
	//Complexitate totala: teta(n) - liniara , unde n este numarul de elemente distincte ale colectiei
	//Caz favorabil = Caz defavorabil = Caz mediu
	int nrAparitii(TElem elem) const;


	//intoarce numarul de elemente nenule din colectie;
	//
	//Complexitate totala: teta(1)
	//Caz favorabil = Caz defavorabil = Caz mediu
	int dim() const;

	//verifica daca colectia e vida;
	//
	//Complexitate totala: teta(1)
	//Caz favorabil = Caz defavorabil = Caz mediu
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	//
	//Complexitate totala: teta(1)
	//Caz favorabil = Caz defavorabil = Caz mediu
	~Colectie();

	

};

