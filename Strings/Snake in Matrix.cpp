// Leetcode Contest
int finalPositionOfSnake(int n, vector<string>& commands) {
    int i = 0, j = 0;
    for (string s : commands) {
        if (s == "LEFT") {
            j--;
        } else if (s == "RIGHT") {
            j++;
        } else if (s == "DOWN") {
            i++;
        } else if (s == "UP") {
            i--;
        }
    }
    return i * n + j;
}

// Another Approach
class Direction {
    public:
    pair<int, int>dir;
    string command;
};

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        vector<vector<int>>cell(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cell[i][j] = (i * n) + j;
            }
        }
        
        vector<Direction> v = {
            {{-1, 0}, "UP"},
            {{0, 1}, "RIGHT"},
            {{1, 0}, "DOWN"},
            {{0, -1}, "LEFT"}
        };

        pair<int, int> start = {0, 0};

        for(const string &s : commands) {
            auto it = find_if(v.begin(), v.end(), [&s](const Direction& d) {
                return d.command == s;
            });

            if(it != v.end()) {
                int x = start.first + it->dir.first;
                int y = start.second + it->dir.second;

                if( x >= 0 && x < n && y >= 0 && y < n) {
                    start.first = x;
                    start.second = y;
                }
            }
        }

        return cell[start.first][start.second];
    }
};

// Input: n = 3, commands = ["DOWN","RIGHT","UP"]
// Output: 1
