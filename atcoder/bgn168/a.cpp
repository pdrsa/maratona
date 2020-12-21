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
	int n; cin >> n;
	int a = n%10;
	if(a == 2 or a == 4 or a == 5 or a == 7 or a == 9) cout << "hon" << endl;
	else if (a == 0 or a == 1 or a ==6 or a == 8) cout << "pon" << endl;
	else cout << "bon" << endl;
	
	exit(0);
}
