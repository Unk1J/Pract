#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int x = 0;
        vector<int> v;

        for (int i = 0; i < n; i++) {
            if (x == 0) {
                v.push_back(nums[i]);
                x = 1;
                i--;
            }
            else {
                v.push_back(nums[n + i]);
                x = 0;
            }
        }

        return v;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Solution solution;
    vector<int> nums = { 2, 5, 1, 3, 4, 7 };  
    int n = 3;  
    vector<int> result = solution.shuffle(nums, n);

    cout << "Результат: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
