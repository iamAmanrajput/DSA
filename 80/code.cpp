// string compression --(LC)

#include <bits/stdc++.h>
using namespace std;

// ✅ Function to compress the string
int compressString(vector<char> &s)
{
    int index = 0, count = 1;
    char prev = s[0];

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == prev)
        {
            count++; // Current character repeat ho raha hai
        }
        else
        {
            s[index] = prev; // Unique character store karna
            index++;

            // Agar character 2+ baar aya ho toh count bhi store karo
            if (count > 1)
            {
                int start = index;
                while (count)
                {
                    s[index] = (count % 10) + '0'; // Convert count to character
                    index++;
                    count /= 10;
                }
                reverse(s.begin() + start, s.begin() + index); // Reverse digits
            }

            prev = s[i]; // Next character ke liye update
            count = 1;   // Reset count
        }
    }

    // eske esliye karna pad rha hai bcz humne count to ++ kar diya tha but add nhi kiya tha main string me -- doubt hai to video no -80 , dry run dekho 7.40
    // ✅ Last character ka handling
    s[index] = prev;
    index++;
    if (count > 1)
    {
        int start = index;
        while (count)
        {
            s[index] = (count % 10) + '0';
            index++;
            count /= 10;
        }
        reverse(s.begin() + start, s.begin() + index);
    }

    return index; // New compressed size return karo
}

// ✅ Function to print compressed string
void printCompressedString(vector<char> &chars, int newSize)
{
    cout << "Compressed characters: ";
    for (int i = 0; i < newSize; i++)
    {
        cout << chars[i] << " ";
    }
    cout << endl;

    // ✅ Print new size
    cout << "New size: " << newSize << endl;
}

// ✅ Main function (Driver Code)
int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'}; // Example input

    int newSize = compressString(chars);   // Call compress function
    printCompressedString(chars, newSize); // Print compressed output

    return 0;
}

// output
//  Compressed characters: a 2 b 2 c 3
//  New size: 6