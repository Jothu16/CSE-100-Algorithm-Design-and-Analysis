	#include <iostream>
	#include <vector>

	using namespace std;
	
	/*
	UPDATE: Went to Ghazal's office hours and she helped me fix my issues. Thank you!
	*/


	/*
	CODE DOES NOT WORK, same error as last time so i can't check whats wrong because i cant compile.

	g++ -std=c++11 -o a.exe hgrewal8.cpp
	/usr/bin/ld: /usr/lib/gcc/x86_64-linux-gnu/9/../../../x86_64-linux-gnu/Scrt1.o: in function `_start':
	(.text+0x24): undefined reference to `main'
	collect2: error: ld returned 1 exit status
	make: *** [Makefile:4: all] Error 1
	*/



	/* 
	Lab 5 Radix Sort Ch. 8.3 Page 197
	Chapter 8, Page 191

	Resource for Vectors besides textbook: https://www.cplusplus.com/reference/vector/vector/
	*/

	const int length = 11; //each vector consits of 11 numbers
	vector<vector<int>> Arr,B;

	void CountingSort(int r, int Size) { //Chapter 8.2, Page 195
		int k= 5;

		vector<int> Counting(k,0);

		for(int i = 1; i <= Size; i++)
			Counting[Arr[i][r]]++;

		for( int i = 1; i < k; i++) 
			Counting[i] += Counting[i-1];

		for (int i = Size; i > 0; i--) {
			for (int j=1; j < length; j++)
				B[Counting[Arr[i][r]]][j] = Arr[i][j];
			Counting[Arr[i][r]] --;
		}

		for(int i = 1; i <= Size; i++)
			for (int j=1; j< length; j++)
				Arr[i][j] = B[i][j];
	}

	//Radix_Sort Function
	void RadixSort(int Size){ //Chapter 8.3, Page 197
		int i;

		for ( i = length-1; i >= 1; i--){
			CountingSort(i, Size);
		}
	}

	int main() {

		int Bar, Size;
		cin >> Size;

		int n = 0;

		//Arr is input array and B is output array for CountingSort()
		Arr.resize(Size+1);
		B.resize(Size+1);

		for (int i = 1; i <= Size; i++){
			Arr[i].push_back(0);
			B[i].push_back(0);
			for (int j = 1; j < length; j++) {
				cin >> Bar;
				Arr[i].push_back(Bar);

				// initialize output array B
				B[i].push_back(0);
			}
		}
		
		RadixSort(Size);
		for (int i = 1; i <= Size; i++) {
			for (int j = 1; j < length; j++) {
				cout << Arr[i][j] << ";";
			}
			cout << endl;
		}
	}
