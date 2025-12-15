// Leetcode Problem 853. Car Fleet

#include <bits/stdc++.h>
using namespace std;

class Solution {

    // Helper class to store car position and speed
    class Car {
    public:
        int pos, speed;
        Car(int p, int s) : pos(p), speed(s) {}
    };

    // Comparator to sort cars based on position (ascending order)
    static bool myComp(Car& a, Car& b) {
        return a.pos < b.pos;
    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<Car> cars;

        // Create car objects from position and speed arrays
        for (int i = 0; i < position.size(); i++) {
            Car car(position[i], speed[i]);
            cars.push_back(car);
        }

        // Sort cars by starting position
        sort(cars.begin(), cars.end(), myComp);

        stack<float> st; // stack to store time to reach target

        // Traverse cars from nearest to farthest
        for (auto car : cars) {

            // Time = distance / speed
            float time = (target - car.pos) / (float)car.speed;

            /*
              If current car takes MORE or EQUAL time than the fleet ahead,
              it will merge with that fleet (cannot overtake),
              so pop the previous fleet time.
            */
            while (!st.empty() && time >= st.top()) {
                st.pop();
            }

            // Push current fleet time
            st.push(time);
        }

        // Number of fleets = stack size
        return st.size();
    }
};

// ------------------- MAIN FUNCTION -------------------
int main() {

    Solution sol;

    // Test case
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    int result = sol.carFleet(target, position, speed);

    cout << "Number of Car Fleets: " << result << endl;

    return 0;
}

// Number of Car Fleets: 3
