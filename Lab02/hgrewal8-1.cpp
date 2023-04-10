#include <iostream>
using namespace std;

#define MAX_INT 2147483647

/*
Attended Ghazal Office Hours Monday 2/8 @ 10:30AM 
I had an issue where my testcases ran 0;0;0;1;5 when 5;4;3;2;1;5 were the inputs using ./a.exe

*/

//Merge Page 31
void Merge (int* Arr, int parent, int queue, int rant) {
	int n1 = queue - parent + 1;
	int n2 = rant - queue;

	int* L = new int[n1+1]; //let L[1...n1 +1] and R[1...n2 +1] be new arrays
	int* R = new int [n2+1];

	for (int i=0; i<n1; i++) {
		L[i] = Arr[parent + i];//Ghazal: I updated this line
	}

	for (int j=0; j<n2; j++) {
		R[j] = Arr[queue + j+1];//Ghazal
			//Originally I had j-1 here (I realize my mistake)
	}

	int i =0; //left pointer
	int j =0; //right pointer
	
        L[n1] = MAX_INT;  // Ghazal: line 8 of Merge algorith textbook page 31
        R[n2] = MAX_INT;
	
        for (int k = parent; k<=rant; k++) { //changed queue to parent
		//if (i<n1 && j<n2) { // Ghazal: why?
			//Harjot: Thought if i combined n1 & n2, it would simplify the code just through the though process. Lol i was up late coding it on Friday Night
			if (L[i] <= R[j]) {
				Arr[k] = L[i];
				i++;
			}
			else {
				Arr[k] = R[j];
				j++;
			}
		//} //
	}
}

//MergeSort Page 34
void MergeSort (int* Arr, int parent, int rant) {
	if (parent<rant) {
		int queue = (parent + rant) /2; //removed queue from void and int here
		MergeSort (Arr, parent, queue);
		MergeSort (Arr, queue + 1, rant);
		Merge (Arr, parent, queue, rant);
	}
}

int main (){
	int n;
	cin>>n;
	int* Arr = new int[n];

	for (int i=0; i<n; i++) {
		cin>>Arr[i];
	}

	MergeSort(Arr, 0, n-1); //added 0 

	for (int i=0; i<n; i++) { //print
		cout<< Arr[i] << ";";
	}
}
