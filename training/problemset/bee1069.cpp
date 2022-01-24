#include <iostream>
#include <string>
 
using namespace std;


int main(){
   	int n; cin >> n;
    while(n--){
		string diamante;
    	cin >> diamante;
		int con = 0;
		int ans = 0;
		for(auto c: diamante){
			if(c == '<') con++;
			if(c == '>')
				if(con){
					ans++;
					con--;
				}
		}
		cout << ans << endl;
    }
    return 0;
}
