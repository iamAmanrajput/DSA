// prev smaller element
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{

    vector<int> v = {2, 1, 4, 3};

    stack<int> st;
    st.push(-1);

    vector<int> ans(v.size());

    for (int i = 0; i < v.size(); i++)
    {
        int curr = v[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }

    cout << "printing" << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}

// -1 -1 1 1
