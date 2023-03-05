#include <iostream>
#include <cstring>

using namespace std;

struct carte {

    int an_publicatie, cod_publicatie;
    string nume_carte, autor_carte;
    string nume_persoana;
    carte *next;
};

void adaugare_carte(carte &lista, int nr_max, int nr_carti) {

    int an, cod;
    string nume, autor;

    carte *newNod;
    newNod = new carte;

    if(nr_carti> nr_max)
    {
        cout<<"S-a atins numarul maxim de carti din biblioteca.\n";
        return;
    }

    cout<<"Introduceti numele cartii: ";
    getline(cin,nume);
    newNod->nume_carte = nume;

    cout<<"\nIntroduceti autorul cartii: ";
    getline(cin,autor);
    newNod->autor_carte = autor;

    cout<<"\nIntroduceti anul publicatiei: ";
    cin>>an;
    newNod->an_publicatie = an;

    cout<<"\nIntroduceti codul cartii: ";
    cin>>cod;
    newNod->cod_publicatie = cod;

    newNod->next = lista.next;
    lista.next = newNod;


}

void listare(carte &lista) {
    carte *p = lista.next;
    while (p != NULL) {
        cout<< p->nume_carte << "\n";
        p = p->next;
    }
}

void eliminare_carte(carte &lista) {

    int deEliminat;
    carte *p = &lista;
    cout<<"Introduceti codul cartii pe care vreti s-o eliminati: ";
    cin>>deEliminat;

    while(p != NULL) {
        if(p->next != NULL && p->next->cod_publicatie == deEliminat) {
            carte *aux = p->next->next;
            delete p->next;
            p->next = aux;
        }else
            p = p->next;
    }
}
void listare_info_carte(carte &lista)
{
    int cod;
    cout<<"Introduceti codul cartii pe care vreti s-o listati: ";
    cin>>cod;


    carte *p = lista.next;
    while (p->cod_publicatie != cod)
        p = p->next;

    if(p->next == NULL &&p->cod_publicatie != cod)
        cout<<"Cartea nu a fost gasita.";
    else
        cout<<p->nume_carte<<"\n"<<p->autor_carte<<"\n"<<p->an_publicatie<<"\n";

    if (p->nume_persoana.empty() != 0)
        cout<<"Cartea nu a fost imprumutata";
    else
        cout<<"Cartea a fost imprumutata de "<<p->nume_persoana<<endl;
}
void imprumut_carte(carte &lista)
{
    int cod;
    cout<<"Introduceti codul cartii: ";
    cin>>cod;
    cin.get();
    string persoana;
    cout<<"\nIntroduceti numele persoanei: ";
    getline(cin,persoana);


    carte *p = lista.next;

    while(p != NULL)
    {

        if(p->cod_publicatie == cod)
        {
            p->nume_persoana.append(persoana);
            break;
        }
        else
            p=p->next;

    }

    if (p->next == NULL && p->cod_publicatie != cod)
        cout<<"Nu exista cartea";

}

void listare_info_pers(carte &lista)
{
    string persoana;
    cout<<"Introduceti numele persoanei: ";
    getline(cin, persoana);

    carte *p = lista.next;
    while (p != NULL)
    {
        if(p->nume_persoana.compare(persoana) == 0)
        {
            cout<<p->nume_carte<<endl;
            break;
        }

        p=p->next;
    }

    if(p->next == NULL && p->nume_persoana != persoana)
        cout<<persoana<<" nu a imprumutat nicio carte.\n";
}



int main()
{
    carte lista;
    char op;
    lista.next = NULL;

    cout<<"Introduceti dimensiunea bibliotecii: ";
    int nr_max;
    cin>>nr_max;
    int nr_carti=0;

    do {
        cout<<"Introduceti codul operatiei: ";
        cin>>op;
        cin.get();
        switch(op){
            case 'A':adaugare_carte(lista, nr_max, nr_carti);
                    nr_carti++;
                    break;
            case 'L':listare(lista);
                    break;
            case 'E':eliminare_carte(lista);
                    break;
            case 'I':imprumut_carte(lista);
                    break;
            case 'C':listare_info_carte(lista);
                    break;
            case 'P':listare_info_pers(lista);
                    break;

        }

    }while(op != 'Q');


    return 0;
}
/*
A
Stapanul inelelor
J.R.R.Tolkien
1990
12
A
Fram, ursul polar
Cezar Petrescu
1999
13
A
Cel mai iubit dintre pamanteni
Marin Preda
1967
77
A
Ion
Liviu Rebreanu
1936
17
*/
