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
	int aux, p1, p2;
	for(int i = 0; i < n; i++){
		cin >> aux;
		if(aux == 1) p1 = i;
		if(aux == n) p2 = i;
	}
	
	cout << max({abs(n-p2-1), abs(n-p1-1), p2, p1}) << endl;

	exit(0);
}
