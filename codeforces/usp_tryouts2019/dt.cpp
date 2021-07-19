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

int main(){
	int tt; cin >> tt;
	int v = 0;
	while(tt--){
		char c; cin >> c;
		if(c == 'B'){
			int as, bs, at, bt, h; cin >> as >> bs >> at >> bt >> h;
			cout << double(as^v)/double(bs^v) << " to ";
			cout << double(at ^ v)/double(bt ^ v);
			cout << " with height = " << h << endl;
		}
		else cin >> v;
	}
	exit(0);
}
