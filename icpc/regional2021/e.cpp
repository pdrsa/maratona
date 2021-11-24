//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	int n; cin >> n;
	int time = 0;
	int wait = -1;
	int direction = -1;
	while(n--){
		int a, dir; cin >> a >> dir;
		
		if(a > time){ // Stair isn't moving
			if(wait != -1){
				time += 10;
				direction = wait;
				wait = -1;
			}

			if(a > time) direction = -1;
		}

		if(direction == -1 or direction == dir){
			time = a+10;
			direction = dir;
		} else wait = dir;
	}

	if(wait != -1) time += 10;
	cout << time << endl;
	exit(0);
}
