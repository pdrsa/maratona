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
	string s; cin >> s;
	int sum = 0;
	for(int i = 0; i < s.size(); i++){
		int n = s[i] - '0';
		sum += n;
	}
	int l = s[s.size() - 1] - '0';
	if(s.size() > 1)
		l += (s[s.size() - 2] - '0') * 10; 
	if(l % 4 == 0) cout << "S" << endl;
	else cout << "N" << endl;

	if(sum % 9 == 0) cout << "S" << endl;
	else cout << "N" << endl;
	
	if(l % 25 == 0) cout << "S" << endl;
	else cout << "N" << endl;
	exit(0);
}
