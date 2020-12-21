#include <bits/stdc++.h>

using namespace std;

long long int memo[200000];

#define MOD  10e9 + 7;

long long int fib(long long int a){

	long long int& pdm = memo[a];

	if (a <= 2) return 1;
	
	if (memo[a] != -1) return pdm;
	
	return pdm = (fib(a-1) + fib(a-2) ) % MOD;
}

int main (void){

	long long int a; cin >> a;
	memset(memo, -1, sizeof memo);
	cout << fib(a) << endl;
	exit(0);
}

