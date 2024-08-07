#include <iostream>
#include "TLista.h"

using namespace std;
 TLista lista;

int main(int argc, char** argv) {
	
	
	
	//-----------------------------------------------------------------//
	//INSERINDO OS DADOS NO COME�O
	lista.Inserir_no_comeco(30);
    lista.Inserir_no_comeco(40);
    lista.Inserir_no_comeco(50);
	//imprimindo a lista
	lista.Imprimir();
	
	
	
	//-----------------------------------------------------------------//
	//INSERINDO OS DADOS NO FINAL
 	lista.Inserir_no_final(20);
    lista.Inserir_no_final(10);
 	//imprimindo a lista
	lista.Imprimir();
	
	
	//-----------------------------------------------------------------//
	//INSERINDO O N�MERO 15 APOS O N�MERO 20
	lista.Inserir_apos_elemento(20, 15);
	//imprimindo a lista
    lista.Imprimir();
    
	
	//-----------------------------------------------------------------//
	//EXCLUINDO O N�MERO 30
	lista.Excluir(30);
	//imprimindo a lista
	lista.Imprimir();
	
	//-----------------------------------------------------------------//
    //CONTAR A QUANTIDADE DE N�MEROS NA LISTA
   	 int contar = 0;
    TLista::TNoLista* no = lista.GetPtrComeco();
    while (no != NULL) {
        contar++;
        no = no->prox;
    }
    cout << "Total de elementos: " << contar <<  " ";
	
	//-----------------------------------------------------------------//
	// CALCULANDO A SOMA DOS N�MEROS DA LISTA
    int soma = 0;
    no = lista.GetPtrComeco();
    while (no != NULL) {
        soma += no->dado;
        no = no->prox;
    }
    cout << "\n\nSoma dos elementos: " << soma << " ";
	
	
	int resultado = soma / 5;
	
	cout << "\n\nMedia aritmetica: " << resultado <<  " ";

	
	return 0;
}
