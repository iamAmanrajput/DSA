// 13. Roman to Integer -- (LC)
// # simple method -- TC = 0(N)

#include <iostream>
using namespace std;

// ✅ Function to Convert Single Roman Character to Integer
int convertRomanToInt(char ch)
{
    if (ch == 'I')
        return 1;
    else if (ch == 'V')
        return 5;
    else if (ch == 'X')
        return 10;
    else if (ch == 'L')
        return 50;
    else if (ch == 'C')
        return 100;
    else if (ch == 'D')
        return 500;
    else
        return 1000;
}

// ✅ Function to Convert Full Roman String to Integer
int romanToInt(string s)
{
    int totalNum = 0;
    int end = s.size() - 1;
    int i = 0;

    while (i <= end)
    {
        int currVal = convertRomanToInt(s[i]);
        int nextVal = 0;

        if (i + 1 <= end)
        {
            nextVal = convertRomanToInt(s[i + 1]);
        }

        if (nextVal > currVal)
        {
            totalNum += (nextVal - currVal);
            i += 2;
        }
        else
        {
            totalNum += currVal;
            i++;
        }
    }

    return totalNum;
}

// ✅ Main Function
int main()
{
    string roman;

    cout << "Enter a Roman numeral: ";
    cin >> roman;

    int result = romanToInt(roman);
    cout << "Integer value: " << result << endl;

    return 0;
}

// Input
//  Enter a Roman numeral: MCMXCIV

// output
//  Integer value: 1994