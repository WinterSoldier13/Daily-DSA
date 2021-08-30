#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class MedianFinder
{
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder()
    {
        // maxHeap stores the left side of the median of the sorted array
        // 5 2 3 1 6 4
        while (!maxHeap.empty())
            maxHeap.pop();
        while (!minHeap.empty())
            minHeap.pop();
    }

    void addNum(int num)
    {
        if (maxHeap.size() == 0 or maxHeap.top() >= num)
        {
            maxHeap.push(num);
        }
        else
            minHeap.push(num);

        // Now balance
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (minHeap.size() > maxHeap.size())
        {
            return minHeap.top();
        }
        else if (maxHeap.size() > minHeap.size())
            return maxHeap.top();

        return (maxHeap.top() + minHeap.top()) * 0.5;
    }
};
