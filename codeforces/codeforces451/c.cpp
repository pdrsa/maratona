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

int main(){ //_
	int n; cin >> n;
	map<string, vector<string>> ans;
	while(n--){
		string s; cin >> s;
		int a; cin >> a;

		while(a--){
			string p; cin >> p;
			ans[s].pb(p);
		}
	}

	cout << ans.size() << endl;
	for(auto ent: ans){

			set<string> now;
			string key = ent.f;

			for(int i = 0; i < ans[key].size(); i++){
				string p = ans[key][i];
				bool nsuf = true;
				//cout << " P = " << p << endl;
				//cout << ans[key].size() << endl;
				for(int j = 0; j < ans[key].size(); j++)
				{
					string q = ans[key][j];
					//cout << "Checking " << p << " on " << q << endl;
					if(q.size() <= p.size()){
						//cout << q << " size < " << p << " size" << endl;
						continue;
					}
					for(int k = 0; k < p.size(); k++){
						if(q[q.size() - k - 1] != p[p.size() - k - 1]) break;
						if(k == p.size()-1) nsuf = false;
					}
					//if(!nsuf) cout << "FOUND SUFFIX!" << endl;
				}

				if(nsuf) now.insert(p);
			}
			
			cout << ent.f << " " << now.size() << " ";
			for(auto z:now) cout << z << " ";
			cout << endl;
	}
	exit(0);
}
