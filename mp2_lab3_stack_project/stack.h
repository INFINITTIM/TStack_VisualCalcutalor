#pragma once

#include <iostream>

template<class T>
struct Node {
	T val;
	Node<T>* pNext;
};

template<class T>
class LLStack {
	Node<T>* pFirst; // указатель на верхний элемент стека. Он хранит адрес первого узла (верхнего элемента)
public:
	LLStack();
	LLStack(const LLStack<T>& s);
	~LLStack();

	LLStack<T>& operator=(const LLStack<T>& s);
	bool operator==(const LLStack<T>& s) const;
	bool operator!=(const LLStack<T>& s) const;

	bool isEmpty() const;
	bool isFull() const;

	void push(T val);
	T pop();
	void clr();
	T top();	
};

template<class T>
LLStack<T>::LLStack() { 
	pFirst = nullptr; 
}

template<class T>
LLStack<T>::LLStack(const LLStack<T>& s) {
	Node<T>* stmp = s.pFirst; // создаем временный указатель stmp, который указывает на первый элемент стека s
	if (stmp != nullptr) { // если стек не пустой (stmp != nullptr), мы создаем новый узел для первого элемента
		pFirst = new Node<T>; // выделяем память для нового узла
		pFirst->val = stmp->val; // копируем значение из stmp->val
		pFirst->pNext = nullptr; // и устанавливаем pNext этого узла в nullptr, так как это будет последний элемент на данный момент

		stmp = stmp->pNext; // переходим к следующему узлу в исходном стеке

		Node<T>* prev = pFirst; // создаем указатель prev, который будет использоваться для связывания новых узлов
		while (stmp != nullptr) { //  цикл while продолжается до тех пор, пока есть элементы для копирования
			Node<T>* newnode = new Node<T>; // Внутри цикла создаем новый узел newnode
			newnode->val = stmp->val; // копируем значение из текущего узла stmp
			newnode->pNext = nullptr; // и устанавливаем его pNext в nullptr

			prev->pNext = newnode; // связываем предыдущий узел с новым узлом

			stmp = stmp->pNext; // переходим к следующему узлу в исходном стеке
			prev = prev->pNext; // и обновляем указатель prev на новый узел
		}
	}
	else {
		pFirst = nullptr; // если исходный стек пуст, устанавливаем pFirst в nullptr
	}
}

template<class T>
LLStack<T>::~LLStack() {
	while (pFirst != nullptr) {
		Node<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
}

template<class T>
bool LLStack<T>::operator==(const LLStack<T>& s) const {
	if (this == &s) return true;

	Node<T>* tmp = pFirst;
	Node<T>* stmp = s.pFirst;

	while (stmp != nullptr && tmp != nullptr) {
		if (tmp->val != stmp->val)
			return false;
		tmp = tmp->pNext;
		stmp = stmp->pNext;
	}

	return tmp == stmp;
}

template<class T>
bool LLStack<T>::operator!=(const LLStack<T>& s) const {
	return (!(*this == s));
}

template<class T>
LLStack<T>& LLStack<T>::operator=(const LLStack<T>& s) {
	if (this == &s) return *this;
	while (pFirst != nullptr) { //удаляем все звенья
		Node<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
	Node<T>* stmp = s.pFirst; //переносим значения из правого стека
	if (stmp != nullptr) {
		pFirst = new Node<T>;
		pFirst->val = stmp->val;
		pFirst->pNext = nullptr;

		stmp = stmp->pNext;

		Node<T>* prev = pFirst;
		while (stmp != nullptr) {
			Node<T>* newnode = new Node<T>;
			newnode->val = stmp->val;
			newnode->pNext = nullptr;

			prev->pNext = newnode;

			stmp = stmp->pNext;
			prev = prev->pNext;
		}
	}
	else {
		pFirst = nullptr;
	}
}

template<class T>
bool LLStack<T>::isEmpty() const { 
	return pFirst == nullptr; 
}

template<class T>
bool LLStack<T>::isFull() const {
	try {
		Node<T>* tmp = new Node<T>;
		delete tmp;
		return false;
	}
	catch (std::bad_alloc e) {
		return true;
	}
}

template<class T>
void LLStack<T>::push(T val) {
	Node<T>* tmp = new Node<T>;
	tmp->val = val;
	tmp->pNext = pFirst;
	pFirst = tmp;
}

template<class T>
T LLStack<T>::pop() {
	T res;
	if (pFirst != nullptr) {
		T res = pFirst->val;
		Node<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		return res;
	}
	else {
		throw - 1;
	}
}

template<class T>
T LLStack<T>::top() {
	if (pFirst != nullptr)
		return pFirst->val;
	else
		throw - 1;
}

template<class T>
void LLStack<T>::clr() {
	while (pFirst != nullptr) {
		Node<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
}

