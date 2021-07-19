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

vector<int> v;
int n;

bool check(int s, int g){
	for(int i = s; i < s+g; i++){
		for(int j = i+1; j < s+g; j++){
			for(int k = j+1; k < s+g; k++){
				vector<int> d(3);
				d[0] = abs(v[i] - v[j]) + abs(i - j);
				d[1] = abs(v[i] - v[k]) + abs(i - k);
				d[2] = abs(v[k] - v[j]) + abs(k - j);
				sort(d.begin(), d.end());
				if(d[0] + d[1] == d[2]) return false;
			}
		}
	}
	return true;
}

int main(){ //_
	int tt; cin >> tt;
	while(tt--){
		cin >> n;
		int ans = 0;
		v.resize(n); for(int &i: v) cin >> i;
		
		for(int k = 1; k <= 6; k++)
			for(int i = 0; i < n - k + 1; i++)
				if(check(i, k)) ans++;
		cout << ans << endl;
	}
	exit(0);
}
