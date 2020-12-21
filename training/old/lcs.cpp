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

int n,m;
int a[1000];
int b[1000];
int mem[1000][1000];
vector<int> ans;

int pd(int i, int j){
	if (i == n or j == m) return 0;
	if (mem[i][j] != -1) return mem[i][j];
	mem[i][j] = 0;
	if (a[i] == b[j]) mem[i][j] = max(mem[i][j], 1 + pd(i+1, j+1));
	return mem[i][j] = max( {mem[i][j], pd(i+1,j), pd(i, j+1)} );
}

void recover(int i, int j){
	if (i==n or j==m) return;

	int pega = a[i] == b[j] ? 1 + pd(i+1, j+1) : -INF;
	int p1   = pd(i+1, j);
	int p2   = pd(i, j+1);

	if (pega >= p1 and pega >= p2){
		ans.pb(a[i]);
		recover(i+1,j+1);
	}
	else if (p1 > p2) recover(i+1, j);
	else recover(i, j+1);
}

int main(){ _
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	memset(mem, -1, sizeof mem);
	recover(0,0);
	
	for(auto u:ans) cout << u << " ";
	cout << endl;

	exit(0);
}
