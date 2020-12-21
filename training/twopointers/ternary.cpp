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

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		vector<int> z(3);
		string aux; cin >> aux;
		vector<int> s(aux.size());
		for(int i = 0; i < aux.size(); i++) s[i] = aux[i] - '1';
		
		int ans = INF;
		int l, r;
		for(l = 0, r = 0; r < s.size();){		
			while(r < s.size() and (!z[0] or !z[1] or !z[2])){
				z[s[r]]++;
				r++;
			}

			while(z[0] and z[1] and z[2]){
				ans = min(ans, r - l);
				z[s[l]]--;
				l++;
			}
		}

		cout << (ans == INF ? 0 : ans) << endl;
	}
	exit(0);
}
