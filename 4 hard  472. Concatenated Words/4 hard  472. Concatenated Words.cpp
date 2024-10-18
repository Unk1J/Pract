#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    map<string, int> m;

    bool cal(string& str, int idx, int cnt) {
        if (idx == str.size())
            return cnt > 1; // Строка состоит хотя бы из двух частей

        string tmp = "";
        for (int i = idx; i < str.size(); i++) {
            tmp += str[i];
            if (m.find(tmp) != m.end()) {
                // Проверяем со следующей позицией
                bool flag = cal(str, i + 1, cnt + 1);
                if (flag)
                    return true;
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (auto x : words)
            m[x]++;

        vector<string> ans;
        for (auto x : words) {
            bool flag = cal(x, 0, 0);
            if (flag)
                ans.push_back(x);
        }

        return ans;
    }
};

void printVector(const vector<string>& vec) {
    for (const string& s : vec) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    Solution solution;
    vector<string> words = { "cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat" };

    vector<string> result = solution.findAllConcatenatedWordsInADict(words);

    cout << "Составные слова: ";
    printVector(result);

    return 0;
}
