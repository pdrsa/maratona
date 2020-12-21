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

struct segtree{
	int size;
	vector<int> stArr;

	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		//Size of the tree is 2n-1. Assigning 0 for init.
		stArr.assign(2 * size, 0);
	}

	void build(vector<int> &arr, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx >= arr.size()) return;
			stArr[x] = arr[lx];
			return;
		}

		//Now we recursive call the children.
		int m = (lx + rx)/2;

		build(arr, 2*x + 1, lx, m);
		build(arr, 2*x + 2, m, rx);
		
		int v1 = stArr[2*x + 1];
		int v2 = stArr[2*x + 2];	
		stArr[x] = v1+v2;
	}

	void build(vector<int> &arr){
		build(arr, 0, 0, size);
	}

	//Recursive function.
	void set(int k, int x, int lx, int rx){
		//Check if on leaf
		if(rx - lx == 1){
			stArr[x] += 1;
			stArr[x] %= 2;
			return;
		}

		//Now we recursive call the children.
		int m = (lx + rx)/2;

		if(k < m)
			set(k, 2*x + 1, lx, m);
		else
			set(k, 2*x + 2, m, rx);
		
		int c1 = stArr[2*x + 1]; int c2 = stArr[2*x + 2];
		stArr[x] = c1+c2;
	}

	//Friendly function.
	void set(int k) {
		set(k, 0, 0, size);
	}
	
	//Recursive function.
	ll get(int k, int x, int lx, int rx){
		if(rx - lx == 1) return lx;
		int m = (lx + rx)/2;
		if (k <= stArr[2*x+1]) return get(k, 2*x+1, lx, m);
		else return get(k-stArr[2*x+1], 2*x+2, m, rx);

	}

	//Friendly function.
	ll get(int k){
		return get(k, 0, 0, size);
	}

};


//Example of code for initializing ST, reading it's initial state and performing some operations.
int main(){
	int n;
	cin >> n;
	int m; cin >> m;
	segtree st;
	st.init(n);
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	st.build(v);

	while(m--){
		int op; cin >> op;
		int a; cin >> a;
		if(op == 1)
			st.set(a);
		else
			cout << st.get(a+1) << endl;
	}
	exit(0);
}
