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
	
	vector<int> c(n);

	for(int i = 0; i < n; i++) cin >> c[i];
	
	int i;

	while(i < n){
		if(c[i] == 1){
			if(i != 0 and c[i-1] != -1)
				c[i-1] = (c[i-1] + 1) % 2;
			if(i != n-1 and c[i+1] != -1) 
				c[i+1] = (c[i+1] + 1) % 2;
			c[i] = -1;
			i = 0;
		}
		else i++;
	}

	for(i = 0; i < n; i++){
		if(c[i] != -1){
			cout << "N" << endl;
			exit(0);
		}
	}

	cout << "S" << endl;

	exit(0);
}
