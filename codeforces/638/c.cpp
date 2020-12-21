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
	while(t--){
		int n, k; cin >> n >> k;
		string s; cin >> s;
		multiset <char> m;
		vector <char> r;
		for (int i = 0; i < n; i++) m.insert(s[i]);
		
		char act;
		auto it   = m.begin();
		auto last = m.end();
		last --;

		while(it != m.end()){
			act = *it;
			if (m.count(act) >= k){
				if (k == 2 and act != *last and it != m.begin()){
					while(it != m.end(){
						r.pb(*it);
						it++;
					}
				}
				int aux = m.count() / k;
				for (int i = 0; i < aux; i++) r.pb(act);
				if (int(m.count(act)) % k != 0){
					while(it != m.end() and *it == act) it++;
					if (it != m.end){
						r.pb(*it);
						break;
					}
				}
				while(it != m.end() and *it == act) it++;
			}
			else{
				int en = 0;
				while(en < k){
					act = *it;
					en += m.count(act);
					while(it != m.end() and *it == act)it++;
					if (it == m.end())break;
				}
				r.pb(act);
				break;
			}
		}

		for (int i = 0; i < r.size(); i++) cout << r[i];
		cout << endl;
	}
	exit(0);
}
