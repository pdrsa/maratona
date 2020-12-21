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
		string a; cin >> a;
		cout << a[0];
		if(a.size() > 1)
			for(int i = 1; i < a.size() - 1; i+=2) cout << a[i];
		cout << a[a.size() - 1] << endl;
	}
	exit(0);
}
