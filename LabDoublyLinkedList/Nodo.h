#pragma once

template<class T>
class Nodo {

	template <class T>
	friend class DoublyLinkedList;

protected:

	T actual;
	Nodo<T> *anterior, *siguiente;

public:

	Nodo(T i) {

		this->actual = i;
		anterior = NULL;
		siguiente = NULL;

	}

	~Nodo() {
	}

};