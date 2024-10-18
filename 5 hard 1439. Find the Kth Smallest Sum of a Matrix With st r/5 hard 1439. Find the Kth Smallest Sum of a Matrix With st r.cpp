#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int l = m, r = 200000;
        int res = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (count(mat, k, 0, mid) < k) {
                l = mid + 1;
            }
            else {
                res = mid;
                r = mid - 1;
            }
        }

        return res;
    }

    int count(vector<vector<int>>& mat, int k, int r, int target) {
        if (target < 0)
            return 0;
        if (r == mat.size())
            return 1;

        int res = 0;
        for (int i = 0; i < mat[0].size(); ++i) {
            int cnt = count(mat, k, r + 1, target - mat[r][i]);
            if (cnt == 0)
                break;
            res += cnt;
            if (res > k)
                break;
        }
        return res;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Solution solution;

    vector<vector<int>> mat = {
        {1, 3, 11},
        {2, 4, 6}
    };
    int k = 5;

    int result = solution.kthSmallest(mat, k);

    cout << "k-й наименьший элемент: " << result << endl;

    return 0;
}
