// Leetcode Problem 901. Online Stock Span

#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    // Stack will store pairs: {price, span}
    stack<pair<int, int>> st;

    StockSpanner() {}

    // Returns the stock span for the current day's price
    int next(int price)
    {
        int span = 1; // Minimum span is always 1 (current day)

        // Merge spans of all previous prices <= current price
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second; // Add their span
            st.pop();                // Remove them from stack
        }

        // Push current price with its calculated span
        st.push({price, span});
        return span;
    }
};

// --------------------------------------------------------
//                     TESTCASE + MAIN
// --------------------------------------------------------

int main()
{
    StockSpanner ss;

    // Testcase input: prices sequence
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    cout << "Stock Spanner Result:\n";

    for (int price : prices)
    {
        cout << "Price: " << price
             << " -> Span: " << ss.next(price) << endl;
    }

    return 0;
}

// 100, 80, 60, 70, 60, 75, 85

// Price: 100 -> Span: 1
// Price: 80 -> Span: 1
// Price: 60 -> Span: 1
// Price: 70 -> Span: 2
// Price: 60 -> Span: 1
// Price: 75 -> Span: 4
// Price: 85 -> Span: 6
