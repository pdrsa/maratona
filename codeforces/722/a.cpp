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
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> v(n);
		for(int &i: v) cin >> i;
		while(v.size() > 0){
			int b = v.size();
			sort(v.begin(), v.end());
			int avg = 0;
			for(int i: v) avg += i;
			avg /= v.size();
			for(int i = 0; i < v.size(); i++){
				if(v[i] > avg) v.resize(i);
			}
			if(v.size() == b) break;
		}

		cout << (n - v.size()) << endl;
	}
	exit(0);
}
