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
	int n, k; cin >> n >> k;
	vector<int> s(n+1);
	for(int i = 1; i <= n; i++){
		cin >> s[i]; s[i] += s[i-1];
	}
	int mini = INF, minidx;
	for(int i = 0; i + k <= n; i++){
		if(s[i+k] - s[i] < mini){
			mini = s[i+k] - s[i];
			minidx = i;
		}
	}
	cout << minidx + 1 << endl;
	exit(0);
}
