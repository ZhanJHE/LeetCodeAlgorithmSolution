class Solution {
public:
    bool canTalk(const vector<int>& a, const vector<int>& b) {
        unordered_set<int> sa(a.begin(), a.end());
        for (int lang : b) {
            if (sa.count(lang)) return true;
        }
        return false;
    }

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> learners;

        // Step 1: 找出所有无法沟通的朋友对，记录涉及的用户（1-based）
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            // 转为 0-based 访问 languages
            if (!canTalk(languages[u - 1], languages[v - 1])) {
                learners.insert(u);
                learners.insert(v);
            }
        }

        // 如果没人需要学，返回 0
        if (learners.empty()) return 0;

        // Step 2: 统计这些用户已掌握的语言频次（语言编号 1~n）
        vector<int> langCount(n + 1, 0); // index 1~n 有效
        for (int user : learners) {
            for (int lang : languages[user - 1]) {
                langCount[lang]++;
            }
        }

        // Step 3: 找出最流行的语言（覆盖最多 learner）
        int maxCover = *max_element(langCount.begin() + 1, langCount.end());

        // Step 4: 需要教的人数 = 总 learner 数 - 已会该语言的人数
        return (int)learners.size() - maxCover;
    }
};
