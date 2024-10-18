#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 1) {
            vector<int> singleList;
            singleList.push_back(nums[0]);
            res.push_back(singleList);
            return res;
        }

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            vector<int> remainingNums;

            // Формируем новый массив без текущего элемента
            for (int j = 0; j < nums.size(); j++) {
                if (j != i) {
                    remainingNums.push_back(nums[j]);
                }
            }

            // Рекурсивно вызываем permute для оставшегося массива
            vector<vector<int>> perms = permute(remainingNums);
            for (vector<int> p : perms) {
                p.insert(p.begin(), n);  // Вставляем n в начало перестановки
                res.push_back(p);  // Добавляем измененную перестановку в результат
            }
        }

        return res;
    }
};

// Функция для вывода всех перестановок
void printPermutations(const vector<vector<int>>& perms) {
    for (const auto& perm : perms) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    Solution solution;

    // Пример вектора чисел
    vector<int> nums = { 1, 2, 3 };

    // Генерация всех перестановок
    vector<vector<int>> result = solution.permute(nums);

    // Выводим все перестановки
    cout << "Все перестановки: " << endl;
    printPermutations(result);

    return 0;
}
