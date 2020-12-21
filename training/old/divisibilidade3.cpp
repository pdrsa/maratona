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
		if(i % 2 == 0)
			sum += n;
		else
			sum -= n;
	}
	if(sum % 11 == 0) cout << "S" << endl;
	else cout << "N" << endl;
	exit(0);
}
