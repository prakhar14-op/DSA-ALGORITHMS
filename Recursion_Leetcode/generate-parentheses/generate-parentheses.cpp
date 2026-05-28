#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void generateParens(int n, int openCount, int closeCount, string current, vector<string>& result) {
        // Base Case
        // The length of the string will be exactly 2 * n.
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        // Decision 1: Can we add an open bracket '('?
        if (openCount < n) {
            generateParens(n, openCount + 1, closeCount, current + "(", result);
        }

        // Decision 2: Can we add a closed bracket ')'?
        if (closeCount < openCount) {
            generateParens(n, openCount, closeCount + 1, current + ")", result);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParens(n, 0, 0, "", result);
        
        return result;
    }
};