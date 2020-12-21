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

int main(){
	int t; cin >> t;
	while(t--){
		int a, b, q; cin >> a >> b >> q;
		vector<int> memo(a*b);
		int n = 0;
		for (int i = 0; i < a * b; i++){
			if( ((i%a)%b) != ((i%b)%a) ) n++;
			memo[i] = n;
		}
			
		while(q--){
			ll l, r; cin >> l >> r;
			ll ansl, ansr;
			
			ansl = ((l-1)/(a*b)) * n;
			ansl += memo[(l-1)%(a*b)];

			ansr = (r/(a*b)) * n;
			ansr += memo[r%(a*b)];

			cout << ansr -  ansl << " ";
		}
		cout << endl;
	}
	exit(0);
}
