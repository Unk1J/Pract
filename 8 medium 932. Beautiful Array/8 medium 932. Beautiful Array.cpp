#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int partition(vector<int>& v, int start, int end, int mask) {
        int j = start;
        for (int i = start; i <= end; i++) {
            if ((v[i] & mask) != 0) { // Проверка побитовой маски
                swap(v[i], v[j]);
                j++;
            }
        }
        return j;
    }

    void sort(vector<int>& v, int start, int end, int mask) {
        if (start >= end) return;
        int mid = partition(v, start, end, mask);
        sort(v, start, mid - 1, mask << 1);
        sort(v, mid, end, mask << 1);
    }

    vector<int> beautifulArray(int N) {
        vector<int> ans;
        for (int i = 0; i < N; i++) ans.push_back(i + 1);
        sort(ans, 0, N - 1, 1); // Сортировка с использованием побитовых операций
        return ans;
    }
};

// Функция для вывода элементов вектора
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    Solution solution;

    // Примерное значение N
    int N = 4;

    // Генерация "красивого массива"
    vector<int> result = solution.beautifulArray(N);

    // Вывод результата
    cout << "Красивый массив: ";
    printVector(result);

    return 0;
}
