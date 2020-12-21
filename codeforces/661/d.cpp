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
		vector<int> ansV;
		ansV.pb(0);
		int n0 = 0, n1 = 0;
		for(int i = 0; i < n-1; i++){
			if(s[i] == s[i+1]){
				if(s[i+1] == '0') n0++;
				else n1++;
			}
			
			ansV.pb(n0-n1);
		}
 		
		set<int> ans;
		map<int,int> ansZ;
		int mini = INF;

		int act = 0;
		for(auto u:ansV){
			ans.insert(u);
			if(ans.size() > act){
				act = ans.size();
				ansZ[u] = act;
			}
		}

		cout << ans.size() << endl;
		for(auto u: ansV) cout << ansZ[u] << " ";
		cout << endl << endl << endl;
 
	}
	exit(0);
}
