#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        // int n;
        // cin>>n;
        // vector<int> start(n,0);
        // vector<int> end_(n,0);
        // for(int i=0;i<n;i++)
        // cin>>start[i];
        // for(int i=0 ;i<n;i++)
        // cin>>end_[i];

        vector<int> start{1, 3, 0, 5, 8, 5};
        vector<int> end_{2, 4, 6, 7, 9, 9};
        int n = 6;

        vector<pair<int, int>> slots;
        for (int i = 0; i < n; i++)
        {
            slots.push_back(make_pair(start[i], end_[i]));
        }
        start.clear();
        end_.clear();

        sort(slots.begin(), slots.end());

        vector<vector<pair<int, int>>> rooms;

        for (auto slot : slots)
        {
            int currentBegin = slot.first;
            int currentEnd = slot.second;
            cout << "CURRENT: " << currentBegin << " " << currentEnd << endl;
            if (rooms.empty())
            {
                vector<pair<int, int>> temp;
                temp.push_back(make_pair(currentBegin, currentEnd));
                rooms.push_back(temp);
                continue;
            }
            bool found = false;

            for (int i = 0; i < rooms.size(); i++)
            {
                auto room = rooms[i];
                int prevBegin = room[room.size() - 1].first;
                int prevEnd = room[room.size() - 1].second;

                if (currentBegin > prevEnd)
                {
                    rooms[i].push_back(make_pair(currentBegin, currentEnd));
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                vector<pair<int, int>> temp;
                temp.push_back(make_pair(currentBegin, currentEnd));
                rooms.push_back(temp);
            }
        }

        for (auto x : rooms)
        {
            for (auto c : x)
            {
                cout << c.first << " " << c.second << " || ";
            }
            cout << endl;
        }
    }
}