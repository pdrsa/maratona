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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int a, b; cin >> a >> b;
		
		int wa = 0, wb = 0;
		
		if(a > b){
			wa += (a-b); //make equal
			wa += b/2; //floor
			wb += (b+1)/2; //ceil
		}

		else{
			a--; //alice starts
			wb += (b-a); //make equal
			wb += a/2; //floor
			wa += (a+1)/2; //ceil
		}

		cout << wa << " " << wb << endl;
	}
	exit(0);
}
