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
					
					
int find_min(int** array, int n, int m) {					
	int i_min = 0, j_min = 0;				
	for (int i = 0; i < n; i++) {				
		for (int j = 0; j < m; j++) {			
			if (array[i][j] < array[i_min][j_min]) {		
				i_min = i;	
				j_min = j;	
			}		
		}			
	}				
	printf("array[%d][%d]=%d", i_min, j_min, array[i_min][j_min]);				
	return array[i_min][j_min];				
					
}					
					
void row_kolomn(int** mas,  int n, int m)					
{					
	int i_min = 0, j_min = 0;				
	for (int i = 0; i < n; i++) {				
		for (int j = 0; j < m; j++) {			
			if (mas[i][j] < mas[i_min][j_min]) {		
				i_min = i;	
				j_min = j;	
			}		
		}			
	}				
	printf("masA[%d][%d]=%d", i_min, j_min, mas[i_min][j_min]);				
					
	cout << endl;				
					
	for (int i = i_min; i < n - 1; i++)				
		mas[i] = mas[i + 1];			
	for (int i = 0; i < n - 1; i++) {				
		for (int j = j_min; j < m - 1; j++) {			
			mas[i][j] = mas[i][j + 1];		
		}			
	}				
	n--;				
	m--;				
					
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
	cout << endl;				
	row_kolomn(mas,  n, m);				
	print_array(mas, n-1, m-1);				
	for (int i = 0; i < n; i++)				
		delete[] mas[i];         			
	delete[] mas;               				
					
	return 0;				
}					
					
