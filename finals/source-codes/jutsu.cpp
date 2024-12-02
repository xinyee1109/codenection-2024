#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> codey;
    vector<int> alien;

    int i = 0;

    while(i < 2*n)
    {
        int temp, temp2;
        cin >> temp >> temp2;

        if(temp == 0)
        {
            codey.push_back(abs(temp2));
        } else {
            alien.push_back(abs(temp));
        }

        i++;
    }

    double sum = 0.0;

    sort(codey.begin(), codey.end());
    sort(alien.begin(), alien.end());

    for(int i = 0; i < n; i++)
    {
        double distance = sqrt(1.0*codey[i]*codey[i] + 1.0*alien[i]*alien[i]);
        sum += distance;
    }

    cout << setprecision(15) << fixed << sum << endl;

    return 0;
}