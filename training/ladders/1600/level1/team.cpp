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
	ii l;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			int a; cin >> a;
			if(a) l = {i,j};
		}
	}
	auto [i,j] = l;
	cout << abs(i-2) + abs(j-2) << endl;
	exit(0);
}
