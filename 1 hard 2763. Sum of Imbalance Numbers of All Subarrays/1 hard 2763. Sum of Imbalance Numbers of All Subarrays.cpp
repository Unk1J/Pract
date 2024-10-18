#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            vector<bool> seen(1001, false); // Предполагаем, что элементы nums ограничены от 0 до 1000
            int currcount = 0;

            for (int j = i; j < n; j++) {
                if (!seen[nums[j]]) {
                    if (nums[j] > 0 && nums[j] < 1000 && seen[nums[j] + 1] && seen[nums[j] - 1]) {
                        currcount--;
                    }
                    else if ((nums[j] == 0 || !seen[nums[j] - 1]) &&
                        (nums[j] == 1000 || !seen[nums[j] + 1])) {
                        currcount++;
                    }
                }
                seen[nums[j]] = true;
                count += currcount;
            }
        }

        return count;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Solution solution;
    vector<int> nums = { 1, 3, 2, 1 };
    int result = solution.sumImbalanceNumbers(nums);

    cout << "Сумма чисел дисбаланса: " << result << endl;

    return 0;
}
