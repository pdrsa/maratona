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

int n, m;
vector<string> s;

bool test(string a){
	for(int i = 0; i < n; i++){
		string aux = s[i];
		int er = 0;
		for(int j = 0; j < m; j++){
			if (a[j] == aux[j]) er++;
		}
		if(er < m-1) return false;
	}

	return true;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		string aux;
		s.clear();
		for(int i = 0; i < n; i++){
			cin >> aux;
			s.pb(aux);
		}
		string a = s[0];
		string ans = "-1";
		for (int i = 0; i < m; i++){
			for(int j = 0; j < 26; j++){
				a[i] = (a[i] == 'z') ? 'a' : a[i]+1;
				
				if (test(a)){
					ans = a;
					break;
				}
			}
			if(ans != "-1") break;
		}
		cout << ans << endl;
	}
	exit(0);
}
