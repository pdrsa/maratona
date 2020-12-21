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
const int MAX = 200000;

int mod(int a, int b){return ((b + (a%b)) % b);}

int main(){ _
	int n; cin >> n;
	vector<int> ap(n);
	vector<int> ans (MAX, 0);
	vector<int> bp(n);
	map<int, int> b;
	
	int aux;
	for(int i = 0; i < n; i++){
		cin >> ap[i];
	}
	
	for(int i = 0; i < n; i++){
		cin >> aux;
		b[aux] = i;
		bp[i] = aux;
	}
	
	int z;

	for(int i = 0; i < n; i++){
		z = b[ap[i]] - i;
		z = mod(z, n);
		ans[z]++;
	}

	int fans = 0;
	
	for(int i = 0; i < n; i++) fans = max(fans, ans[i]);

	cout << fans << endl;

	exit(0);
}
