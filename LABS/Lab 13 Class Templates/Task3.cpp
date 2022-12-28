#include <iostream>
#include <string>


using namespace std;

template <class T>
class MyArray
{
	int size;
	int index;
	T* arr;
	void resize();
public:
	MyArray(int s = 10);
	~MyArray();
	int getLength() const;
	int getIndex() const;
	void setElement(T val);
	T getElement(int i) const;
	T& operator[](const int index);
	MyArray& operator=(const MyArray& a);
	T sort();
};

template <class T>
void MyArray<T>::resize()
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
MyArray<T>::MyArray(int s)
{
	size = s;
	index = 0;
	arr = new T[size];
}

template <class T>
MyArray<T>::~MyArray()
{
	if (arr)
	{
		delete[] arr;
		arr = nullptr;
	}
}

template <class T>
int MyArray<T>::getLength() const
{
	return size;
}
template <class T>
int MyArray<T>::getIndex() const
{
	return index;
}
template <class T>
void MyArray<T>::setElement(T val)
{
	if (index >= size)
	{
		resize();
	}
	arr[index] = val;
	index++;
}
template <class T>
T MyArray<T>::getElement(int i) const
{
	if (i > -1 && i < size)
	{
		return arr[i];
	}
	else
	{
		cout << "Index Out of bound" << endl;
		return -1;
	}
}
template <class T>
T& MyArray<T>::operator[](const int index)
{
	return arr[index];
}

template <class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& a)
{
	if (this != &a)
	{
		if (arr)
		{
			delete[] arr;
			arr = nullptr;
		}
		size = a.size;
		index = a.index;
		arr = new T[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = a.arr[i];
		}
	}
	return *this;
}

template <class T>
T MyArray<T>::sort()
{
	T temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return *arr;
}
template<>
string MyArray<string>::sort()
{
	string temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return *arr;
}

int main()
{
	MyArray<int> a1(5);
	for (int i = 0; i < a1.getLength(); i++)
	{
		int val;
		cout << "Enter value: ";
		cin >> val;
		a1.setElement(val);
	}
	cout << "Original Array:\n";
	for (int i = 0; i < a1.getLength(); i++)
	{
		cout << a1[i] << " ";
	}
	cout << "Sorted Array:\n";
	a1.sort();
	for (int i = 0; i < a1.getLength(); i++)
	{
		cout << a1[i] << " ";
	}
	
	MyArray<string> s1(5);
	cin.ignore();
	for (int i = 0; i < s1.getLength(); i++)
	{
		string s;
		cout << "Enter string: ";
		getline(cin, s);
		s1.setElement(s);
	}
	cout << "Original string Array:\n";
	for (int i = 0; i < s1.getLength(); i++)
	{
		cout << s1[i] << endl;
	}
	cout << "Sorted string Array in alphabetical order:\n";
	s1.sort();
	for (int i = 0; i < s1.getLength(); i++)
	{
		cout << s1[i] << endl;
	}
}