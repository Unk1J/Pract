#include <iostream>
#include <vector>
#include <cmath> // Для функции abs

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int x = abs(nums[i]);
            if (nums[x - 1] < 0) {
                ans.push_back(x); // Добавляем число в результат, если оно уже встречалось
            }
            nums[x - 1] *= -1; // Меняем знак числа на -1, чтобы пометить его
        }

        return ans;
    }
};

// Функция для вывода списка чисел
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    Solution solution;

    // Пример вектора чисел
    vector<int> nums = { 4, 3, 2, 7, 8, 2, 3, 1 };

    // Поиск всех дубликатов
    vector<int> result = solution.findDuplicates(nums);

    // Выводим результат
    cout << "Дубликаты: ";
    printVector(result);

    return 0;
}
