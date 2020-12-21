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
	int cases; cin >> cases;
	while(cases--){
		double h, c, t; cin >> h >> c >> t;

		if(t >= h){
			cout << 1 << endl;
			continue;
		}
		
		if((c+h) / 2 >= t){
			cout << 2 << endl;
			continue;
		}

		double x = (h-t)/(2*t-h-c);
		x = int(x);
		
		double val1 = ((x+1)*h + x*c) / (2*x+1);
		x++;
		double val2 = ((x+1)*h + x*c) / (2*x+1);
		
		val1 = abs(val1 - t);
		val2 = abs(val2 - t);
		
		if (val1 > val2) cout << 2*x+1 << endl;
		else cout << 2*x-1 << endl;
	}
	exit(0);
}
