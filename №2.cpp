#include<iostream>				
#include<ctime>				
using namespace std;
void print_array(int** array, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

}

void random_array(int** array, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			array[i][j] = rand() % 90 + 10;
		}
	}
}

int matrix_multi(int** A, int** B, int** C, int n, int m, int n1, int m1) {

	for (int i = 0; i < n; i++)                                  			
		for (int j = 0; j < m1; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < m; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	return 0;
}

int main() {
	int n, m, n1, m1;
	cout << "Enter the number of rows of the  matrix A" << endl;
	cin >> n;
	cout << "Enter the number of columns of the  matrix A" << endl;
	cin >> m;
	int** masA = new int* [n];
	for (int i = 0; i < n; i++) {
		masA[i] = new int[m];
	}
	random_array(masA, n, m);
	cout << "Matrix A: " << endl;
	print_array(masA, n, m);

	cout << "Enter the number of rows of the  matrix B" << endl;
	cin >> n1;
	cout << "Enter the number of columns of the  matrix B" << endl;
	cin >> m1;
	int** masB = new int* [n1];
	for (int i = 0; i < n1; i++) {
		masB[i] = new int[m1];
	}
	random_array(masB, n1, m1);
	cout << "Matrix B: " << endl;
	print_array(masB, n1, m1);

	int** masC = new int* [n];                 		
	for (int i = 0; i < n; i++) {              
		masC[i] = new int[m1];
	}


	if (m != n1)
	{
		cout << "Multiplication is impossible\n";
	}

	if (m == n1)
	{
		matrix_multi(masA, masB, masC, n, m, n1, m1);
		cout << "Matrix C: " << endl;
		print_array(masC, n, m1);
	}

	return 0;
}
