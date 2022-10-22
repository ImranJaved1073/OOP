#include <iostream>
using namespace std;
char* left(const char* target, const int count);
void destructor(char*& p);
int main()
{
	int count = 0;
	int size = 0;
	cout << "Enter size of string:";
	cin >> size;
	char* arr = new char[size];
	cin.ignore();
	cin.clear();
	cout << "Enter String= ";
	cin.getline(arr, size);
	cout << "Enter count:";
	cin >> count;
	while (count > size)
	{
		cout << "Out of Range value!Enter count again so that count must be smallar than size.";
		cin >> count;
	}
	char* target = left(arr, count);
	for (int i = 0; i < count; i++)
	{
		cout << target[i];
	}
	destructor(arr);
	destructor(target);
}
char* left(const char* target, const int count)
{
	char* arr = new char[count];
	int i = 0;
	while (i < count)
	{
		arr[i] = target[i];
		i++;
	}
	return arr;
}

void  destructor(char*& p)
{
	delete[] p;
	p = nullptr;
}
