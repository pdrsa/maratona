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
		bool flag = true;
		string s;cin >> s;
		for(int i = 1; i < s.size(); i++){
			if(s[i] != s[i-1]){
				flag = false;
				break;
			}
		}
		
		if(flag){
			cout << s << endl;
			continue;
		}
		
		int a = s.size();

		if(s[0] == '0')
			while(a--)cout<<"01";
		else
			while(a--)cout<<"10";

		cout << endl;
	}
	exit(0);
}
