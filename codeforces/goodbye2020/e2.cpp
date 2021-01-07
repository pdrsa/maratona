// C++ program to find sum of bitwise OR 
// of all subarrays 

#include <bits/stdc++.h> 
using namespace std; 

// Function to find sum of bitwise OR 
// of all subarrays 
ll givesum(vector<ll> A, int n) 
{ 
	// Find max element of the array 
	int max = *max_element(A, A + n); 

	// Find the max bit position set in 
	// the array 
	int maxBit = log2(max) + 1; 

	int totalSubarrays = n * (n + 1) / 2; 

	int s = 0; 

	// Traverse from 1st bit to last bit which 
	// can be set in any element of the array 
	for (int i = 0; i < maxBit; i++) { 
		int c1 = 0; 

		// Vector to store indexes of the array 
		// with i-th bit not set 
		vector<int> vec; 

		int sum = 0; 

		// Traverse the array 
		for (int j = 0; j < n; j++) { 

			// Check if ith bit is not set in A[j] 
			int a = A[j] >> i; 
			if (!(a & 1)) { 
				vec.push_back(j); 
			} 
		} 

		// Variable to store count of subarrays 
		// whose bitwise OR will have i-th bit 
		// not set 
		int cntSubarrNotSet = 0; 

		int cnt = 1; 

		for (int j = 1; j < vec.size(); j++) { 
			if (vec[j] - vec[j - 1] == 1) { 
				cnt++; 
			} 
			else { 
				cntSubarrNotSet += cnt * (cnt + 1) / 2; 

				cnt = 1; 
			} 
		} 

		// For last element of vec 
		cntSubarrNotSet += cnt * (cnt + 1) / 2; 

		// If vec is empty then cntSubarrNotSet 
		// should be 0 and not 1 
		if (vec.size() == 0) 
			cntSubarrNotSet = 0; 

		// Variable to store count of subarrays 
		// whose bitwise OR will have i-th bit set 
		int cntSubarrIthSet = totalSubarrays - cntSubarrNotSet; 

		s += cntSubarrIthSet * pow(2, i); 
	} 

	return s; 
} 

// Driver code 
int main() 
{ 
	int A[] = { 1, 2, 3, 4, 5 }; 
	int n = sizeof(A) / sizeof(A[0]); 

	cout << givesum(A, n); 

	return 0; 
} 

