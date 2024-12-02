#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    multiset<ll> track;
    ll res = 0, num = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(res + a[i] >= 0)
        {
            track.insert(a[i]);
            res += a[i];
            num++;
        } else if (!track.empty() && *track.begin() < a[i])
        {
            res -= *track.begin();
            track.erase(track.begin());
            track.insert(a[i]);
            res += a[i];

        }
    }

    cout << num << endl;

    return 0;
}