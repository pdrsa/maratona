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
int n;
vector<ii> ans;

bool checkSafe(vector<ii> q){
	int x = q.back().f;
	int y = q.back().s;
	ii queen = q.back();
	for(int i = 0; i < n; i++){
		for(auto u: q){
			if (u == queen) continue;
			ii a = {i, y};
			if (u == a) return false;
			a = {x, i};
			if (u == a) return false;
			a = {x-i, y-i};
			if (u == a) return false;
			a = {x-i, y+i};
			if (u == a) return false;
			a = {x+i, y-i};
			if (u == a) return false;
			a = {x+i, y+i};
			if (u == a) return false;
		}
	}
	return true;
}

bool putQueen(vector<ii> q){
	if(!q.empty() and !checkSafe(q)) return false;

	int i = q.size();
	if (i == n){
		ans = q;
		return true;
	}
	for(int j = 0; j < n; j++){
		q.pb({i, j});
		if(putQueen(q)) return true;
		q.pop_back();
	}
	return false;
}

int main(){ _
	cin >> n;
	vector<ii> q;
	putQueen(q);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			bool flag = true;
			for(auto u: ans){
				ii a = {i,j};
				if(u == a){
					cout << "Q|";
					flag = false;
					break;
				}
			}
			if (flag) cout << " |";
		}
		cout << endl;
		for(int z = 0; z < n; z++) cout << "--";
		cout << endl;
	}
	exit(0);
}
