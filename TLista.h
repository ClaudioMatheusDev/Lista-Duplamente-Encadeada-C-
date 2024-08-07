#pragma once
class TLista
{
public:
	typedef int TInfoLista;

	struct TNoLista 
	{
		TInfoLista dado;
		TNoLista* ant;
		TNoLista* prox;
	};

	bool IsEmpty();

	TNoLista * GetPtrComeco();
	TNoLista * GetPtrFinal();

	TInfoLista GetDadoComeco();
	TInfoLista GetDadoFinal();

	TNoLista * Inserir_no_comeco(TInfoLista dado);
	TNoLista * Inserir_no_final(TInfoLista dado);
	TNoLista * Inserir_apos_elemento(TInfoLista ref, TInfoLista dado);

	TNoLista * Pesquisar(TInfoLista dado); 
	TInfoLista Excluir(TInfoLista dado); 
	void Imprimir();

	TLista();
	~TLista();

protected:
	TNoLista* Comeco;
	TNoLista* Final;
	void Init();
};

