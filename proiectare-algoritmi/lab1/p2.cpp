#include<iostream>
using namespace std;

int main(){
	int a[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	
	int n = 3;
	
	int temp;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			temp = a[j][i];
			a[j][i] = a[i][j];
			a[i][j] = temp;
		}
	}
	
	for(int i = 0; i < n/2; i++){
		for(int j = 0; j < n; j++){
			temp = a[i][j];
			a[i][j] = a[n - i - 1][j];
			a[n - i - 1][j] = temp;
		}
		
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j] << " "; 
		}
		cout << endl;
	}
}
