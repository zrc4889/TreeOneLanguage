#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string a, b;
};

vector<Node>
    mem;

int main()
{
    string pos = "hello";
    mem.push_back({"hello", "1"});
    mem.push_back({"bye", "2"});
    for (auto &cur : mem)
    {
        if (cur.a == pos)
        {
            // cout << cur.b << endl;
            cur.b = "FxxK";
        }
    }
    for (auto cur : mem)
    {
        cout << cur.a << ' ' << cur.b << endl;
    }

    return 0;
}