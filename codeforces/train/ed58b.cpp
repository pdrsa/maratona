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

void fail(){
	cout << -1 << endl;
	exit(0);
}

void rem(string &s, char c){
	bool error = true;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == c){
			s = s.substr(i+1);
			error = false;
			break;
		}
	}
	if(error) fail();
}

int main(){ _
	string s; cin >> s;
	rem(s, '[');
	rem(s, ':');
	reverse(s.begin(), s.end());
	rem(s, ']');
	rem(s, ':');
	int ans = 4;
	for(char c: s) if(c == '|') ans++;
	cout << ans << endl;

	exit(0);
}
