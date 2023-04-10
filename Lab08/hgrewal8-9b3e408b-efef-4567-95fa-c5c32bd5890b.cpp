	#include <iostream>
	#include <stdio.h>

	using namespace std;


	void printoptimal(int** s, int i, int j) { //Page 377 
		if(i == j)
			cout << "A" << i - 1;
		else{
			cout << "(";
			printoptimal(s, i, s[i][j]);
			printoptimal(s, s[i][j] + 1, j);
			cout << ")";
		}
		}

		/* Found it easier to do the print function first, but was curious how to use go to and move it
		LOOP:
			dlkfnmskf
			klanfna
			lkandfl
			goto LOOP*/

		/* PRINT:
			if{
			}
			else{
				cout
				j=[i][j]
				got to print
				i = s[i][j]+1

				goto print
				cout
			}
		*/

	void MatrixChain(int* p, int n) { // Page 375
		int **m = new int*[n], **s = new int*[n];
		int j, q;

		for(int i = 1; i <n; i++) {
			m[i] = new int[n];
			s[i] = new int[n];
			m[i][i] = 0;
		}
		for (int c = 2; c < n; c++) { 
		for (int i = 1; i < n-c+1; i++) {
			j = i + c-1;
			m[i][j] = 123456789;

			for (int k = i; k <= j-1; k++) {
				q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
				if (q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
			}
			}
			} //dont need to return
			}

		cout<< m[1][n-1] <<endl;
		printoptimal(s, 1,n-1);
		}

	int main() {
		int n;
		cin>>n;

		int *Arr = new int[n +1];

		for(int i = 0; i<= n; i++)
			cin>> Arr[i];
		MatrixChain(Arr, n + 1);
		cout<<endl;

		}