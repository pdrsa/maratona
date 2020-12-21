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
	while(tt--){
		int n; cin >> n;
		string s; cin >> s;
		vector<bool> a(n);
		for(int i = 0; i < n; i++) a[i] = (s[i] == '1');
		for(int i = a.size() - 2; i >= 0; i--){
			if(a[i] and !a[i+1]){
				if(i != 0 and a[i-1]){
					a.erase(a.begin() + i);
				}
				else if (i != a.size() - 2 and !a[i+2]){
					a.erase(a.begin() + i + 1);
					i++;
				}
				else{
					a.erase(a.begin() + i);
				}
			}
		}

		for(auto u: a) cout << u;
		cout << endl;

	}
	exit(0);
}
