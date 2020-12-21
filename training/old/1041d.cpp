#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool invert(bool a){
	if (a == true)
		return false;
	else
		return true;
}

int main(){
	ll maior = 0, n, h, l = 0, r = 0, pl = 0, pr = 0;
	bool il = false, ir = false;
	
	cin >> n >> h;

	ll arr[2*n];

	for (ll i = 0; i < 2*n; i++)
	{
		cin >> arr[i];
	}


	while (pl < 2*n){
		while(r < 10e9 && h > 0){

			if (arr[pr] == r){
				ir = invert(ir);
				pr++;
			}

			if (ir)
				r = arr[pr];
			else{
				if (arr[pr] - r > h){
					r += h;
					h = 0;
				}
				else{
					h = h - (arr[pr] - r);
					r = arr[pr];
				}
			}
		}

		if (maior < r - l)
			maior = r - l;

		if(arr[pl] == l){
			il = invert(il);
			pl++;
		}

		if(il)
			l = arr[pl];
		
		else{
			if (arr[pl] > r){
					h += r - l;
					l = r;
				}
				else{
					h = h + (arr[pl] - l);
					l = arr[pl];
				}
		}
	}

	cout << maior;


	return 0;
}