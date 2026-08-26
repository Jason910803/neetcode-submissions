class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<string, vector<string>> anagramMap;

        // for (const string& s : strs) {
        //     string key = s;
        //     sort(key.begin(), key.end());
        //     anagramMap[key].push_back(s);
        // }

        // vector<vector<string>> result;
        // result.reserve(anagramMap.size());

        // for (const auto& [key, group] : anagramMap) {
        //     result.push_back(group);
        // }

        // return result;
        
        return another(strs);
    }

    vector<vector<string>> another(const vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        for (const string& s : strs) {
            vector<int> count(26, 0);         
            for (char c : s) {
                count[c - 'a']++;
            }

            string key;
            for (int c : count) {
                key += to_string(c);
                key+= '#';
            }

            anagramMap[key].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(anagramMap.size());

        for (const auto& [key, group] : anagramMap) {
            result.push_back(group);
        }

        return result;
    }
};
