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
	string s; cin >> s;
	set<char> c;
	for(auto u: s) c.insert(u);
	cout << (c.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!") << endl;
	exit(0);
}
