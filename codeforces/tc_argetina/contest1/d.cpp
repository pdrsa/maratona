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

vector<ll> head;
vector<ll> track;
int n, m;

bool solve(ll x){
	int p = 0;
	for(int i = 0; i < head.size(); i++){
		ll dist = abs(track[p] - head[i]);

		ll mw = x; // Max I can walk to the right.

		if(track[p] < head[i]){
			mw = max(x - 2*dist, (x-dist)/2);
			if(dist > x) return false;
		}
		
		// Find first track I won't reach.
		p = upper_bound(track.begin(), track.end(), head[i] + mw) - track.begin();
		if(p == m) return true; // Got everyone.
	}

	return false;
}

int main(){ _
	cin >> n >> m;
	head.resize(n); for(ll &i: head) cin >> i;
	track.resize(m); for(ll &i: track) cin >> i;
	
	ll ini = 0, end = 1e11;
	while(ini < end){
		ll mid = (ini + end)/2;
		if(solve(mid)) end = mid;
		else ini = mid+1;
	}
	cout << ini << endl;

	exit(0);
}
