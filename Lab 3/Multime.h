#pragma once

#define NULL_TELEM -1
typedef int TElem;

class IteratorMultime;
class Nod;
typedef Nod* PNod;//se defineste tipul PNod ca fiind adresa unui Nod

class Multime {
	

private:
	/* aici e reprezentarea */
	//prim este adresa primului Nod din lista
	PNod head;
	int nr_elem;

public:
	friend class IteratorMultime;
	friend class Nod;

	//constructorul implicit
	// 	   
	//Complexitate totala: teta(1) constanta
	//Caz favorabil = Caz defavorabil = Caz mediu
	Multime();

	//adauga un element in multime
	//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
	// 
	//Complexitate totala: liniara O(n), unde n este numarul total de elemente al multimii, deoarece
	//apelam functia cauta() pentru a verifica daca elementul exista deja in multime
	//Caz favorabil - teta(1) elementul este pe prima pozitie in multime
	//Caz defavorabil - teta(n) elementul nu se afla in multime/se afla pe ultima pozitie
	//Caz mediu - teta(n)
	bool adauga(TElem e);

	//sterge un element din multime
	//returneaza adevarat daca elementul a existat si a fost sters
	//
	//Complexitate totala: liniara O(n), unde n este numarul total de elemente al multimii, deoarece
	//apelam functia cauta() pentru a verifica daca elementul exista in multime
	//Caz favorabil - teta(1) elementul este pe prima pozitie in multime
	//Caz defavorabil - teta(n) elementul nu se afla in multime/se afla pe ultima pozitie
	//Caz mediu - teta(n)
	bool sterge(TElem e);

	//verifica daca un element se afla in multime
	//
	//Complexitate totala: liniara O(n), unde n este numarul total de elemente al multimii
	//Caz favorabil - teta(1) elementul este pe prima pozitie in multime
	//Caz defavorabil - teta(n) elementul nu se afla in multime/se afla pe ultima pozitie
	//Caz mediu - teta(n)
	bool cauta(TElem elem) const;

	//verifica pe ce pozitie se afla un element in multime
	//
	//Complexitate totala: liniara O(n), unde n este numarul total de elemente al multimii
	//Caz favorabil - teta(1) elementul este pe prima pozitie in multime
	//Caz defavorabil - teta(n) elementul nu se afla in multime/se afla pe ultima pozitie
	//Caz mediu - teta(n)
	int cautaPoz(TElem elem) const;

	//intoarce numarul de elemente din multime;
	// 	   
	//Complexitate totala: teta(1) constanta
	//Caz favorabil = Caz defavorabil = Caz mediu
	int dim() const;

	//verifica daca multimea e vida;
	//
	//Complexitate totala: teta(1) constanta
	//Caz favorabil = Caz defavorabil = Caz mediu
	bool vida() const;

	/* Functia calculeaza si returneaza diferenta dintre numarul maxim si cel minim din multime
	* 
	* Complexitate totala: teta(n) - liniara , unde n este numarul de elemente al multimii
	* Caz favorabil = Caz defavorabil = Caz mediu
	* 
	* PSEUDOCOD
	* Subalgoritm diferentaMaxMin(m)
		daca Vida(m) atunci
			returneaza -1
		sfarsit_daca

		mini:Intreg
		maxi:Intreg
		e:TElem[]
		im: IteratorMultime[]

		im <- iterator()
		im.prim()

		daca im.valid() atunci
			e <-im.element()
			mini <- e
			maxi <- e
			im.urmator()
		sfarsit_daca

		cat_timp im.valid() executa
			e <- im.element()

			daca e < mini atunci
				mini = e
			sfarsit_daca

			daca e > maxi atunci
				maxi = e
			sfarsit_daca

			im.urmator()
		sfarsit_cat_timp

		returneaza maxi - mini
	SfSubalgoritm
	*/
	int diferentaMaxMin() const;

	//returneaza un iterator pe multime
	IteratorMultime iterator() const;

	// destructorul multimii
	//
	//Complexitate totala: teta(n) liniara , unde n este numarul de elemente al multimii
	//Caz favorabil = Caz defavorabil = Caz mediu
	~Multime();
};



