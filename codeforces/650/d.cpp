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
		string s; cin >> s;
		int n; cin >> n;
		vector<ii> a(n); 
		int aux;
		for(int i = 0; i < n; i++){
			cin >> aux;
			a[i] = {-aux, i};
		}
		sort(a.begin(), a.end());
		sort(s.begin(), s.end());
		for(int i = 0; i < n; i++){
			cout << s[a[i].s];
		}
		cout << endl;
		
	}
	exit(0);
}
