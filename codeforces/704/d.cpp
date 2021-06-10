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

int main(){ _
	int a, b, k; cin >> a >> b >> k;
	
	if(k == 0){
		cout << "Yes" << endl;
		for(int i = 0; i < b; i++) cout << 1;
		for(int i = 0; i < a; i++) cout << 0;
		cout << endl;
		for(int i = 0; i < b; i++) cout << 1;
		for(int i = 0; i < a; i++) cout << 0;
		cout << endl;
	}
	
	else if(k > (a+b - 2) or b == 1 or a == 0) cout << "No" << endl;
	
	else{
		cout << "Yes" << endl;
		// First Number
		for(int i = 0; i < b; i++) cout << 1;
		for(int i = 0; i < a; i++) cout << 0;
		cout << endl;

		// Second Number
		if(a >= k){
			for(int i = 0; i < b-1; i++) cout << 1;
			for(int i = 0; i < k; i++) cout << 0;
			cout << 1;
			for(int i = 0; i < (a-k); i++) cout << 0;
			cout << endl;
		}
		else{
			for(int i = 0; i < b - (k-a) - 1; i++) cout << 1;
			cout << 0;
			for(int i = 0; i < (k-a); i++) cout << 1;
			for(int i = 0; i < (a-1); i++) cout << 0;
			cout << 1;
			cout << endl;
		}
	}
	exit(0);
}
