class Solution {
public:

    // One encoding scheme would be to write the string length followed by a delimiter at the beginning or end of each string.
    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        
        vector<int> sizes;
        string encodedString;
        for (string& s : strs) {
            sizes.push_back(s.size());
        }
        for (int sz : sizes) {
            encodedString.append(to_string(sz));
            encodedString.push_back(',');
        }
        encodedString.push_back('#');
        for (string& s : strs) {
            encodedString.append(s);
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};

        vector<int> sizes;
        vector<string> decodedString;

        int i = 0;
        while(s[i] != '#') {
            int j = i;
            while (s[j] != ',') {
                j++;
            }
            sizes.push_back(stoi(s.substr(i, j - i)));
            i = j + 1;
        }
        i++;
        for (int sz : sizes) {
            decodedString.push_back(s.substr(i, sz));
            i += sz;
        }
        return decodedString;
    }
};
