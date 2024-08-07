#include "TLista.h"
#include <iostream>

using namespace std;

void TLista::Init()
{
	Comeco = NULL; 
	Final = NULL;
}

bool TLista::IsEmpty()
{
	return Comeco == NULL;
}

TLista::TNoLista * TLista::GetPtrComeco()
{
	return Comeco;
}

TLista::TNoLista * TLista::GetPtrFinal()
{
	return Final;
}

TLista::TInfoLista TLista::GetDadoComeco()
{
	if (!IsEmpty())
	{
		return Comeco->dado;
	}
	else
	{
		return 0;
	}
}
TLista::TInfoLista TLista::GetDadoFinal()
{
	if (!IsEmpty())
	{
		return Final->dado;
	}
	else
	{
		return 0;
	}
}

TLista::TLista()
{
	Init();
}

TLista::~TLista()
{
	while (!IsEmpty()) Excluir(Comeco->dado);
}

void TLista::Imprimir()
{
	if (!IsEmpty())
	{
		TNoLista * aux_no;
		cout << "\n\no CONTEUDO DA Lista E:\n\n"; 
		aux_no = Comeco;

		while (aux_no != NULL)
		{
			cout << aux_no->dado << "; "; 
			aux_no = aux_no->prox;
		}
	}
	else
	{
		cout << "A lista est vazia!";
	}

	cout << "\n\n";
}

TLista::TNoLista * TLista::Pesquisar(TInfoLista dado)
{
	if (!IsEmpty())
	{
		TNoLista * no;
		
		no = Comeco;
		bool achou = false;

		while( !achou && no != NULL)
		{
			achou = no->dado == dado;
			
			if (!achou) no = no->prox;
		}

		return no;
	}
	else
	{
		return NULL;
	}
}

TLista::TNoLista* TLista::Inserir_no_comeco(TInfoLista dado)
{
	TNoLista * novo;
	novo = new TNoLista;

	novo->dado = dado; 
	novo->ant = NULL;
	novo->prox = NULL;

	if (IsEmpty())
	{
		Comeco = novo; 
		Final = novo;
	}
	else
	{
		novo->prox = Comeco;
		Comeco->ant = novo;
		Comeco = novo;
	}

	return novo;
}

TLista::TNoLista * TLista::Inserir_no_final(TInfoLista dado)
{
	TNoLista * novo;
	novo = new TNoLista;

	novo->dado = dado;
	novo->ant = NULL;
	novo->prox = NULL;

	if (IsEmpty())
	{
		Comeco = novo; 
		Final = novo;
	}
	else
	{
		novo->ant = Final; 
		Final->prox = novo; 
		novo->prox = NULL; 
		novo->dado = dado; 
		Final = novo;
	}

	return novo;
}

TLista::TNoLista * TLista::Inserir_apos_elemento(TInfoLista ref, TInfoLista dado)
{

	TNoLista *no, *novo;

	no = Pesquisar(ref);

	if (no != NULL)
	{
		if (no->prox != NULL)
		{
			novo = new TNoLista;
			novo->dado = dado;
			novo->ant = NULL;
			novo->prox = NULL;

			novo->ant = no;
			novo->prox = no->prox;

			no->prox = novo;
			novo->prox->ant = novo;
		}
		else
		{
			novo = Inserir_no_final(dado);
		}

		return novo;
	}
	else
	{
		return NULL;
	}
}

TLista::TInfoLista TLista::Excluir(TInfoLista dado) 
{

	TNoLista* no;
	TInfoLista dado_excluido;

	no = Pesquisar(dado);

	if (no != NULL)
	{
		if (no->ant != NULL && no->prox != NULL)
		{
			no->ant->prox = no->prox;
			no->prox->ant = no->ant;
		}
		else if (no->ant == NULL && no->prox != NULL)
		{
			no->prox->ant = NULL;
			Comeco = no->prox;
		}
		else if (no->ant != NULL && no->prox == NULL)
		{
			no->ant->prox = NULL;
			Final = no->ant;
		}
		else
		{
			Comeco = NULL;
			Final = NULL;
		}

		dado_excluido = no->dado;

		delete(no);

		return dado_excluido;
	}
	else
	{
		return NULL;
	}
}
