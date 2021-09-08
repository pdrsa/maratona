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

bool cmp(vector<int> a, vector<int> b){
	int cnt = 0;
	for(int i = 0; i < 5; i++) if(a[i] > b[i]) cnt++;

	return cnt >= 3;
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<vector<int>> rank(n, vector<int> (6));
		
		for(int i = 0; i < n; i++) for(int j = 0; j < 5; j++){
			cin >> rank[i][j];
			rank[i][5] = i;
		}
		
		sort(rank.begin(), rank.end(), cmp);

		bool ok = true;
		for(int adv = 0; adv < n-1; adv++){
			int cnt = 0;
			for(int j = 0; j < 5; j++) if(rank[adv][j] < rank.back()[j]) cnt++;
			ok &= cnt < 3;
		}

		cout << (ok ? rank.back()[5] + 1 : -1) << endl;
	}
	exit(0);
}
