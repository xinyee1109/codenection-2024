#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x, y, k;
    cin >> x >> y >> k;

    long long mx = 0;

    for(long long i = 1; i <= x; i++)
    {
        if(k % i != 0)
            continue;                
        else
        {
            long long b = k / i;

            if(b <= y)
            {
                long long temp = (x-i+1) * (y-b+1);
                mx = max(temp, mx);                    
            }
        }
    }

    cout << mx << endl;

    return 0;
}