// Binary Search using recursion

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> v, int s, int e, int target)
{

    // key not found
    if (s > e)
    {
        return -1;
    }

    // finding mid
    int mid = s + (e - s) / 2;

    // key found
    if (v[mid] == target)
    {
        return mid;
    }

    // right search
    if (v[mid] < target)
    {
        return binarySearch(v, mid + 1, e, target);
    }
    else
    { // left search
        return binarySearch(v, s, mid - 1, target);
    }
}

int main()
{

    vector<int> v{10, 20, 30, 40, 50, 60, 70};
    int target = 60;

    int n = v.size();
    int s = 0;
    int e = n - 1;
    int ans = binarySearch(v, s, e, target);

    cout << "Ans is : " << ans << endl;

    return 0;
}

// output
// Ans is : 5
