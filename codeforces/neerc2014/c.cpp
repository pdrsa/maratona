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

const int INF   = 0x3f3f3f3f;
const ll LINF   = 0x3f3f3f3f3f3f3f3fll;
const int MAX   = 3e5 + 10;
const int MAGIC = 1200;

unordered_map<int, int> props[MAX];
vector<int> g[MAX];

unordered_map<string, int> vals;
vector<string> inVals;

unordered_map<string, int> keys;

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
		if(!props[u].count(p) and props[x].count(p)) props[u][p] = props[x][p];
		dfs(u, p);
	}
}

vector<pair<int, int>> euler(MAX);

int countEuler = 0;
void dfsEuler(int x){
	euler[x].f = countEuler++;
	for(int u: g[x]) dfsEuler(u);
	euler[x].s = countEuler++;
}

int main(){  _
	int n; cin >> n;

	unordered_map<int, int> countP;
	unordered_map<int, vector<int>> has;

	// unordered_map<string, int> dict;
	for(int i = 0; i < n; i++){
		int p, k; cin >> p >> k; p--;
		if(p != -1) g[p].pb(i);

		while(k--){
			string s; cin >> s;
			auto [key, val] = split(s);

			if(!vals.count(val)){
				vals[val] = vals.size();
				inVals.pb(val);
			}
			if(!keys.count(key)) keys[key] = keys.size();

			int a = keys[key];
			int b = vals[val];

			if(countP.count(a)) countP[a]++;
			else countP[a] = 1;
			
			props[i][a] = b;
			if(!has.count(a)) has[a] = vector<int>();
			has[a].pb(i);
		}
	}
	
	// For big boys
	for(auto [key, value]: countP)
		if(countP[key] >= MAGIC) dfs(0, key);

	// For smol boys
	dfsEuler(0);
	
	// Queries
	int q; cin >> q;
	while(q--){
		int node; cin >> node; node--;
		string s; cin >> s;
		
		// If property never seen before
		if(!keys.count(s)){
			cout << "N/A" << endl;
			continue;
		}
		int property = keys[s];

		// For big boys
		if(countP[property] >= MAGIC){
			if(props[node].count(property))
				cout << inVals[props[node][property]] << endl;
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
		else cout << inVals[props[ansNode][property]] << endl;
	}

	exit(0);
}
