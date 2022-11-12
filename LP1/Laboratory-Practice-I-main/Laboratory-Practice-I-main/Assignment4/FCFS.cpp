#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes :- ";
    cin >> n;
    cout << endl;
    vector<pair<int, pair<int, int>>> v;
    int tat[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Arrival time of process " << i + 1 << " : ";
        int x;
        cin >> x;
        cout << "Burst time of process " << i + 1 << " : ";
        int y;
        cin >> y;
        v.push_back({x, {y, i + 1}});
        cout << endl;
    }
    cout << endl;
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].first > sum)
        {
            sum = v[i].first;
        }
        tat[i] = sum + v[i].second.first - v[i].first;
        sum += v[i].second.first;
    }
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - v[i].second.first;
    }
    cout << "Proc\tAT\tBT\tTAT\tWT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i].second.second << "\t" << v[i].first << "\t" << v[i].second.first << "\t" << tat[i] << "\t" << wt[i] << endl;
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += tat[i];
        sum2 += wt[i];
    }
    cout << endl;
    cout << "Average TurnAroundTime = " << (int)(sum1 / n) << endl;
    cout << "Average Waiting Time = " << (int)(sum2 / n) << endl;
}