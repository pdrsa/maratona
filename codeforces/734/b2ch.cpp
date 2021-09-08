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
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	vector<int> a;
	int b;
	int maxi = 0;
	while(cin >> b){
		maxi = max(b, maxi);
		a.pb(b);
	}
	vector<int> f(maxi+1);
	for(int i: a) f[i]++;
	for(int i = 2; i < maxi+1; i++) if(f[i] != f[i-1]){
		cout << "ERROR \n" << endl;
		for(int i: a) cout << i << " ";
		cout << endl;
		exit(0);
	}
	cout << "Check!" << endl;
	exit(0);
}
