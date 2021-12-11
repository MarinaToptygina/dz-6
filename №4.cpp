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
			array[i][j] = rand() % 31 - 15;
		}
	}
}
void swap_row_column_elements(int** array, int n, int m)
{
	int flag;
	int min = 0;
	int i_min = 0;
	int j_min = 0;
	flag = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (array[i][j] > 0) {
				if (!flag || array[i][j] < min) {
					flag = true;
					min = array[i][j];
					i_min = i;
					j_min = j;
				}
			}

		}

			
	cout << "min positive element" << endl;
	cout << "array " << "[" << i_min << "]" << "[" << j_min << "]" << "=" << min << endl;
	cout << endl;
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		tmp = array[i][j_min];
		array[i][j_min] = array[i_min][i];
		array[i_min][i] = tmp;
	}

}


int main() {
	srand(time(NULL));
	int n;
	cin >> n;
	int** mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[n];
	}
	random_array(mas, n, n);
	print_array(mas, n, n);

	swap_row_column_elements(mas, n, n);
	print_array(mas, n, n);

	for (int i = 0; i < n; i++)
		delete[] mas[i];         	
	delete[] mas;                

	return 0;

}
