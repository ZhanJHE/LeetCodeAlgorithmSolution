#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        // 定义元音集合（大小写）
        string vowels = "aeiouAEIOU";
        unordered_set<char> vset(vowels.begin(), vowels.end());
        
        // 提取所有元音字符
        vector<char> sorted_vowels;
        for (char c : s) {
            if (vset.count(c)) {
                sorted_vowels.push_back(c);
            }
        }
        
        // 对元音按 ASCII 排序
        sort(sorted_vowels.begin(), sorted_vowels.end());
        
        // 重新填入元音位置
        int idx = 0; // 指向 sorted_vowels 的索引
        for (int i = 0; i < s.size(); ++i) {
            if (vset.count(s[i])) {
                s[i] = sorted_vowels[idx++];
            }
        }
        
        return s;
    }
};
