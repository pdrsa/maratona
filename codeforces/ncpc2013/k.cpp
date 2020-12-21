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
	map<int,int> ans;
	int aux;
	for(int i = 1; i <= n; i++){
		cin >> aux;
		ans[aux] = i;
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;

	exit(0);
}
