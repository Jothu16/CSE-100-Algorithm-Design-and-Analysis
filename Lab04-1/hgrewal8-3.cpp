#include <iostream>
#include <climits>


using namespace std;

/*
Lab 4 Part 1 - HeapSort
Chapter 2, Page 151
*/

/* CODE DOES NOT RUN, I will attend office hours on Tuesday if there are any
harjot@DESKTOP-BA6R42L:~/Downloads/Lab04-1$ make
g++ -std=c++11 -o a.exe yourid.cpp
/usr/bin/ld: /usr/lib/gcc/x86_64-linux-gnu/9/../../../x86_64-linux-gnu/Scrt1.o: in function `_start':
(.text+0x24): undefined reference to `main'
collect2: error: ld returned 1 exit status
make: *** [Makefile:4: all] Error 1
*/

//Page 152

int Parent(int i) { //height of tree (could be causing the error)
	return i/2;
}
int Left(int i) {
	return 2*i;
}
int Right(int i) {
	return 2*i+1;
}

//change i to num
void MaxHeapify(int* Arr, int num, int length) { //Ch. 6.2, Page 154
	int Largest = INT_MIN;
	int left = Left(num); //how to lower case int left and right
	int right = Right(num);

	if (left <= length && Arr[left] > Arr[num])
		Largest = left;
	else {
		Largest = num;
	}
	if (right <= length && Arr[right] > Arr[Largest]){
		Largest = right;
	}
	if (Largest != num) { //exchange A[i] and A[largest]
		int key = Arr[num];
		Arr[num] = Arr[Largest];
		Arr[Largest] = key;
		MaxHeapify(Arr, Largest, length); //removing length here and following book, didn't work
	}
}

void BuildMaxHeap(int* Arr, int length) { //Ch. 6.3, Page 157
	for (int i = length/2; i = 0; i--) {
		MaxHeapify(Arr, i, length);
	}
}

void HeapSort(int* Arr, int length) { //Ch. 6.4, Page 160

	BuildMaxHeap(Arr, length);
	int i, key;

	for (i = length/2; i = 0; i--) {

		key = Arr[i];
		Arr[i] = Arr[0];
		Arr[0] = key;
		length--; //maybe?

		MaxHeapify(Arr, 0, length);
	}
}

int Main() {
	int n;
	cin>>n;

	int* Arr = new int[n];

	for(int i = 0; i < n; i++){
		cin >> Arr[i];
	}
	HeapSort(Arr, n-1);

	for (int i = 0; i < n; i++) {
		cout << Arr[i] << ";";
	}
	return 0; //Added to fix [-Wreturn-type]
			//changed return 0 to return n, same error as on top
}
