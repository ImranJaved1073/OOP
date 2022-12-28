#ifndef SET_H
#define SET_H

#include <iostream>
using namespace std;

template <class T>
class Set
{
	T* arr;
	int size;
	int index;
	void resize();

public:
	Set(int = 10);
	~Set();
	int getLength() const;
	int getIndex() const;
	T getElement(int) const;
	T& operator[](const int);
	//MyArray& operator=(const MyArray& a);
	void insert(T);
	void remove(T);
	bool isMember(T);
	bool isSubset(const Set<T>&);

	Set<T> U(const Set<T>&, const Set<T>&);
	Set<T> common(const Set<T>&, const Set<T>&);
	Set<T> difference(const Set<T>&, const Set<T>&);
	Set<T> operator-(const Set<T>&);
	Set<T> operator+(const Set<T>&);
	bool operator==(const Set<T>&);
	bool operator!=(const Set<T>&);
	
};

template <class T>
void Set<T>::resize()
{
	size++;
	T* temp = new T[size];
	for (int i = 0; i < size; i++)
	{
		if (i != size - 1)
			temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}

template <class T>
Set<T>::Set(int s)
{
	size = s;
	index = 0;
	arr = new T[size];
}

template <class T>
Set<T>::~Set()
{
	if (arr)
	{
		delete[] arr;
		arr = nullptr;
	}
}

template <class T>
int Set<T>::getLength() const
{
	return size;
}

template <class T>
int Set<T>::getIndex() const
{
	return index;
}

template <class T>
T Set<T>::getElement(int i) const
{
	return arr[i];
}

template <class T>
T& Set<T>::operator[](const int index)
{
	return arr[index];
}
//MyArray& operator=(const MyArray& a);

template <class T>
void Set<T>::insert(T item)
{
	if (index == size)
		resize();
	arr[index++] = item;
}

template <class T>
void Set<T>::remove(T item)
{
	//bool flag == false;
	for (int i = 0; i < index; i++)
	{
		if (arr[i] == item)
		{
			for (int j = i; j < index - 1; j++)
				arr[j] = arr[j + 1];
			index--;
			break;
		}
	}
}

template <class T>
bool Set<T>::isMember(T item)
{
	for (int i = 0; i < index; i++)
	{
		if (arr[i] == item)
			return true;
	}
	return false;
}

template <class T>
Set<T> Set<T>::U(const Set<T>& lhs, const Set<T>& rhs)
{
	Set<T> temp;
	for (int i = 0; i < lhs.index; i++)
	{
		temp.insert(lhs.arr[i]);
	}
	for (int i = 0; i < rhs.index; i++)
	{
		if (!temp.isMember(rhs.arr[i]))
			temp.insert(rhs.arr[i]);
	}
	return temp;
}

template <class T>
Set<T> Set<T>::common(const Set<T>& lhs, const Set<T>& rhs)
{
	Set<T> temp;
	for (int i = 0; i < lhs.index; i++)
	{
		if (this->isMember(rhs.arr[i]))
			temp.insert(rhs.arr[i]);
	}

	return temp;
}

template <class T>
Set<T> Set<T>::difference(const Set<T>& lhs, const Set<T>& rhs)
{
	Set<T> temp;
	for (int i = 0; i < lhs.index; i++)
	{
		temp.insert(lhs.arr[i]);
	}
	for (int i = 0; i < rhs.index; i++)
	{
		if (temp.isMember(rhs.arr[i]))
			temp.remove(rhs.arr[i]);
	}
	return temp;
}

template <class T>
Set<T> Set<T>::operator-(const Set<T>& rhs)
{
	return difference(*this, rhs);
}

template <class T>
Set<T> Set<T>::operator+(const Set<T>& rhs)
{
	return U(*this, rhs);
}

template <class T>
bool Set<T>::operator==(const Set<T>& lhs)
{
	if (this->index != lhs.index)
		return false;
	for (int i = 0; i < lhs.index; i++)
	{
		if (!this->isMember(lhs.arr[i]))
			return false;
	}
	return true;
}

template <class T>
bool Set<T>::operator!=(const Set<T>& lhs)
{
	return !(*this == lhs);
}

template <class T>
bool Set<T>::isSubset(const Set<T>& lhs)
{
	int count = 0;
	if (this->index > lhs.index)
		return false;
	for (int i = 0; i < this->index; i++)
	{
		if (this->isMember(lhs.arr[i]))
			count++;
	}
	if (count == this->index)
		return true;
	return false;
}

#endif // !SET_H

