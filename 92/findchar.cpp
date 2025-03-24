// finding character in a string using recursion

#include <iostream>
using namespace std;

bool isPresent(string name, char key, int index)
{
    if (name[index] == '\0')
    {
        return false;
    }

    if (name[index] == key)
    {
        return true;
    }
    return isPresent(name, key, index + 1); // yaha return esliye likha bcz previous call ko pata chal sake ki final value kya return ho rhi hai
}

int main()
{
    string name = "amansingh";
    char key = 'r';
    int index = 0;
    bool ans = isPresent(name, key, index);

    if (ans)
    {
        cout << "yes it is present";
    }
    else
    {
        cout << "No it is not present";
    }

    return 0;
}

// No it is not present