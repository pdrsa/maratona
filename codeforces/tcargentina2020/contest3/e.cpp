//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
// #define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;

void found(int i){
	cout << "! " << i << endl;
	fflush(stdout);
	exit(0);
}

int solve(int i){
	int a, b;
	cout << "? " << i << endl;
	fflush(stdout);
	cin >> a;
	fflush(stdout);
	cout << "? " << i+ (n/2) << endl;
	fflush(stdout);
	cin >> b;
	fflush(stdout);

	return (a-b);
}

int main(){ //_
	cin >> n;
	int l = 1, r = n/2;
	bool a = (solve(l) > 0);

	while(l <= r){
		int m = (l+r)/2;
		int ans = solve(m);
		if(ans % 2 == 1) found(-1);
		if(ans == 0) found(m);
		
		if(a){
			if(ans > 0) l = m + 1;
			if(ans < 0) r = m - 1;
		} else{
			if(ans > 0) r = m - 1;
			if(ans < 0) l = m + 1;
		}
	}

	cout << "! -1" << endl;
	fflush(stdout);

	exit(0);
}
