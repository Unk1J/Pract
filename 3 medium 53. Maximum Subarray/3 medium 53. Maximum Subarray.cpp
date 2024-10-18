#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i, curSum = 0; j < n; j++) {
                curSum += nums[j];
                ans = max(ans, curSum);
            }
        }
        return ans;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Solution solution;
    vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 }; 
    int maxSum = solution.maxSubArray(nums);

    cout << "Максимальная сумма подмассива: " << maxSum << endl;

    return 0;
}
