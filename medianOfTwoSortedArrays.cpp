// Median of two Sorted Arrays
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> input1, vector<int> input2)
{
    //if input1 length is greater than switch them so that input1 is smaller than input2.
    // In this way we will always work on the array with smaller length i.e. the input1
    if (input1.size() > input2.size())
    {
        return findMedianSortedArrays(input2, input1);
    }

    int l1 = input1.size();
    int l2 = input2.size();

    int low = 0;
    int high = l1;

    while (low <= high)
    {
        // Remember the below two formulas for this question
        // For more reference watch this YT Video: https://www.youtube.com/watch?v=LPFhl65R7ww
        int partitionX = (low + high) / 2;
        int partitionY = (l1 + l2 + 1) / 2 - partitionX;

        //if partitionX is 0 it means nothing is there on left side. Use -INF for maxLeftX
        //if partitionX is length of input then there is nothing on right side. Use +INF for minRightX
        int maxLeftX = (partitionX == 0) ? INT32_MIN : input1[partitionX - 1];
        int minRightX = (partitionX == l1) ? INT32_MAX : input1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT32_MIN : input2[partitionY - 1];
        int minRightY = (partitionY == l2) ? INT32_MAX : input2[partitionY];

        // Now need to apply the logic in this part

        if (maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            //We have partitioned array at correct place
            // Now get max of left elements and min of right elements to get the median in case of even length combined array size
            // or get max of left for odd length combined array size.
            if ((l1 + l2) % 2 == 0)
            {
                // In case of even length the median is the average of the two middle values
                return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
            }
            else
            {
                return (double)max(maxLeftX, maxLeftY);
            }
        }
        else if (maxLeftX > minRightY)
        {
            //we are too far on right side for partitionX. Go on left side.
            high = partitionX - 1;
        }
        else
        {
            //we are too far on left side for partitionX. Go on right side.
            low = partitionX + 1;
        }
    }

    // If the arrays are not sorted
    return -1;
}

int main()
{
    return 0;
}