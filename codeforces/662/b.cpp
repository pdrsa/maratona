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
	int n; cin >> n;
	vector<int> p(112345);
	int aux;
	int pS = 0, pQ = 0;
	for(int i = 0; i < n; i++){
		cin >> aux;
		p[aux]++;
		if(p[aux] != 0 and p[aux] % 2 == 0) pS++;
		if(p[aux] != 0 and p[aux] % 4 == 0) pQ++;
	}
	
	cin >> n;
	char sign;
	for(int i = 0; i < n; i++){
		cin >> sign >> aux;
		if(sign == '+'){
			p[aux]++;
			if(p[aux] != 0 and p[aux] % 2 == 0) pS++;
			if(p[aux] != 0 and p[aux] % 4 == 0) pQ++;
		}
		else{
			if(p[aux] != 0 and p[aux] % 2 == 0) pS--;
			if(p[aux] != 0 and p[aux] % 4 == 0) pQ--;
			p[aux]--;
		}

		if(pS >= 4 and pQ > 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	exit(0);
}
