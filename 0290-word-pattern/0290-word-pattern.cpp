class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, std::string> charToWordMap;
        istringstream ss(s);
        string word;
        int i = 0;
        
        while (ss >> word) {
            if (i >= pattern.length())
                return false;
            
            char c = pattern[i];
            if (charToWordMap.find(c) != charToWordMap.end()) {
                if (charToWordMap[c] != word)
                    return false;
            } else {
                for (auto& entry : charToWordMap) {
                    if (entry.second == word)
                        return false;
                }
                charToWordMap[c] = word;
            }
            i++;
        }
        return i == pattern.length();
    }
};
