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
const int MAX = 1e5 + 10;

int main(){ _
	int n;cin >> n;
	vector<int> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	int ans = 1, act = 1, ls = 1;
	for(int i = 1; i < n; i++){
		if(s[i-1] == s[i]) act++;
		else{
			ans = max(ans, min(act, ls));
			ls = act;
			act = 1;
		}
	}
	ans = max(ans, min(act, ls));

	cout << 2*ans << endl;
	
	exit(0);
}
