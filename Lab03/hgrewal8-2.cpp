#include <iostream>
#include <climits>
#include <tuple>
using namespace std;

/*
Solving Max Subarray via Divide-and-conquer
Chapter 4, Page 65
/
to return more than 1 int, must use tuple, page 73
tuple: https://en.cppreference.com/w/cpp/utility/tuple 
*/
tuple<int, int, int>FindMaxCrossingSubarray (int* Arr, int low, int mid, int high) { //page 71
	int leftSum = INT_MIN;
	int rightSum = INT_MIN;
	int totalSum = 0;
	int maxLeft = 0;

	//Max leftsum
	for(int i = mid; i>=low; i--) { //switched i++ to --, fixed seg fault
		totalSum += Arr[i];

		if(totalSum >= leftSum) {
			leftSum = totalSum;
			maxLeft = i;
		}
	}
	totalSum = 0; 
	//Max rightsum
	int maxRight = 0;
	for(int j = mid+1; j<=high; j++) {
		totalSum += Arr[j];

		if(totalSum >= rightSum){
			rightSum = totalSum;
			maxRight = j;
		}
	}
	return make_tuple(maxLeft, maxRight, leftSum + rightSum);
}

tuple<int, int, int>FindMaxSubarray (int* Arr, int low, int high) { //page 72
	if (high == low) {
		return make_tuple(low, high, Arr[low]);
	}
	
		int mid = (low + high)/2;
	//}
		int leftLow, leftHigh, leftSum;
		int rightLow, rightHigh, rightSum;
		int crossLow, crossHigh, crossSum;
		
		/*
		tie takes whatever returns from the array and makes key pairs for it
		https://stackoverflow.com/questions/43762651/how-does-stdtie-work
		*/
		tie(leftLow, leftHigh, leftSum) = FindMaxSubarray(Arr, low, mid);
		tie(rightLow, rightHigh, rightSum) = FindMaxSubarray(Arr, mid+1, high);
		tie(crossLow, crossHigh, crossSum) = FindMaxCrossingSubarray(Arr, low, mid, high);


		if (leftSum >= rightSum && leftSum>= crossSum) {
			return make_tuple(leftLow, leftHigh, leftSum);
		}
		else if(rightSum >= leftSum && rightSum >= crossSum) {
				return make_tuple(rightLow, rightHigh, rightSum);
			}

				else return make_tuple(crossLow, crossHigh, crossSum); 
			}
		//}

//}

int main(){
	int n;
	cin >> n;
	int* Arr = new int[n];

	for(int i = 0; i<n; i++) {
		cin >> Arr[i];
	}
	//FindMaxSubarray(Arr, 0, n);

	int low, high, totalSum;
	tie(low, high, totalSum) = FindMaxSubarray(Arr, 0, n-1);
	cout << totalSum;
	
	}
