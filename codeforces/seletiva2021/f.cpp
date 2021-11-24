//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	string s; cin >> s;
	bool ok = false;
	if(s.size() < 26){
		cout << -1 << endl;
		exit(0);
	}
	for(int i = 0; i < s.size() - 25; i++){
		vector<bool> g(26);
		int count = 0;
		bool erro = false;
		for(int j = i; j < i+26; j++){
			if(s[j] == '?'){
				count++;
				continue;
			}
			int c = s[j] - 'A';
			if(g[c]){
				erro = true;
				break;
			}
			else g[c] = true;
		}
		if(erro) continue;
		
		int miss = 0;
		stack<char> print;
		for(int j = 0; j < 26; j++){
			miss += (1 - g[j]);
			if(!g[j]) print.push('A' + j);
		}

		// cout << miss << " " << count << endl;
		
		if(miss == count){
			ok = true;
			for(int j = i; j < i+26; j++)
				if(s[j] == '?'){
					s[j] = print.top();
					print.pop();
				}
		}
		if(ok) break;
	}
	
	if(!ok) cout << -1 << endl;
	else{
		for(int i = 0; i < s.size(); i++)
			if(s[i] == '?') s[i] = 'A';
		cout << s << endl;
	}
	exit(0);
}
