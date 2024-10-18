#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;

            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }

            if (count > mid) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 1, 3, 4, 2, 2 }; 
    int duplicate = solution.findDuplicate(nums);

    cout << "Дубликатное число: " << duplicate << endl;

    return 0;
}
