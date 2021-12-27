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
	cout << endl;
}

void random_array(int** array, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			array[i][j] = rand() % 90 + 10;
		}
	}
}

void swap_relative_to_side_diagonal(int** mas, int n, int m){
	int c = 0;
	for (int i = 0; i < n; i++)
		for(int j = 0; j <  n - i - 1; j++){
			c = mas[i][j];
			mas[i][j]=mas[n - j - 1][n - i - 1];
			mas[n - j - 1][n - i - 1] = c;
		}
}

int main() {
	int n, m;                              		
	cin >> n >> m;
	int** mas = new int* [n];             		
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];               
	}
	random_array(mas, n, m);
	cout << "Matrix A: " << endl; 
	
	print_array(mas, n, m);	
	
	swap_relative_to_side_diagonal(mas, n, m)
		
	cout << "Matrix B: " << endl;
	print_array(mas, n, m);
	for (int i = 0; i < n; i++)
		delete[] mas[i];         
	delete[] mas;    

	return 0;
}
