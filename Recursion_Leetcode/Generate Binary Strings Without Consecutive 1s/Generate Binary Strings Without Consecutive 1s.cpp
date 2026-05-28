#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void generateStrings(int n, string current, vector<string>& result) {
        // Base Case
        if (current.length() == n) {
            result.push_back(current);
            return;
        }
        // Decision 1: We can ALWAYS append a '0'.
        generateStrings(n, current + "0", result);

        // Decision 2: We can append a '1' ONLY IF the string is empty
        // OR the last character is a '0'.
        if (current.empty() || current.back() == '0') {
            generateStrings(n, current + "1", result);
        }
    }

public:
    vector<string> validStrings(int n) {
        vector<string> result;
        generateStrings(n, "", result);
        
        return result;
    }
};