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

string s, t;
int n, m;

int main(){ _
	cin >> n >> m;
	cin >> s >> t;
	int i, j;
	vector<int> f(m), l(m);

	for(i = n-1, j = m-1; j >= 0 and i >= 0; i--){
		if(s[i] == t[j]){
			l[j] = i;
			j--;
		}
	}

	for(i = 0, j = 0; j < m and i < n; i++){
		if(s[i] == t[j]){
			f[j] = i;
			j++;
		}
	}
	
	int ans = 0;
	for(i = 0; i < m-1; i++) ans = max(ans, (l[i+1] - f[i]));

	cout << ans << endl;

	exit(0);
}
