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
	int k, nut, div, cap; cin >> k >> nut >> div >> cap;
	
	for(int i = 1; i <= nut; i++){
		int sec = i + min((k-1) * i, div);
		if(sec * cap >= nut){
			cout << i << endl; break;
		}
	}
	
	exit(0);
}
