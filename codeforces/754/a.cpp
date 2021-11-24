//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void test_case(){
	int a, b, c; cin >> a >> b >> c;
	cout << ((abs((a+c) - b*2)) % 3 ? 1 : 0) << endl;
	
}

int32_t main(){ _
	int tt; cin >> tt;
	while(tt--) test_case();
	exit(0);
}
