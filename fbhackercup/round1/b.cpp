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
	int tt; cin >> tt;
	for(int t = 0; t < tt; t++){
		int n; cin >> n;
		string s; cin >> s;
		int a = 0, b = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == 'A') a++;
			else b++;
		}
		cout << "Case #" << t+1 << ": ";
		if(abs(a-b) == 1) cout << "Y" << endl;
		else cout << "N" << endl;
	}
	exit(0);
}
