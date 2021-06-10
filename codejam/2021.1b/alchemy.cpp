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
	int ttt; cin >> ttt;
	for(int tt = 1; tt <= ttt; tt++){
		int n, a, b; cin >> n >> a >> b;
		vector<int> ne(n); for(int &i: ne) cin >> i;
		bool did;

		vector<vector<int>> opt(n, vector<int>(n, -1));

		for(int i = 0; i < 100; i++){
			vector<int> act = ne;
			priority_queue<int> q; q.push(i);
			
			while(!q.empty()){
				int m = q.top(); q.pop();
				if(m < n and act[m] > 0) act[m]--;
				else{
					if(m - a >= 0) q.push(m-a);
					if(m - b >= 0) q.push(m-b);
				}
			}

			did = true;
			for(int s: act) if(s > 0) did = false;
			if(did){
				cout << "Case #" << tt << ": " << i+1 << endl;
				break;
			}
		}

		if(!did) cout << "Case #" << tt << ": IMPOSSIBLE" << endl;
	}
	exit(0);
}
