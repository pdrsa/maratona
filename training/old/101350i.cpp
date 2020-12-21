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
string s;
vector<bool> p(1010);

bool checkP(int st, int sz){
	for(int i = 0; i < sz/2; i++){
		if(s[st+i] != s[st+sz-i-1] or p[st+i] or p[st+sz-i-1]) return false;
	}

	if(p[st+sz/2]) return false;

	return true;
}

bool poss(int m){
	for(int i = 0; i <= s.size() - m; i++){
		if(s[i] == s[i+m-1]){
			if(checkP(i, m)) return true;
		}
	}

	return false;
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		cin >> s;
		int size = s.size();
		
		for(int i = 0; i < size; i++){
			if(s[i] == 'A' or s[i] == 'H' or
			s[i] == 'I' or s[i] == 'M' or
			s[i] == 'O' or s[i] == 'T' or
			s[i] == 'U' or s[i] == 'V' or
			s[i] == 'W' or s[i] == 'X' or
			s[i] == 'Y') p[i] = false;
			else p[i] = true;
			//cout << p[i] << " ";
		}
		//cout << endl;
		
		int l = 0, r = size;
		while(l < r){
			int m = (l+r+1)/2;
			//cout << m << endl;
			if(poss(m) or poss( min(m+1,size) )) l = m;
			else r = m-1;
		}

		cout << l << endl;
	}
	exit(0);
}
