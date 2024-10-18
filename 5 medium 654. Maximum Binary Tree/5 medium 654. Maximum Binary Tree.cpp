#include <iostream>
#include <vector>

using namespace std;

// Определение структуры TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr; // Базовый случай: если индекс начала больше конца, возвращаем nullptr

        int index = -1;
        int val = -1;

        // Находим максимальный элемент в текущем подмассиве
        for (int i = start; i <= end; i++) {
            if (nums[i] > val) {
                index = i;
                val = nums[i];
            }
        }

        TreeNode* root = new TreeNode(val); // Создаем узел с найденным максимальным значением
        // Рекурсивно строим левое и правое поддеревья
        root->left = constructMaximumBinaryTree(nums, start, index - 1);
        root->right = constructMaximumBinaryTree(nums, index + 1, end);

        return root; // Возвращаем корень
    }
};

// Функция для вывода дерева в порядке pre-order
void preOrder(TreeNode* root) {
    if (root == nullptr) return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    setlocale(LC_ALL, "ru");
    Solution solution;

    // Пример вектора чисел
    vector<int> nums = { 3, 2, 1, 6, 0, 5 };

    // Построение максимального бинарного дерева
    TreeNode* root = solution.constructMaximumBinaryTree(nums);

    // Вывод дерева в порядке pre-order
    cout << "Pre-order обход построенного дерева: ";
    preOrder(root);
    cout << endl;

    return 0;
}
