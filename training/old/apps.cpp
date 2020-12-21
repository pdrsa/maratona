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
	int c, n;
	ll a, b;
	cin >> c >> n;
	map<ll,ll> emp;
	map<ll,ll> net;
	map<ll, ll> ans;
	
	for (int i = 0; i < c; i++){
		cin >> a >> b;
		emp[a] = b;
	}

	for (int i = 0; i < n; i++){
		cin >> a >> b;
		if (net.find(a) != net.end()){
			if (net[a] < b)
				net[a] = b;
		}
		else
			net[a] = b;
	}

	auto it = net.begin();

	while(it != net.end()){
		a = it -> f;
		if (emp.find(a) == emp.end()){
			it++;
			continue;
		}
		if (emp[a] < net[a]){
			ans[a] = net[a];
		}
		it++;
	}

	it = ans.begin();

	while(it != ans.end()){
		cout << it -> f << " " << it -> s << endl;
		it++;
	}

	exit(0);
}
