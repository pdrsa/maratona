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
	int n, k; cin >> n >> k;
	vector<int> z(110);
	int count = 0;
	for(int i = 0; i < n; i++){
		int aux; cin >> aux;
		if(z[aux] == 0){
			count++;
			z[aux] = i+1;
		}
	}

	if(count < k) cout << "NO" << endl;

	else{
		cout << "YES" << endl;
		
		for(int i = 0; i < 110 and k > 0; i++){
			if(z[i] != 0){
				cout << z[i] << " ";
				k--;
			}
		}
		
		cout << endl;
	}
	exit(0);
}
