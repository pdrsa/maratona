#include "bits/stdc++.h"

using namespace std;


int main(){
	int n;
	double l;
	cin >> n >> l;
	double arr[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort (arr, arr+n);
	double maior = 0;

	for (int i = 0; i < n-1; i++){
		if (arr[i+1] - arr[i] > maior)
			maior = (arr[i+1] - arr[i]);
	}

	maior = maior/2;

	if (arr[0] > maior)
		maior = arr[0];

	if (l - arr[n-1] > maior)
		maior = (l - arr[n-1]);
	cout.precision(9);
	cout << maior << endl;

	return 0;
}