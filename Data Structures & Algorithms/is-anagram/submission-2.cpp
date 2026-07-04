class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> seen;

        // build the map first with s
        for (char &c : s) {
            seen[c]++;
        }

        // decrement by matching with t
        for (char &c : t) {
            if (!seen[c])
                return false;
            seen[c]--;
        }

        // now need to check if any seen has a value
        for (auto &it : seen ) {
            if (it.second > 0)
                return false;
        }

        return true;
    }
};
