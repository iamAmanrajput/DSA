// Leetcode Problem 295. Find Median from Data Stream

#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    // max heap -> left side (smaller elements)
    priority_queue<int> maxi;

    // min heap -> right side (greater elements)
    priority_queue<int, vector<int>, greater<int>> mini;

    double median;

    MedianFinder()
    {
        median = 0;
    }

    // helper to check size relation between heaps
    int signum(int a, int b)
    {
        if (a == b)
            return 0;
        else if (a > b)
            return 1;
        else
            return -1;
    }

    void addNum(int element)
    {

        // decide case based on heap sizes
        switch (signum(maxi.size(), mini.size()))
        {

        // case 0: both heaps equal size
        case 0:
            if (element > median)
            {
                mini.push(element);
                median = mini.top();
            }
            else
            {
                maxi.push(element);
                median = maxi.top();
            }
            break;

        // case 1: maxi has more elements
        case 1:
            if (element > median)
            {
                mini.push(element);
            }
            else
            {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
            }
            median = (mini.top() + maxi.top()) / 2.0;
            break;

        // case -1: mini has more elements
        case -1:
            if (element > median)
            {
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
            }
            else
            {
                maxi.push(element);
            }
            median = (mini.top() + maxi.top()) / 2.0;
            break;
        }
    }

    double findMedian()
    {
        return median;
    }
};

int main()
{
    MedianFinder mf;

    // test stream
    vector<int> nums = {5, 15, 1, 3};

    cout << "Adding numbers and printing median:\n";

    for (int num : nums)
    {
        mf.addNum(num);
        cout << "Inserted: " << num
             << " -> Median: " << mf.findMedian() << endl;
    }

    return 0;
}

// Inserted: 5 -> Median: 5
// Inserted: 15 -> Median: 10
// Inserted: 1 -> Median: 5
// Inserted: 3 -> Median: 4