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



int find_max_element_row(int* array, int size)
{
	int max = array[0];
	for (int i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return(max);
}

int find_min_index_row(int* array, int size)
{
	int min = 0;
	for (int i = 1; i < size; i++)
		if (array[i] < array[min])
			min = i;
	return(min);
}

int main() {
	int n, m;
	cin >> n >> m;
	int** mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];
	}
	random_array(mas, n, m);
	print_array(mas, n, m);
	for (int i = n - 1; i >= 1; i--)
	{
		int tmp = find_min_index_row(mas[i], m);
		mas[i][tmp] = find_max_element_row(mas[i - 1], m);
	}
	cout << endl;

	print_array(mas, n, m);
	return 0;

}
