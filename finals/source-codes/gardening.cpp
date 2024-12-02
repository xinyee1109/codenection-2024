#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) { 
    return a.second > b.second; 
} 

int main()
{
    int n;
    cin >> n;

    map<string, int> score;
    for(int i = 0; i < n; i++)
    {
        string temp;
        int tempnum;
        cin >> temp >> tempnum;
        score[temp] += tempnum;
    }

    vector<pair<string, int>> scores(score.begin(), score.end());

    sort(scores.begin(), scores.end(), cmp); 

    int rank = 0;
    int prev = 0;
    for (int i = 0; i < scores.size(); i++) {
        if (scores[i].second != prev) {
            rank++;
            prev = scores[i].second;
        }
        if (scores[i].first == "codey") {
            cout << rank;
            break;
        }
    }
    
    return 0;
}
