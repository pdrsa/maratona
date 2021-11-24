//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int rand(int a, int b){ // Random on [a, b]
	return rand()%(b-a+1) + a;
}

int32_t main(){ _
	srand(17);
	cout << 100 << " " << int(1e5) << endl;
	for(int i = 0; i < 100; i++) cout << 1 << " ";
	cout << endl;
	for(int i = 0; i < 1e5; i++)
		cout << rand(1, int(1e9)) << endl;
	exit(0);
}
