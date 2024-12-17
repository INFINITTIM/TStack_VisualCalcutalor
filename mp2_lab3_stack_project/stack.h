#pragma once

#include <iostream>

template<class T>
struct Node {
	T val;
	Node<T>* pNext;
};

template<class T>
class LLStack {
	Node<T>* pFirst;//храним значения стека в списке инвертировано,т.е. pFirst указывает на верхний элемент стека
public:
	LLStack() { pFirst = nullptr; }

	LLStack(const LLStack<T>& s) {
		Node<T>* stmp = s.pFirst;//делаем ссылку на первый элемент второго стека, чтоб оп нему пройтись
		if (stmp != nullptr) {
			pFirst = new Node<T>;//переносим первую ячейку
			pFirst->val = stmp->val;
			pFirst->pNext = nullptr;

			stmp = stmp->pNext;//переход на вторую ячейку

			Node<T>* prev = pFirst;//нам нужно хранить ссылку на пред. ячейку, чтобы подцеплять друг за другом указатели
			while (stmp != nullptr) {
				Node<T>* newnode = new Node<T>;
				newnode->val = stmp->val;
				newnode->pNext = nullptr;

				prev->pNext = newnode;//подцепляем указатели

				stmp = stmp->pNext;
				prev = prev->pNext;
			}
		}
		else {
			pFirst = nullptr;
		}
	}

	~LLStack() {
		while (pFirst != nullptr) {
			Node<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}
	//--------------------interface------------------------------
	bool isEmpty() const { return pFirst == nullptr; }

	bool isFull() const {
		try {
			Node<T>* tmp = new Node<T>;//пытаемся выделить память под новую ячейку
			delete tmp;
			return false;
		}
		catch (std::bad_alloc e) {
			return true;
		}
	}

	void push(T val) {
		try {
			Node<T>* tmp = new Node<T>;
			tmp->val = val;
			tmp->pNext = pFirst;
			pFirst = tmp;
		}
		catch (std::bad_alloc e) {
			throw - 1;
		}
	}

	T pop() {
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

	T top() {
		if (pFirst != nullptr)
			return pFirst->val;
		else
			throw - 1;
	}

	void clr() {
		while (pFirst != nullptr) {
			Node<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}

	bool operator==(const LLStack<T>& s) const {
		if (this == &s) return true;

		Node<T>* tmp = pFirst;//два указателя для того, чтоб пробегаться по двум стекам
		Node<T>* stmp = s.pFirst;

		while (stmp != nullptr && tmp != nullptr) {//пробег, пока один из стеков не закончится
			if (tmp->val != stmp->val)
				return false;
			tmp = tmp->pNext;
			stmp = stmp->pNext;
		}

		return tmp == stmp;//если в одном из стеков что-то осталось, то они точно не равны, см. ниже
		/*
		* if(tmp != stmp) - разные размеры стеков
		*	return false;
		* return true;
		*/
	}

	bool operator !=(const LLStack<T>& s) const {
		return (!(*this == s));
	}

	LLStack<T>& operator=(const LLStack<T>& s) {
		if (this == &s) return *this;
		//удаляем все звенья
		while (pFirst != nullptr) {
			Node<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
		//переносим значения из правого стека
		Node<T>* stmp = s.pFirst;
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
};
