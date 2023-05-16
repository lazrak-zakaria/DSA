#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:

 bool bfs(vector<int>& arr, int &start)
    {
        queue<int> q;
        q.push(start);
        vector<int> vis(arr.size());
        if (!arr[start])
            return (true);
         int size = arr.size();
        while (!q.empty())
        {
            int c = q.front();
            q.pop();
            if ((arr[c] + c >= 0 && arr[c] + c <size) && !vis[arr[c] + c])
            {
                if (arr[arr[c] + c] == 0)
                    return (true);
                q.push(arr[c] + c );
                vis[arr[c] + c] = 1;
            }
            int l = c - arr[c];
            if ((l>= 0 && l < size) && !vis[l])
            {
                
                if (arr[l] == 0)
                    return (true);
                q.push(l);
                vis[l] = 1;
            }
        }
        return (false);
    }
        bool canReach(vector<int>& arr, int start) {
        return (bfs(arr, start));
    }
};
