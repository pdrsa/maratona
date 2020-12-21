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
	int k; cin >> k;
	vector<int> f(12);
	for (int i = 0; i < 12; i++)cin >> f[i];
	sort(f.begin(),f.end());
	int a = 0;
	bool flag = false;
	if (k <= 0){
		cout << 0 << endl;
		exit(0);
	}
	for (int i = 11; i >= 0; i--){
		a++;
		k = k-f[i];
		if(k <= 0){
			flag = true;
			break;
		}
	}
	
	if(!flag) cout << -1 << endl;
	else cout << a;
	exit(0);
}
