class Solution {
public:

int leastInterval(vector<char> &tasks, int n)
{
    priority_queue<pair<int, int>> pq;
    unordered_map<char, int> hashmap;
    vector<char> out;
    
    for (auto x : tasks)
    {
        hashmap[x]++;
    }

    for (auto it = hashmap.begin(); it != hashmap.end(); it++)
    {
        pq.push(make_pair(it->second, it->first));
    }

    queue<pair<int, char>> q;

    // Do it for the first element
    auto top = pq.top();
    pq.pop();
    int countTop = top.first;
    int charTop = top.second;

    out.push_back(charTop);

    pair<int, char> temp = make_pair(countTop - 1, charTop);

    for (int i = 0; i < n; i++)
    {
        q.push(make_pair(0, 0));
    }
    q.push(temp);

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        if(front.first==0)
        {

        }
        else
        {
            pq.push(front);
        }

        if(pq.empty())
        {
            out.push_back('z');
        }
        else
        {
            top = pq.top();
            pq.pop();
            int countTop = top.first;
            int charTop = top.second;

            out.push_back(charTop);

            temp  = make_pair(countTop-1, charTop);

            int qSize = q.size();


            for(int i=0;i<n-qSize;i++)
            {
                q.push(make_pair(0,0));
            }
            q.push(temp);
        }
    }
    reverse(out.begin(), out.end());
    int i=0;
    for(;out[i] == 'z';i++){}
    vector<char> t;
    for(;i<out.size();i++)
    {
        t.push_back(out[i]);
    }
    reverse(t.begin(), t.end());
    out = t;
    return out.size();
}

};