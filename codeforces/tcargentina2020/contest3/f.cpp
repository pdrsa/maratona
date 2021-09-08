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

int n;
ii hb;
vector<ii> it;

vector<int> dp((1 << 25), -1);

// Dist(-1, x) = Dist(Bolsa, Item[x]).
// Dist(x, y) = Dist(item[x], item[y]).
int dist(int i, int j){
	ii a, b;
	if(i == -1) a = hb;
	else a = it[i];

	if(j == -1) b = hb;
	else b = it[j];

	int dx = abs(a.f - b.f), dy = abs(a.s - b.s);

	return dx * dx + dy * dy;
}

int solve(int mask){
	if(dp[mask] != -1) return dp[mask];

	// First I didn't get
	int f = -1;
	for(int i = 0; i < n; i++){
		if(!(mask & (1 << i))){
			f = i; break;
		}
	}
	if(f == -1) return 0;

	int maskAlone = mask | (1 << f);
	int ans = solve(maskAlone) + 2*dist(-1, f);

	// All I didn't get after I
	for(int j = f+1; j < n; j++){
		if(!(mask & (1 << j))){
			int maskJ = maskAlone | (1 << j);
			ans = min(ans, solve(maskJ) + dist(-1, f) + dist(-1, j) + dist(f, j));
		}
	}

	return dp[mask] = ans;
}

void print(int mask){
	// First I didn't get
	int f = -1;
	for(int i = 0; i < n; i++){
		if(!(mask & (1 << i))){
			f = i; break;
		}
	}
	if(f == -1) return;
	
	int maskAlone = mask | (1 << f);
	if(solve(mask) == solve(maskAlone) + 2*dist(-1, f)){
		cout << f+1 << " 0 ";
		print(maskAlone);
		return;
	}

	// All I didn't get after I
	for(int j = f+1; j < n; j++){
		if(!(mask & (1 << j))){
			int maskJ = maskAlone | (1 << j);
			int ans = solve(maskJ) + dist(-1, f) + dist(-1, j) + dist(f, j);
			if(solve(mask) == ans){
				cout << f+1 << " " << j+1 << " 0 ";
				print(maskJ);
				return;
			}
		}
	}

}

int main(){ _
	cin >> hb.f >> hb.s;
	cin >> n;
	it.resize(n);
	for(auto &[x, y]: it) cin >> x >> y;
	cout << solve(0) << endl;
	cout << "0 ";
	print(0);
	cout << endl;
	exit(0);
}
