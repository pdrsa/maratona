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
	vector<ll> stArr;

	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		//Size of the tree is 2n-1. Assigning 0 for init.
		stArr.assign(2 * size, 0LL);
	}
	
	//Recursive function.
	void set(int i, int v, int x, int lx, int rx){
		//Check if on leaf
		if(rx - lx == 1){
			stArr[x] = v;
			return;
		}

		//Now we recursive call the children.
		int m = (lx + rx)/2;

		if(i < m)
			set(i, v, 2*x + 1, lx, m);
		else
			set(i, v, 2*x + 2, m, rx);
		
		ll c1 = stArr[2*x + 1]; ll c2 = stArr[2*x + 2];
		stArr[x] = op(c1, c2);
	}
	
	//Friendly function.
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
	
	//Recursive function.
	ll get(int l, int r, int x, int lx, int rx){
		//Check if all inside or all out.
		if(lx >= r or rx <= l) return 0;
		if(lx >= l and rx <= r) return stArr[x];
		
		int m = (lx + rx)/2;
		ll c1 = get(l, r, 2*x+1, lx, m);
		ll c2 = get(l, r, 2*x+2, m, rx);

		return op(c1, c2);
	}

	//Friendly function.
	ll get(int l, int r){
		return get(l, r, 0, 0, size);
	}

};


//Example of code for initializing ST, reading it's initial state and performing some operations.
int main(){
	int n;
	cin >> n;
	int m; cin >> m;
	segtree st;
	st.init(n);
	int v;
	for(int i = 0; i < n; i++){
		cin >> v;
		st.set(i, v);
	}

	while(m--){
		int op; cin >> op;
		int a, b; cin >> a >> b;
		if(op == 1)
			st.set(a, b);
		else
			cout << st.get(a,b) << endl;
	}
	exit(0);
}
