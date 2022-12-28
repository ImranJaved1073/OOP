#include <iostream>
#include <string>
using namespace std;

template <class A>
A** productOfMatrices(A** mat1, A** mat2, int size1, int size2)
{
	A** product = new A * [size1];
	for (int i = 0; i < size1; i++)
	{
		product[i] = new A[size2];
		for (int j = 0; j < size2; j++)
		{
			product[i][j] = 0;
			for (int k = 0; k < size1; k++)
			{
				product[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	return product;
}

int main()
{
	cout << " 1. Integer" << endl;
	cout << " 2. Float " << endl;
	cout << " 3. Double " << endl;
	cout << " 4. Exit   " << endl;
	int choice;
	cout << " Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		cout << "Enter Matrix 1: " << endl;
		int** mat1 = new int* [3];
		for (int i = 0; i < 3; i++)
		{
			mat1[i] = new int[3];
			for (int j = 0; j < 3; j++)
			{
				cin >> mat1[i][j];
			}
		}

		cout << "Enter Matrix 2: " << endl;
		int** mat2 = new int* [3];
		for (int i = 0; i < 3; i++)
		{
			mat2[i] = new int[3];
			for (int j = 0; j < 3; j++)
			{
				cin >> mat2[i][j];
			}
		}

		int** product = productOfMatrices(mat1, mat2, 3, 3);
		cout << "Product of Matrices: " << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << product[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < 3; i++)
		{
			delete[] mat1[i];
			mat1[i] = nullptr;
		}
		delete[]mat1;
		mat1 = nullptr;

		for (int i = 0; i < 3; i++)
		{
			delete[] mat2[i];
			mat2[i] = nullptr;
		}
		delete[]mat2;
		mat2 = nullptr;
	}
	
	else if (choice == 2)
	{
		cout << "Enter Matrix 1: " << endl;
		float** mat1 = new float* [3];
		for (int i = 0; i < 3; i++)
		{
			mat1[i] = new float[3];
			for (int j = 0; j < 3; j++)
			{
				cin >> mat1[i][j];
			}
		}

		cout << "Enter Matrix 2: " << endl;
		float** mat2 = new float* [3];
		for (int i = 0; i < 3; i++)
		{
			mat2[i] = new float[3];
			for (int j = 0; j < 3; j++)
			{
				cin >> mat2[i][j];
			}
		}

		float** product = productOfMatrices(mat1, mat2, 3, 3);
		cout << "Product of Matrices: " << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << product[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < 3; i++)
		{
			delete[] mat1[i];
			mat1[i] = nullptr;
		}
		delete[]mat1;
		mat1 = nullptr;

		for (int i = 0; i < 3; i++)
		{
			delete[] mat2[i];
			mat2[i] = nullptr;
		}
		delete[]mat2;
		mat2 = nullptr;
	}

	else if (choice == 3)
	{
		cout << "Enter Matrix 1: " << endl;
		double** mat1 = new double* [3];
		for (int i = 0; i < 3; i++)
		{
			mat1[i] = new double[3];
			for (int j = 0; j < 3; j++)
			{
				cin >> mat1[i][j];
			}
		}

		cout << "Enter Matrix 2: " << endl;
		double** mat2 = new double* [3];
		for (int i = 0; i < 3; i++)
		{
			mat2[i] = new double[3];
			for (int j = 0; j < 3; j++)
			{
				cin >> mat2[i][j];
			}
		}

		double** product = productOfMatrices(mat1, mat2, 3, 3);
		cout << "Product of Matrices: " << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << product[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < 3; i++)
		{
			delete[] mat1[i];
			mat1[i] = nullptr;
		}
		delete[]mat1;
		mat1 = nullptr;

		for (int i = 0; i < 3; i++)
		{
			delete[] mat2[i];
			mat2[i] = nullptr;
		}
		delete[]mat2;
		mat2 = nullptr;
	}
	
	else if (choice == 4)
	{
		cout << "Thank you for using the program!" << endl;
		return 0;
	}
		
	else
	{
		cout << "Invalid choice!" << endl;
		return 0;
	}
}