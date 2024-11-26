#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int> >v(n);
    int countN = 0;
    int countP = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;

        if(v[i].first > 0)
            countP++;
        else
            countN++;
    }

    sort(v.begin(), v.end());

    int j = countN - 1, k = countN;
    int sum = 0;

    int res = min(countP, countN);

    for(int i = 0; i < res; i++)
    {
        sum += (v[j].second + v[k].second);
        j--, k++;
    }

    if(countP > countN)
        sum += v[k].second;
    else if (countP < countN)
        sum += v[j].second;

    cout << sum;

    return 0;
}
