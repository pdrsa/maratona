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
	ll counter = 0;
	ll n;
	int c;
	set<int> t;
	cin >> n;
	for (ll i = 0; i < n; i++){
		cin >> c;
		if (t.count(c)){
			t.erase(c);
		}
		else{
			counter += 2;
			t.insert(c);
		}
	}
	cout << counter;
	exit(0);
}
