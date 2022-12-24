#include "Box.h"
#include <iostream>
using namespace std;

void swap(int&, int&);
void sortArray(Box*, const int);

int main()
{
	int size, input;
	cout << "Enter size of Boxes: ";
	cin >> size;
	Box* boxes = new Box[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Enter length of box# " << i + 1 << ": ";
		cin >> input;
		while (input < 0)
		{
			cout << "\nERROR: Invalid length! Enter again.\n";
			cin >> input;
		}
		boxes[i].setLength(input);
		
		cout << "Enter width of box# " << i + 1 << ": ";
		cin >> input;
		while (input < 0)
		{
			cout << "\nERROR: Invalid width! Enter again.\n";
			cin >> input;
		}
		boxes[i].setWidth(input);
		
		cout << "Enter height of box# " << i + 1 << ": ";
		cin >> input;
		while (input < 0)
		{
			cout << "\nERROR: Invalid height! Enter again.\n";
			cin >> input;
		}
		boxes[i].setHeight(input);
	}
	
	//print volume of boxes
	for (int i = 0; i < size; i++)
	{
		cout << "Volume of box " << i + 1 << ": " << boxes[i].getVloume() << endl;
	}

	sortArray(boxes, size);

	cout << "In Sorted Order:\n";
	for (int i = 0; i < size; i++)
	{
		cout << "Volume of box " << i + 1 << ": " << boxes[i].getVloume() << endl;
		cout << "Length:" << boxes[i].getLength()<<endl;
		cout << "Width:" << boxes[i].getWidth() << endl;
		cout << "Height:" << boxes[i].getHeight()<<endl;
	}

	delete[] boxes;
	boxes = nullptr;

}


void sortArray(Box* boxArray, const int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int index = i + 1; index < size; index++)
		{
			if (boxArray[i].getVloume() > boxArray[index].getVloume())
			{
				swap(boxArray[i], boxArray[index]);
			}
		}
	}
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}