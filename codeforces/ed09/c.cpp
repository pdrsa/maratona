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

bool comp(string a, string b){
	return (a + b) < (b + a);
}

int main(){ _
	int n; cin >> n;
	vector<string> a(n);
	for(string &s:a) cin >> s;
	sort(a.begin(), a.end(), comp);
	for(string s:a) cout << s;
	cout << endl;
	exit(0);
}
