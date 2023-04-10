#include <iostream>
using namespace std;
//Attended Ghazal's Office Hours on 2/1
//my t1 file was incorrect, also helped me fix code

//setup print first
void PrintSort(int* printer, int sort) {
	for(int k=0; k<sort; k++) {
		cout<< printer[k] <<";";
	}
	}

//Chapter 2, Page 18 Insertion-Sort
//Translated from Pseudocode
void InsertionSort(int* Arr, int length) {
	int key, i;
	for (int j=1; j<length; j++) {
		key = Arr[j];
		i = j-1;

	while (i>=0 && Arr[i]>key) {
		Arr[i+1] = Arr[i];
		i--;
	}
	Arr[i+1] = key;
	PrintSort(Arr, j+1);
	cout<<endl;
	}
	}

int main() {
	int n;
	cin>>n;

	int* Arr = new int [n]; //Added to store (got rid of segmentation core dump)
//	cout<<"hi"<<endl;

	for(int i=0; i<n; i++) {
		cin>>Arr[i];
	}
	InsertionSort(Arr, n); //main fix, I was calling PrintSort instead of InsertionSort this entire time

	}
