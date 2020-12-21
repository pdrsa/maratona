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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> c(n);
		for(int i = 0; i < n; i++) cin >> c[i];
		int l = 0, r = n-1;
		int mv = 0, a = 0, b = 0, la = 0, lb = 0;
		bool flag = true;

		while(l <= r){
			la = 0;
			if (flag) mv++;
			while(lb >= 0 and l <= r){
				la += c[l];
				a  += c[l];
				lb -= c[l];
				l++;
				if (l > r) flag = false;
			}
			lb = 0;
			if (flag) mv++;
			while(la >= 0 and l <= r){
				lb += c[r];
				b += c[r];
				la -= c[r];
				r--;
				if (l > r) flag = false;
			}
		}
		cout << mv << " " << a << " " << b << endl;
	}
	exit(0);
}
