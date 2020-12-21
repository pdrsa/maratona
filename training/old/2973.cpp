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
const int MAX = 1e5 + 10;

int n, c, t;
int p[MAX];

bool poss(ll m){
	ll res = m*t;
	int count = 0;
	int i = 0;
	while(count < c){
		if(p[i] <= res){
			res -= p[i];
			i++;
			if(i == n) return true;
		}
		else{
			res = m*t;
			count++;
		}
	}

	return false;
}

int main(){ 
	cin >> n >> c >> t;
	int l = 0, r = 1e9+10;
	for(int i = 0; i < n; i++) cin >> p[i];
	while(l < r){
		//cout << l << " " << r <<  endl;
		ll m = (l+r)/2;
		if(poss(m)) r = m;
		else l = m+1;
	}

	cout << l << endl;
	exit(0);
}
