	#include <iostream>
	#include <limits.h>
	#include <stdio.h>
	#include <vector>
	#include <tuple>

	using namespace std;

	/*Chapter 15.1, Page 358
	Page 363 Cut Rod
	Page 365 Memoized Cut Rod (Memoized proved to be difficult compared to bottom up)
	Page 366 Memoized Cut Rod Aux
	Page 366 Bottom Up Cut Rod (Simpler than Memoized)
	Page 369 Extended Bottom Up Cut Rod
	Reference: https://www.cplusplus.com/reference/vector/vector/
	Used my lab 12 from last semester as reference as well. 
	*/

	int BottomUpCutRod(int* parent, int n, vector<int> &Arr, vector<int> &r) { 
			//by adding & to the vectors, solved cocde

		if(n == 0) {
			return 0;
		} 
		
		if(Arr[n] >= 0) {
			return Arr[n];
		} 

		int queue = INT_MIN;

		for(int i =1; i <= n; i++) {
			int max = parent[i] + BottomUpCutRod(parent, n-i, Arr, r);
		
			if(max > queue){
				queue = max;
		
				r[n]=i;
		}
		}
		Arr[n] = queue;
		return queue;
		}

	void PrintCutRod(int n, vector<int> &r) {

		int i = n;

		while(i > 0) {
			cout<< r[i] << " ";
			i = i - r[i];
		}
	}

	int main (int argc, char const *argv[]) {

		int n;
		cin >> n;

		int* parent = new int[n+1];

		vector<int> Arr; 
		vector<int> r;

		Arr.resize(n+1);
		r.resize(n+1); //https://www.cplusplus.com/reference/vector/vector/resize/

		for(int i = 1; i <= n; i++) {

			cin >> parent[i];
			Arr[i] = INT_MIN;
			r[i] = INT_MIN;
		}

		cout<< BottomUpCutRod(parent, n, Arr, r) <<endl;

		PrintCutRod(n, r);

		cout<< "-1 ";

		}
