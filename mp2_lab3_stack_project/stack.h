#pragma once
#include <iostream>

template <class T>
class TStack
{
	int maxsize;
	int num_last_element;
	T* pMem;
public:
	TStack(int _maxsize = 10);
	TStack(const TStack<T>& other_stack);
	~TStack();

	TStack& operator=(const TStack<T>& other_stack);
	bool operator==(const TStack<T>& other_stack) const;
	bool operator!=(const TStack<T>& other_stack) const;

	bool Empty() const;
	bool Full() const;

	T Pop(); // вз€тие элемента с вершины стека
	void Push(T element); // добавить элемент в стек (в вершину стека) 
	T Top() const;
	void clear();
};

template <class T>
TStack<T>::TStack(int _maxsize)
{
	if (_maxsize < 0)
		throw - 1;
	maxsize = _maxsize;
	num_last_element = -1;
	pMem = new T[maxsize];
}

template <class T>
TStack<T>::~TStack()
{
	delete[] pMem;
}

template <class T>
TStack<T>::TStack(const TStack<T>& other_stack)
{
	maxsize = other_stack.maxsize;
	num_last_element = other_stack.num_last_element;
	pMem = new T[maxsize];
	for (int i = 0; i <= num_last_element; i++)
		pMem[i] = other_stack.pMem[i];
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& other_stack)
{
	if (this == &other_stack) //провер€ем что эти два стека не €вл€ютс€ одним и тем же стеком
		return *this;
	if (maxsize != other_stack.maxsize) // если размеры стэков различны то берем и удал€ем пам€ть нашего стека,
	{                                  // берЄм размер другого стэка и приравниваем его к нашего стеку, а потом 
		delete[] pMem;                 // уже выдел€ем пам€ть дл€ стека нужного размера
		maxsize = other_stack.maxsize;
		pMem = new T[maxsize];
	}
	num_last_element = other_stack.num_last_element;
	for (int i = 0; i <= num_last_element; i++) // записываем значени€ другого стека в свой стек 
	{
		pMem[i] = other_stack.pMem[i];
	}
}

template <class T>
bool TStack<T>::operator==(const TStack<T>& other_stack) const
{
	if (maxsize != other_stack.maxsize)
		return false;
	if (num_last_element != other_stack.num_last_element)
		return false;
	for (int i = 0; i <= num_last_element; i++)
	{
		if (pMem[i] != other_stack.pMem[i])
			return false;
	}
	return true;
}

template <class T>
bool TStack<T>::operator!=(const TStack<T>& other_stack) const
{
	return (!(*this == other_stack));
}

template <class T>
bool TStack<T>::Empty() const
{
	if (num_last_element == -1)
		return true;
	return false;
}

template <class T>
bool TStack<T>::Full() const
{
	if (num_last_element == maxsize)
		return true;
	return false;
}

template <class T>
T TStack<T>::Pop()
{
	if (this->Empty())
		throw - 1;
	T element_on_the_top = pMem[num_last_element];
	num_last_element--;
	return element_on_the_top;
}

template <class T>
void TStack<T>::Push(T element)
{
	if (this->Full())
		throw - 1;
	pMem[++num_last_element] = element;
}

template <class T>
T TStack<T>::Top() const
{
	return pMem[num_last_element];
}

template <class T>
void TStack<T>::clear()
{
	num_last_element = -1;
}
