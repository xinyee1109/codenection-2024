#include <bits/stdc++.h>
using namespace std;

int main()
{
        long long n, x;
        cin >> n >> x;

        long long lines = 2*n - 1;
        long long sum = 0;
        long long start = 1, end = lines;
        long long total = lines;

        while(start <= end)
        {
            long long mid = start + (end - start)/2;
            sum = (mid*(mid+1))/2;

            if(mid > n)
            {
                sum = n*(n+1)/2 + ((n-1)*n)/2 - (lines-mid)*(lines-mid+1)/2;
            }

            if(sum == x)
            {
                total = mid;
                break;
            } 
            else if (sum > x)
            {
                total = mid;
                end = mid - 1;
            } 
            else 
            {
                start = mid + 1;
            }
        }
        cout << total << endl;

    return 0;
}