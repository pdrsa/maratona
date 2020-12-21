#include <bits/stdc++.h>

using namespace std;

int main()
{
    int maiores, n, k, breaker = 0, atual, possible = 0, rights = 0;
    long int counter, menorCounter = 1000000;
    cin >> n >> k;
    long int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int  i = 0; i < n; i++)
    {
        rights = 0;
        counter = 0;
        maiores = 0;

        for (int j = 0; j < n; j++)
        {
            if (nums[j] >= nums[i])
                maiores++;
        }

        if (k > maiores)
            continue;
        
        for (int j = 0; j < n; j++)
        {
            if (rights == k)
                break;
            atual = nums[j];
            while (atual >= nums[i])
            {
                if (atual == nums[i])
                    rights++;
                    break;
                atual = (atual/2);
                counter++;
            }
        }

        if (rights == k)
        {
            if (counter < menorCounter)
            {
                possible = 1;
                menorCounter = counter;
            }
        }
    }

    if (possible == 0)
    {
        counter = 0;
        for (int i = 0; i < n; i++)
        {
            while(nums[i] != 0)
            {
                counter++;
                nums[i] = (nums[i]/2);
            }
        }
        cout << counter;
    }
    else
    {
        cout << menorCounter;
    }
    


    return 0;
}