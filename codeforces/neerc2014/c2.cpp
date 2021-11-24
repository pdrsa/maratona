//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
// #define endl '\n' DEFINE SALAFRARIO
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<unordered_map<int, string>> props;
vector<vector<int>> g;
unordered_map<string, int> dict;

pair<string, string> split(string s) {
    string s1;
    string s2;
    bool primeira = true;
    for(int I = 0; I < s.size(); I++){
        if(s[I] == '=') {
            primeira = false;
            continue;
        }
        if(primeira) s1 += s[I];
		else s2 += s[I];
    }
    return {s1, s2};
}

void dfs(int x, int p){
	for(int u: g[x]){
		if(!props[u].count(p) and props[x].count(p))
			props[u][p] = props[x][p];
		dfs(u, p);
	}
}

vector<pair<int, int>> euler;

int countEuler = 0;
void dfsEuler(int x){
	euler[x].f = countEuler++;
	for(int u: g[x]) dfsEuler(u);
	euler[x].s = countEuler++;
}

int main(){  _
	int n; cin >> n;
	g.resize(n), props.resize(n);

	vector<int> countP;
	vector<vector<int>> has;

	// unordered_map<string, int> dict;
	for(int i = 0; i < n; i++){
		int p, k; cin >> p >> k; p--;
		if(p != -1) g[p].pb(i);

		while(k--){
			string s; cin >> s;
			auto [a, b] = split(s);

			if(!dict.count(a)) dict[a] = dict.size();
			if(dict[a] >= countP.size()) countP.pb(0);
			countP[dict[a]]++;

			props[i][dict[a]] = b;
			if(dict[a] >= has.size()) has.pb(vector<int>());
			has[dict[a]].pb(i);
		}
	}
	
	// For big boys
	for(int key = 0; key < countP.size(); key++)
		if(countP[key] * countP[key] >= n) dfs(0, key);

	// For smol boys
	euler.resize(n);
	dfsEuler(0);
	
	// Queries
		int property = ;
	int q; cin >> q;
	while(q--){
		int node; cin >> node; node--;
		string s; cin >> s;
		int property;

		// If property never seen before
		if(!dict.count(property)){
			cout << "N/A" << endl;
			continue;
		} else property = dict[property];
		
		// For big boys
		if(countP[property] >= sqrt(n)){
			if(props[node].count(property))
				cout << props[node][property] << endl;
			else cout << "N/A" << endl;
			continue;
		}

		// For smol boys
		auto [start, end] = euler[node];
		int ansNode = -1, ansNodeStart = -1;
		for(int i: has[property]){
			auto [startNow, endNow] = euler[i];
			if(endNow >= end and startNow <= start)
				if(startNow > ansNodeStart) ansNode = i, ansNodeStart = startNow;
		}

		// Print Answer
		if(ansNode == -1) cout << "N/A" << endl;
		else cout << props[ansNode][property] << endl;
	}

	exit(0);
}
