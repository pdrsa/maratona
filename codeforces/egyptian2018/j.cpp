#include <iostream>
#include <vector>
#include <bitset> 

using namespace std;

int main() {
    int t; cin>>t; int n;
    while(t--){
        cin>>n;
        vector<int>mod(n,0);
        bool prn=false;
        for(int i=(1<<(n-1));i<(1<<n);i++){
            if(i%n!=0)continue;
            int k = i;
            mod.assign(n,0);
            while(k){
                if(mod[k%n])break;
                mod[k%n]=1;
                if(k==1) prn=true;
                k=k>>1;
            }
            if(prn){
                cout<<std::bitset<32>(i)<<endl;
                break;
            }
        }
    }
    return 0;
}
