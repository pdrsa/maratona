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
	vector<char> qt1, qt2;
	vector<int>  pos1, pos2, pall;
	vector<char> c1, c2;

	vector<tuple<char, int, char>> q1, q2;
	char a, b;
	int x;
	bool got = false;
	while(cin >> a){
		if(a == 'D'){
			cin >> x;
			if(!got) q1.pb({a, x, '@'});
			else q2.pb({a, x, '@'});
			
			pall.pb(x);
		} 
		else if(a == 'I'){
			cin >> x >> b;
			if(!got) q1.pb({a, x, b});
			else q2.pb({a, x, b});

			pall.pb(x);
		}
		else if(a == 'E') got = true;
	}
	
	// Coordinate
	sort(pall.begin(), pall.end());
	pall.resize(unique(pall.begin(), pall.end()) - pall.begin());

	vector<int> s1, s2;
	for(int i = 0; i < 5000; i++) s1.pb(int('Z')+i+1), s2.pb(int('Z')+i+1);

	for(auto [t, idxO, ch]: q1){
		int idx = lower_bound(pall.begin(), pall.end(), idxO) - pall.begin();
		
		if(t == 'D') s1.erase(s1.begin() + idx);
		else s1.insert(s1.begin() + idx, int(ch));
	}

	for(auto [t, idxO, ch]: q2){
		int idx = lower_bound(pall.begin(), pall.end(), idxO) - pall.begin();
		
		if(t == 'D') s2.erase(s2.begin() + idx);
		else s2.insert(s2.begin() + idx, int(ch));
	}
	
	if(s1 == s2) cout << 0 << endl;
	else cout << 1 << endl;
	exit(0);
}

