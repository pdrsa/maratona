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
	int k, n; cin >> n >> k;
	n = n*3;
	map<string, pair<int, int>> c;
	cin.ignore();

	for(int i = 0; i < n; i++){
		string s;
		getline(cin, s);
		if(!c.count(s)) c[s] = {1, i};
		else{
			c[s].f++;
			c[s].s = i;
		}
	}

	vector<tuple<int, int, string>> ord;

	for(auto [s, a]: c) ord.emplace_back(a.f, a.s, s);
	sort(ord.rbegin(), ord.rend());

	for(auto [a, b, s]: ord){
		if(k == 0) break;
		cout << s << endl;
		k--;
	}

	exit(0);
}
