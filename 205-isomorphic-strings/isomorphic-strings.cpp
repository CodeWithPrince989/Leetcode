class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, char> mapS2T;
        unordered_map<char, char> mapT2S;
        
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            
            if (mapS2T.count(c1) && mapS2T[c1] != c2) {
                return false;
            }

            if (mapT2S.count(c2) && mapT2S[c2] != c1) {
                return false;
            }
            
            // Establish the mapping
            mapS2T[c1] = c2;
            mapT2S[c2] = c1;
        }
        
        return true;
    }
};