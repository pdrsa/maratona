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
	while (t--){
		string s; cin >> s;
		ll l, r;
		l = 0; r = 0;
		int a = 0, b = 0, c = 0;
		int menor = INF;
		
		while (l < s.length()){

			if ((a == 0 or b == 0 or c == 0) and r < s.length()){
				if (s[r] == '1') a++;
				if (s[r] == '2') b++;
				if (s[r] == '3') c++;
				r++;
			}

			else{
				if (a == 0 or b == 0 or c == 0) break;
				
				if (r-l < menor) menor = r-l;
				if (s[l] == '1') a--;
				if (s[l] == '2') b--;
				if (s[l] == '3') c--;
				l++;
			}

		}

		if (menor == INF) cout << 0 << endl;
		else cout << menor << endl;
	}
	exit(0);
}
