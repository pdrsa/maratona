//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e4;

int gen(int z){
	return (rand() % z) + 1;
}

int main(){ _
 	srand(42);

	int n = gen(MAX);
	int m = gen(MAX);
	int x = gen(n);
	cout << n << " " << m << " " << x << endl;
	while(m--){
		int t = gen(2);
		int a = gen(n);
		int b = gen(n);

		cout << t << " " <<  min(a,b) << " " << max(a,b) << endl;
	} 
	exit(0);
}
