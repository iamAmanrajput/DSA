// the painters partition problem --(GFG)

#include <iostream>
#include <vector>
using namespace std;

int totalBoardLength(vector<int> &arr)
{
    int totalLength = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        totalLength += arr[i];
    }
    return totalLength;
}

bool isPossible(vector<int> &arr, int k, int mid)
{
    int totalTime = 0;
    int count = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        if (totalTime + arr[i] > mid) // ye condition hai second painter ko allocate karne ki
        {
            count++;
            totalTime = arr[i];
            if (count > k)
            {
                return false;
            }
        }
        else
        {
            totalTime += arr[i];
        }
    }
    return true;
}

class Solution
{
public:
    int minTime(vector<int> &arr, int k)
    {
        int start = 0;
        int end = totalBoardLength(arr);
        int ans = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (isPossible(arr, k, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};