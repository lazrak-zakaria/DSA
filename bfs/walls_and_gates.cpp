#include <iostream>
#include <queue>
#include <vector>

using namespace std;


typedef struct 
{
    int r, c;
} cell ;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool is_valid(vector< vector<int> >&rooms, int r, int c)
{
    if (r < 0 || r >= rooms.size())
        return (0);
    if (c < 0 || c >= rooms[0].size())
        return 0;
    if (rooms[r][c] == 0 || rooms[r][c] == -1)
        return (0);
    return 1;
}
void    bfs(vector< vector<int> >&rooms, cell c)
{
    queue<cell> q;
    q.push(c);
    for (int lev = 0 , sz = 1; !q.empty(); ++lev , sz  = q.size())
    {
        while (sz--)
        {
            c = q.front();
            q.pop();
        
        for (int i = 0; i < 4; ++i)
         {
                 if (!is_valid(rooms, c.r + dr[i], c.c + dc[i]))
                  continue;
              if (lev + 1 <= rooms[c.r + dr[i]][c.c+dc[i]])
              {
                     rooms[c.r + dr[i]][c.c + dc[i]] = lev + 1;
                  q.push({c.r + dr[i], c.c + dc[i]});
              }
        }
        }
    }
}

void    wallsAndGates(vector< vector<int> >&rooms)
{
    for (int i = 0; i < rooms.size(); ++i)
    {
        for (int j = 0; j < rooms[0].size(); ++j)
        {
            if (rooms[i][j] == 0)
            {
                bfs(rooms, {i, j});
            }
        }
    }
}
#define INF 2147483647
int main()
{
vector<vector<int> >v = {
 {   INF , -1 , 0,  INF},
{INF, INF ,INF , -1},
{INF , -1, INF,  -1},
 { 0, -1, INF ,INF}
};

// vector<vector<int> >v = {{INF}};
wallsAndGates(v);

for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[0].size(); ++j)
        {
            cout << v[i][j] << "      ";
        }
        cout << "\n";
    }

    return (0);
}