// Book Allocation Proble -- GFG

#include <iostream>
using namespace std;

int findMax(int arr[], int n)
{
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int findSum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

bool isPossibleSolution(int arr[], int n, int k, int sol)
{
    int pageSum = 0;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > sol)
        {
            return false;
        }
        if (pageSum + arr[i] > sol)
        {
            count++;
            pageSum = arr[i];
            if (count > k)
            {
                return false;
            }
        }
        else
        {
            pageSum += arr[i];
        }
    }
    return true;
}

int findPages(int arr[], int n, int k)
{
    if (k > n)
    {
        return -1;
    }
    int start = findMax(arr, n);
    int end = findSum(arr, n);
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossibleSolution(arr, n, k, mid))
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

int main()
{
    int arr[] = {12, 34, 67, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // Number of students
    cout << "Minimum number of pages: " << findPages(arr, n, k) << endl;
    return 0;
}
