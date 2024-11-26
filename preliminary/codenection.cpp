#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string p = "CODENECTION";
    
    for(int i = 0; i < n; i++)
    {
        for(int j = n-1; j > i; j--)
        {
            cout << " ";
        }
        
        for(int k = 0; k < i+1; k++)
        {
            cout << p[k];
        }
        
        cout << endl;
    }

    return 0;
}
