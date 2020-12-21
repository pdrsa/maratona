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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int a,b; cin >> a >> b;
	int step = 1;
	while(a >= 0 and b >= 0){
		if(step % 2) a -= step;
		else b -= step;
		step++;
	}

	cout << (step % 2 ? "Valera" : "Vladik") << endl;
	exit(0);
}
