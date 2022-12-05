#include <stdio.h>
#include <stdlib.h>

struct node *new_node(int dato);
void insert_node(struct node *nd, struct node *nodo);
int search(struct node *raiz, int dato);

struct nodo
{
	struct nodo *hijoizq;
	struct nodo *hijoder;
	int dato, lv;
};

int main()
{
	int num, lv = 0;
	struct nodo *raiz = NULL;
	raiz = nuevoNodo(10);
	insertarNodo(raiz, 15);
	insertarNodo(raiz, 5);
	insertarNodo(raiz, 3);
	insertarNodo(raiz, 6);
	insertarNodo(raiz, 17);
	insertarNodo(raiz, 13);
	insertarNodo(raiz, 21);
	insertarNodo(raiz, 3);

	printf("Ingresa el numero a buscar en el arbol: ");
	scanf("%d", &num);
	lv = search(raiz, num);
	if (lv > 0)
		printf("Numero %d en el nivel: %d \n", num, lv);
	else
		printf("Numero no encontrado\n");

	return 0;
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

void insertarNodo(struct nodo *nd, int dato)
{
	if (dato < nd->dato)
	{
		if (nd->hijoder == NULL)
		{
			nd->hijoder = nuevoNodo(dato);
		}
		else
		{
			insertarNodo(nd->hijoder, dato);
		}
	}
	else
	{
		if (nd->hijoizq == NULL)
		{
			nd->hijoizq = nuevoNodo(dato);
		}
		else
		{
			insertarNodo(nd->hijoizq, dato);
		}
	}
}

void busqueda(struct node *raiz, int dato)
{
	int l = 0;
	if (raiz == NULL)
		return 0;
	if (raiz->dato == dato)
		return raiz->lv;
	l = search(raiz->hijoizq, dato);
	if (l > 0)
		return l;
	l = search(raiz->hijoder, dato);
	if (l > 0)
		return l;
	return 0;
}