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

int main(){ 
	int k; cin >> k;
	vector<pair<vector<ii>, int>> s(k);

	for(int a = 0; a < k; a++){
		int n; cin >> n;
		int sum = 0;
		for(int i = 0; i < n; i++){
			int aux; cin >> aux;
			sum += aux;
			s[a].f.pb({aux, i});
		}
		s[a].s = sum;
		sort(s[a].f.begin(), s[a].f.begin());
	}
	
	bool ok = false;
	pair<ii,ii> ans;

	for(int i = 0; i < k; i++){
		for(int z = 0; z < s[i].f.size(); z++){
			int w = s[i].f[z].f;
			for(int j = 0; j < k and j != i; j++){
				int ww = s[j].s + w - s[i].s;
				ii wanted = {ww, -INF};
				auto l = lower_bound(s[j].f.begin(), s[j].f.end(), wanted);
				cout << "Vector " << i << " element " << w << " with Vector " << j << endl;
				cout << "Desired is " << ww << endl;
				if(l != s[j].f.end()){
					int pos = (l - s[j].f.begin());

					if(s[j].f[pos].f == ww){
						ok = true;
						ans.f.f = i+1; ans.f.s = z;
						ans.s.f = j+1; ans.s.s = (l - s[j].f.begin());
						break;
					}
				}
			}
			if(ok) break;
		}
		if(ok) break;
	}

	if(ok){
		cout << "YES" << endl;
		cout << ans.f.f << " " << ans.f.s << endl;
		cout << ans.s.f << " " << ans.s.s << endl;
	} else cout << "NO" << endl;

	exit(0);
}
