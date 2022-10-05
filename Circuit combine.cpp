#include <bits/stdc++.h>

using namespace std;

vector<int> v[1000005];
bool visited[1000005];

// ฟังชั่นนี้หาว่าจากตัวที่ x สามารถเดินต่อไปได้อีกไกลสุดกี่ก้าวโดยที่ไม่เดินไปทับตัวที่เคยเดินไปแล้ว
int dfs(int x)
{
    visited[x] = true;
    int i;
    int traveled = 0;
    for (i = 0; i < v[x].size(); i++)
    {
        int next = v[x][i];

        if (!visited[next])
        {
            traveled = max(dfs(next) + 1, traveled);
            visited[next] = false;
        }
    }
    return traveled;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string s;
            cin >> s;
            if (s == "True")
            {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }

    if (dfs(0) + 1 == n)
    {
        cout << "Complete circuit";
    }
    else
    {
        cout << "Incomplete circuit";
    }
}

//####################
// 4
// False
// True
// False

// True
// False

// True

//####################
// 5
// True
// True
// True
// False

// True
// False
// False

// False
// True

// True

//####################
// 5
// False
// False
// False
// False

// False
// False
// False

// False
// False

// False

//####################
// 5
// True
// True
// True
// True

// True
// True
// True

// True
// True

// True

//####################
// 4
// True
// True
// False

// True
// False

// True