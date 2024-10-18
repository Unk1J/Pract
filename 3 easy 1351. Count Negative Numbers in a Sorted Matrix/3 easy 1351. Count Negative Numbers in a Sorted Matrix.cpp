#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = grid[i].size() - 1; j >= 0; --j) {
                if (grid[i][j] < 0)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Solution solution;
    vector<vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    }; // Пример ввода

    int result = solution.countNegatives(grid);

    cout << "Количество отрицательных чисел: " << result << endl;

    return 0;
}
