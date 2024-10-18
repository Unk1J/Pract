#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for (int i = n - 1; i >= 0; i--) {
            while (nums[i] > 0) {
                int digit = nums[i] % 10;
                nums[i] /= 10;
                ans.push_back(digit);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Solution solution;
    vector<int> nums = { 123, 45, 6798 }; 
    vector<int> result = solution.separateDigits(nums);

    cout << "Результат: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
