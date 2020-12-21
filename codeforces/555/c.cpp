#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    deque <int> num(n);
    vector <char> seq;
    vector <int> seqNums;
    for (int i = 0; i < n; i++)
        cin >> num[i];


    seqNums.push_back(0);

    int happens = 1;
    while (num.size() > 0)
    {
        if (happens == 0)
            break;
        happens = 0;
        if (num[num.size() - 1] < num[0]) {
            if (num[num.size() - 1] > seqNums[seqNums.size() - 1])
            {
                seq.push_back('R');
                seqNums.push_back(num[num.size() -1]);
                num.erase(num.end());
                happens = 1;
            }
            else if (num[0] > seqNums[seqNums.size() - 1]) {
                seq.push_back('L');
                seqNums.push_back(num[0]);
                num.erase(num.begin());
                happens = 1;
            }
        }
        else {
            if (num[0] > seqNums[seqNums.size() - 1])
            {
                seq.push_back('L');
                seqNums.push_back(num[0]);
                num.erase(num.begin());
                happens = 1;
            }
            else if (num[num.size() - 1] > seqNums[seqNums.size() - 1]){
                seq.push_back('R');
                seqNums.push_back(num[num.size() -1]);
                num.erase(num.end());
                happens = 1;
            }
        }
    }

    cout << seq.size() << endl;
    for (int i = 0; i < seq.size(); i++)
        cout << seq[i];

   return 0;
}