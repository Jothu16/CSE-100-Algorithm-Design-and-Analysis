#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h>

using namespace std;

/*CODE DOES NOT RUN - got the same error as in Lab04-1. Will attend office hours
harjot@DESKTOP-BA6R42L:~/Downloads/Lab04-2$ make
g++ -std=c++11 -o a.exe yourid.cpp
/usr/bin/ld: /usr/lib/gcc/x86_64-linux-gnu/9/../../../x86_64-linux-gnu/Scrt1.o: in function `_start':
(.text+0x24): undefined reference to `main'
collect2: error: ld returned 1 exit status
make: *** [Makefile:4: all] Error 1
*/

/*
Lab 04-2, Quick-Sort
Chapter 7, Page 170
RAND: http://www.cplusplus.com/reference/cstdlib/rand/
*/

int Partition(int* Arr, int parent, int length) { //Page 171
	int x = Arr[length];
	int num = parent -1; 
	int j, key;


	for (j = parent; j < length; j++) {
		if (Arr[j] <= x) {

			num++;

			key = Arr[num];
			Arr[num] = Arr[j]; //exchange A[i] with A[j]
			Arr[j] = key;
		}
	}
	key = Arr[num+1];
	Arr[num+1] = Arr[length];
	Arr[length] = key;

	return num+1;
}

int RandomPartition(int* Arr, int parent, int length) {

	srand(time(NULL));
							//reference: http://www.cplusplus.com/reference/cstdlib/rand/
	int num = parent + rand() % (parent - length); 

	int key = Arr[length];
	Arr[length] = Arr[num];
	Arr[num] = key;

	return Partition(Arr, parent, length);
}

void RandomQuickSort(int* Arr, int parent, int length) { //not an int, changed to void
	if (parent < length) {
		int q = RandomPartition(Arr, parent, length);
			RandomQuickSort(Arr, parent, q-1);
			RandomQuickSort(Arr, q+1, length);
	}
}

int Main() {
	int length;
	cin>>length;

	int* Arr = new int[length];

	for(int i = 0; i < length; i++) {
		cin >> Arr[i];
	}
	RandomQuickSort(Arr, 0, length-1);

	for (int i = 0; i < length; i++) {
		cout << Arr[i] << ";";
	}
	return 0;
}
