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
	//Prepocessing
	set<ii> ans;
	int a = 1, b = 1;
	int p = 1;
	while(a < 100000 and b < 100000){
		ans.insert({a,b});
		if(p) a += b;
		else b += a;
		p++; p %= 2;
	}
	cout << *ans.rend() << endl;
	exit(0);
	int n; cin >> n;
	int aux;
	set<int> m;
	for(int i = 0; i < n; i++){
		cin >> aux;
		m.insert(aux);
	}
	exit(0);
}
