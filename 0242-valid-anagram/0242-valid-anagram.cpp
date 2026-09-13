class Solution {
public:
    bool isAnagram(string s, string t) {
unordered_map<char, int> count;
for (char c : s) count[c]++;
for (char c : t) count[c]--;
for (auto x : count) {
    if (x.second != 0) return false;
}
return true;
    }
};