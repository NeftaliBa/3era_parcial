#include <stdio.h>
#include <stdlib.h>

struct nodo *nuevoNodo(int dato);
void insertarNodo(struct nodo *nd, struct nodo *nodo);
int busqueda(struct nodo *raiz, int dato);

struct nodo
{
	struct nodo *hijoizq;
	struct nodo *hijoder;
	int dato, lv;
};

int main()
{
	int num, lv = 0, r=0;
	struct nodo *raiz = NULL;
	raiz = nuevoNodo(10);
	insertarNodo(raiz, nuevoNodo(5));
	insertarNodo(raiz, nuevoNodo(3));
	insertarNodo(raiz, nuevoNodo(6));
	insertarNodo(raiz, nuevoNodo(17));
	insertarNodo(raiz, nuevoNodo(13));
	insertarNodo(raiz, nuevoNodo(21));
	insertarNodo(raiz, nuevoNodo(3));

	printf("Ingresa el numero a buscar en el arbol: ");
	scanf("%d", &num);
	lv = busqueda(raiz, num);
	if (lv > 0){
		printf("Numero %d en el nivel: %d \n", num, lv);
	}else{
		printf("Numero no encontrado\n");
}
 
}

struct nodo *nuevoNodo(int dato)
{
	size_t tam_nodo = sizeof(struct nodo);
	struct nodo *nuevo_nodo = (struct nodo *)malloc(tam_nodo);
	nuevo_nodo->dato = dato;
	nuevo_nodo->hijoizq = NULL;
	nuevo_nodo->hijoder = NULL;
	return nuevo_nodo;
}

void insertarNodo(struct nodo *nd, struct nodo *nodo)
{
	if (nd != NULL && nodo != NULL)
	{
		nodo->lv = nd->lv + 1;
		nodo->lv = nodo->lv + 1;
		if (nodo->dato > nd->dato)
		{
			if (nd->hijoizq == NULL)
				nd->hijoder = nodo;
			else
				insertarNodo(nd->hijoder, nodo);
		}
		else
		{
			if (nd->hijoizq == NULL)
				nd->hijoizq = nodo;
			else
				insertarNodo(nd->hijoizq, nodo);
		}
	}
}

int busqueda(struct nodo *raiz, int dato)
{
	int l = 0;
	if (raiz == NULL)
		return 0;
	if (raiz->dato == dato)
		return raiz->lv;
	l = busqueda(raiz->hijoizq, dato);
	if (l > 0)
		return l;
	l = busqueda(raiz->hijoder, dato);
	if (l > 0)
		return l;
	return 0;
}