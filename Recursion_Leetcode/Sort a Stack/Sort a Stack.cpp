#include <stack>
using namespace std;

class Solution {
private:
    void sortedInsert(stack<int>& s, int element) {
        // Base Case: If stack is empty OR the element is greater than the top, push the element
        if (s.empty() || element > s.top()) {
            s.push(element);
            return;
        }

        int temp = s.top();
        s.pop();

        // Recursively insert the element into the remaining stack
        sortedInsert(s, element);
        s.push(temp);
    }

public:
    // Main Function: The Dismantler
    void sortStack(stack<int>& s) {
        // Base Case
        if (s.empty()) {
            return;
        }
        int temp = s.top();
        s.pop();
        sortStack(s);
        sortedInsert(s, temp);
    }
};