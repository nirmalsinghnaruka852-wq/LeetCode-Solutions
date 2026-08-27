using pii = pair<int, int>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using vpii = vector<pair<int, int>>;

class Node {
public:
    int row;
    int col;
    int mask;

    Node(int row, int col, int mask)
        : row(row), col(col), mask(mask) {}
};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {

        vpii dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int rows = grid.size();
        int cols = grid[0].size();

        int keyCount = 0;
        pii start = {0, 0};

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                char cell = grid[row][col];

                if (cell == '@') {
                    start = {row, col};
                }
                else if ('a' <= cell && cell <= 'z') {
                    keyCount++;
                }
            }
        }

        int totalMasks = 1 << keyCount;
        int fullMask = totalMasks - 1;

        vvvb visited(
            rows,
            vvb(cols, vb(totalMasks, false))
        );

        queue<Node*> q;

        q.push(new Node(start.first, start.second, 0));
        visited[start.first][start.second][0] = true;

        int level = 0;
        int size = q.size();

        while (!q.empty()) {

            Node* node = q.front();
            q.pop();
            size--;

            if (node->mask == fullMask)
                return level;

            for (pii& dir : dirs) {

                int nr = node->row + dir.first;
                int nc = node->col + dir.second;

                if (nr < 0 || nc < 0 ||
                    nr >= rows || nc >= cols || grid[nr][nc] == '#')
                    continue;

                char cell = grid[nr][nc];

                int newMask = node->mask;

                // Key
                if ('a' <= cell && cell <= 'z') {

                    int key = cell - 'a';

                    newMask |= (1 << key);
                }

                else if ('A' <= cell && cell <= 'Z') {

                    int key = cell - 'A';

                    if (!(newMask & (1 << key)))
                        continue;
                }

                if (visited[nr][nc][newMask])
                    continue;

                visited[nr][nc][newMask] = true;

                q.push(new Node(nr, nc, newMask));
            }

            if (size == 0) {
                size = q.size();
                level++;
            }
        }

        return -1;
    }
};