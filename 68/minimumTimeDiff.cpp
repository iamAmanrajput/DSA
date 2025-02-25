// Minimum Time Difference (LC)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/**
 * Function to find the minimum difference in minutes between any two time points.
 * param timePoints - A vector of strings containing time in "HH:MM" format.
 * return - The minimum time difference in minutes.
 */
int findMinDifference(vector<string> &timePoints)
{
    vector<int> minutes; // Store time points in total minutes

    // Convert HH:MM format into total minutes
    for (int i = 0; i < timePoints.size(); i++)
    {
        string curr = timePoints[i];

        int hours = stoi(curr.substr(0, 2)); // Extract hours and convert to integer
        int min = stoi(curr.substr(3, 2));   // Extract minutes and convert to integer
        int totalMinutes = hours * 60 + min; // Convert full time into minutes
        minutes.push_back(totalMinutes);     // Store converted time
    }

    // Sort the minutes vector so that adjacent comparisons are easier
    sort(minutes.begin(), minutes.end());

    int mini = INT_MAX; // Initialize minimum difference with a large value

    // Find minimum difference between adjacent time points
    for (int i = 0; i < minutes.size() - 1; i++)
    {
        int diff = minutes[i + 1] - minutes[i]; // Difference between consecutive times
        mini = min(mini, diff);                 // Update minimum difference if smaller difference found
    }

    // Handle the circular difference (between last and first time)
    int lastDiff = (minutes[0] + 1440) - minutes[minutes.size() - 1]; // Time gap over midnight
    mini = min(mini, lastDiff);                                       // Update minimum difference

    return mini; // Return the smallest time difference found
}

int main()
{
    vector<string> timePoints; // Vector to store time inputs
    int n;                     // Number of time points

    // User input for number of time points
    cout << "Enter number of time points: ";
    cin >> n;

    // Taking input for time points
    cout << "Enter time points in HH:MM format:\n";
    for (int i = 0; i < n; i++)
    {
        string time;
        cin >> time;
        timePoints.push_back(time); // Store time input in vector
    }

    // Find and print the minimum time difference
    int result = findMinDifference(timePoints);
    cout << "Minimum time difference: " << result << " minutes" << endl;

    return 0; // Exit the program
}
