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

//A classic segment tree structure :D
//Template for any operation, here using sum.
//Range is inclusive on left bound and exclusive on right bound.	
//Using long long

//Set operation here
ll op(ll a, ll b){
	return a+b;
}

struct segtree{
	int size;
	vector<vector<ll>> stArr;

	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		//Size of the tree is 2n-1. Assigning 0 for init.
		stArr.resize(2 * size);
		for(int i = 0; i < 2 * size; i++){
			stArr[i].resize(4);
			stArr[i] = {0,0,0,0};
		}
	}

	void build(vector<int> &arr, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx >= arr.size()) return;
			ll p = max(0, arr[lx]);
			stArr[x] = {p,p,p,arr[lx]};
			return;
		}

		//Now we recursive call the children.
		int m = (lx + rx)/2;

		build(arr, 2*x + 1, lx, m);
		build(arr, 2*x + 2, m, rx);
		
		vector<ll> v1 = stArr[2*x + 1];
		vector<ll> v2 = stArr[2*x + 2];
		
		//CalcPref
		stArr[x][0] = max({v1[0], v1[3]+v2[0]});
		//CalcMaxSeg
		stArr[x][1] = max({v1[1], v2[1], v1[2]+v2[0]});
		//CalcSuf
		stArr[x][2] = max({v2[2], v1[2] + v2[3]});
		//CalcSum
		stArr[x][3] = v1[3]+ v2[3];	
	}

	void build(vector<int> &arr){
		build(arr, 0, 0, size);
	}

	//Recursive function.
	void set(int i, int v, int x, int lx, int rx){
		//Check if on leaf
		if(rx - lx == 1){
			ll p = max(0, v);
			stArr[x] = {p,p,p,v};
			return;
		}

		//Now we recursive call the children.
		int m = (lx + rx)/2;

		if(i < m)
			set(i, v, 2*x + 1, lx, m);
		else
			set(i, v, 2*x + 2, m, rx);
		
		vector<ll> v1 = stArr[2*x + 1];
		vector<ll> v2 = stArr[2*x + 2];
		
		//CalcPref
		stArr[x][0] = max({v1[0], v1[3]+v2[0]});
		//CalcMaxSeg
		stArr[x][1] = max({v1[1], v2[1], v1[2]+v2[0]});
		//CalcSuf
		stArr[x][2] = max({v2[2], v1[2] + v2[3]});
		//CalcSum
		stArr[x][3] = v1[3]+ v2[3];
	}
	
	//Friendly function.
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	ll get(){
		return stArr[0][1];
	}
};


int main(){
	int n;
	cin >> n;
	int m; cin >> m;
	segtree st;
	st.init(n);
	vector<int> s(n);
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	st.build(s);
	cout << st.get() << endl;

	while(m--){
		int a, b; cin >> a >> b;
		st.set(a, b);
		cout << st.get() << endl;
	}
	exit(0);
}
