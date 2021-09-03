#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// class MedianFinder {
// public:

// 	priority_queue<int> pq;
// 	vector<int> helperArr;

//     MedianFinder()
//     {
//         helperArr.push_back(0);
//         helperArr.pop_back();
//         pq.push(1);
//         pq.pop();
//     }

// 	void updateHelper()
// 	{
// 		priority_queue<int> temp = pq;
// 		helperArr.clear();
// 		while(!temp.empty())
// 		{
// 			helperArr.push_back(temp.top());
// 			temp.pop();
// 		}
// 	}

//     void addNum(int num)
// 	{
// 		pq.push(num);
//         updateHelper();
//     }

//     double findMedian()
// 	{
// 		int l = helperArr.size();

// 		if(l%2!=0)
// 		{
// 			return helperArr[(int)((l-1)/2)];
// 		}
// 		else
// 		{
// 			double val1 = helperArr[(l/2)-1];
// 			double val2 = helperArr[(l/2)];
// 			return ans  = (val1 + val2 )/2;
// 		}
//     }
// };

class MedianFinder
{
public:
	/** initialize your data structure here. */
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int size;

	MedianFinder()
	{
		maxHeap.push(1);maxHeap.pop();
		minHeap.push(1);minHeap.pop();
		size = 0;
	}


//  Just remember this
	void addNum(int num)
	{
		size++;
		maxHeap.push(num);
		minHeap.push(maxHeap.top());
		maxHeap.pop();

		if(maxHeap.size() < minHeap.size())
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}

	double findMedian()
	{
		if(maxHeap.size()> minHeap.size())
		{
			return maxHeap.top();
		}
		else
		{
			return (maxHeap.top()+minHeap.top())*0.5;
		}
		
	}
};

int main()
{

	auto ob = MedianFinder();

	ob.addNum(1);
	ob.addNum(2);

	cout << ob.findMedian() << endl;

	ob.addNum(3);
	cout << ob.findMedian() << endl;
}
