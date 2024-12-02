#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    double first = (a*c - b)*e;
    double second = (d - f*e)*c;

    //double first = a - (b/c);
    //double second = (d/e) - f;

    //cout << first << " " << second << endl;

    if (first > second)
        cout << ">";
    else if (first < second)
        cout << "<";
    else
        cout << "=";
    return 0;
}