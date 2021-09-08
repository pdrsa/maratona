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


string s;

int penalty(int g1, int g2, int i){
	if(i == 10 or (g1 > g2 + (5 - i/2)) or (g2 > g1 + (5 - (i+1)/2))) return (i - 1);
	
	if(i % 2 == 0){
		if(s[i] != '?') return penalty(g1 + int(s[i] - '0'), g2, i+1);
		else return min(penalty(g1+1, g2, i+1), penalty(g1, g2, i+1));
	} else{
		if(s[i] != '?') return penalty(g1, g2 + int(s[i] - '0'), i+1);
		else return min(penalty(g1, g2+1, i+1), penalty(g1, g2, i+1));
	}
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		cin >> s; cout << penalty(0, 0, 0) + 1 << endl;
	}
	exit(0);
}
