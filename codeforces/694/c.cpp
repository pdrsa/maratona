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
	int tt; cin >> tt;
	while(tt--){
		int n, m; cin >> n >> m;
		vector<int> f(n), p(m);
		for(int &i :f) cin >> i;
		for(int &i: p) cin >> i;
		sort(f.rbegin(), f.rend());
		
		ll sum = 0;
		int idx = 0;
		for(int i: f){
			i--;
			if(idx < m and idx <= i and p[idx] < p[i]){
				sum += p[idx];
				idx++;
			}
			else sum += p[i];
		}

		cout << sum << endl;
	}
	exit(0);
}
