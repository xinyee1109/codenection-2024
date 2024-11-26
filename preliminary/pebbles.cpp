#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    int countOdd = 0, countEven = 0;
    int oddidx = -1, evenidx = -1;

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];

        if (v[i] % 2 == 0)
        {
            countEven++;
            evenidx = i+1;
        }
        else
        {
            countOdd++;
            oddidx = i+1;
        }
    }

    if(countEven > countOdd)
        cout << oddidx;
    else
        cout << evenidx;
    
    return 0;
}
