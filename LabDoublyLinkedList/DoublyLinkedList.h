#pragma once

#include "stdafx.h"
#include "Nodo.h"
#include <iostream>
using namespace std;

template<class T>
class DoublyLinkedList {

	template<class T>
	friend ostream & operator<<(ostream &, DoublyLinkedList<T> &);

private:
	Nodo<T> *inicio;
	Nodo<T> * final;

public:
	Lista() {
		inicio = NULL;
		final = NULL;
	}
	
	virtual ~Lista() {
	}

	void insertarInicio(T elemento) {
		if (inicio == NULL) {
			this->inicio = elemento;
			this->final = elemento;
		}
		else {
			Nodo<T> * temp = new Nodo<T>(elemento);
			temp->siguiente = this->inicio;
			if (this->inicio != NULL) {
				this->inicio->anterior = temp;
			}
			this->inicio = temp;
		}
	}
	
	
	void insertarFinal(T elemento) {
		if (final == NULL) {
			this->inicio = elemento;
			this->final = elemento;
		}
		else {
			Nodo<T> * temp = new Nodo<T>(elemento);
			this->final->siguiente = temp;
			temp->anterior = this->final;
			this->final = temp;
		}
	}
	
	
	void insertarElemento(T elemento, int posicion) {
		Nodo<T> * temp1 = new Nodo<T>(this->inicio);
		while (--posicion != 0) {
			temp1 = temp1->siguiente;
		}
		Nodo<T> * temp2 = new Nodo<T>(temp1->siguiente);
		Nodo<T> * temp = new Nodo<T>(elemento);
		temp->siguiente = temp2;
		temp2->anterior = temp;
		temp1->siguiente = temp;
		temp->anterior = temp1;
	}

	
	void eliminarInicio() {
		Nodo<T> * temp = new Nodo<T>(this->inicio);
		this->inicio = this->inicio->siguiente;
		delete temp;
		if (this->inicio != NULL) {
			this->inicio->anterior = NULL;
		}
	}
	
	
	void eliminarFinal() {
		Nodo<T> * temp = new Nodo<T>(this->final);
		this->final = this->final->anterior;
		this->final->siguiente = NULL;
		delete temp;
	}
	
	
	void eliminarElemento(int posicion) {
		Nodo<T> * cur = new Nodo<T>(this->inicio);
		while (--posicion != 0) {
			cur = cur->siguiente;
		}
		Nodo<T> * aEliminar = new Nodo<T>(cur->siguiente);
		Nodo<T> * temp = new Nodo<T>(aEliminar->siguiente);
		delete aEliminar;
		cur->siguiente = temp;
		temp->anterior = cur;
	}
	
	
	void imprimir(ostream& out) {
		Nodo<T> * aImprimir = new Nodo<T>(this->inicio);
		while (aImprimir != NULL) {
			out << aImprimir;
			aImprimir = aImprimir->siguiente;
		}
};

template<class T>
ostream & operator<<(ostream & out, DoublyLinkedList<T> & l) {
	l.imprimir(l.inicio, out);
	return out;
}
