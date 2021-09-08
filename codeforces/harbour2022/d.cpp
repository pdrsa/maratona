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
	int tt; cin >> tt;
	while(tt--){
		string s, t; cin >> s >> t;
		bool ok = false;

		// Começando em Par
		int parity = 0;
		int j = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == t[j] and (((i % 2) + parity) % 2 == 0)){
				parity = (parity + 1) % 2;
				j++;
			}

			if(j == t.size()){
				if((s.size() - i - 1) % 2 == 0) ok = true;
				break;
			}
		}

		// Começando em Ímpar
		parity = 1;
		j = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == t[j] and (((i % 2) + parity) % 2 == 0)){
				parity = (parity + 1) % 2;
				j++;
			}

			if(j == t.size()){
				if((s.size() - i - 1) % 2 == 0) ok = true;
				break;
			}
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
	exit(0);
}

