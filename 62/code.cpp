#include <iostream>
using namespace std;

// Find the total sum of pages
int sumOfPages(int arr[], int n)
{
    int totalPages = 0;
    for (int i = 0; i < n; i++)
    {
        totalPages += arr[i];
    }
    return totalPages;
}

// Check if the current mid (sol) can be a possible solution
bool isPossibleSolution(int arr[], int b, int s, int sol, int n)
{
    int pageSum = 0;
    int count = 1; // Start with first student

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > sol)
        { // If any book has pages more than sol, allocation is impossible
            return false;
        }

        if (pageSum + arr[i] > sol)
        {
            // Allocate this book to next student
            count++;
            pageSum = arr[i];

            // If students exceed the limit, return false
            if (count > s)
            {
                return false;
            }
        }
        else
        {
            pageSum += arr[i]; // Continue adding pages to the current student
        }
    }
    return true;
}

// Find minimum number of pages allocated to a student
int findPages(int arr[], int b, int s, int n)
{
    // If students are more than books, allocation isn't possible
    if (s > b)
    {
        return -1;
    }

    int start = 0;
    int end = sumOfPages(arr, n);
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2; // Fix: Correct way to find mid

        if (isPossibleSolution(arr, b, s, mid, n))
        {
            ans = mid;     // Store the valid minimum pages
            end = mid - 1; // Try to minimize the answer
        }
        else
        {
            start = mid + 1; // Increase the value of mid
        }
    }
    return ans;
}

int main()
{
    int arr[] = {12, 34, 67, 90};
    int size = sizeof(arr) / sizeof(int);
    int students = 2;
    int noOfBooks = 4;

    int result = findPages(arr, noOfBooks, students, size);
    cout << "Minimum pages allocated to a student: " << result << endl;
    return 0;
}
