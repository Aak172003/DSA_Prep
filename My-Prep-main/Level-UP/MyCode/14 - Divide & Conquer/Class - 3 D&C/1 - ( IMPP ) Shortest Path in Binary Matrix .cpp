/*

************************* MyNotes ******************* 
LeetCode Link - https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
YtubeLink - https://youtu.be/p4kOKdLmktg
*/

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        // Edge Case
        if (grid[0][0] != 0)
        {
            return -1;
        }

        if (grid[0][0] == 0 && grid.size() == 1 && grid[0].size() == 1)
            return 1;

        // abovepair = pair<int,int>
        // pair < abovepair , int >
        queue<pair<pair<int, int>, int>> q;
        // Push 1st Coordinate
        q.push({{0, 0}, 1});

        // need a visited matrix
        // make vector of vector means 2D matrix
        // whole row grid.size ke barabar hai ,
        // or us 1 row me ek vector pda hai grid.size ka jisme initially value
        // false bhari hai
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
        // Initially visited ka top left mark as true
        visited[0][0] = true;

        // jb tk que empty na ho
        while (!q.empty())
        {
            // Note - queue me pair ke and ek to paired me element jaega or ek int term me
            pair<int, int> p = q.front().first; // extract {0,0} from queue
            int x = p.first;
            int y = p.second;
            int lengthofPath = q.front().second; // 1 initialy

            // after extracting the length pop the element
            q.pop();

            //  This is visited neighbours for any cell , 8 ways to move
            vector<pair<int, int>> neighbours = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

            for (pair<int, int> neighbour : neighbours)
            {
                int newX = neighbour.first + x;
                int newY = neighbour.second + y;

                // Here Check the neighbour is vallid or not
                if (newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid.size() && grid[newX][newY] == 0 && !visited[newX][newY])
                {
                    // if satisfy above condition , then put into queue
                    q.push({{newX, newY}, lengthofPath + 1});
                    // mark visited is true
                    visited[newX][newY] = true;

                    // Check wheteher i reach end cell or not
                    if (newX == grid.size() - 1 && newY == grid[0].size() - 1)
                    {
                        return lengthofPath + 1;
                    }
                }
            }
        }
        return -1;
    }
};