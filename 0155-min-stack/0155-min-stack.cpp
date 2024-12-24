#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> s;  // Main stack to store all elements
    stack<int> ss; // Auxiliary stack to store minimum elements

    MinStack() { }

    void push(int val) {
        s.push(val); // Always push to the main stack
        // Push to the auxiliary stack if it's empty or `val` is less than or equal to the current minimum
        if (ss.empty() || val <= ss.top()) {
            ss.push(val);
        }
    }

    void pop() {
        if (s.empty()) return; // If main stack is empty, do nothing
        if (s.top() == ss.top()) {
            ss.pop(); // Pop from auxiliary stack if the top matches
        }
        s.pop(); // Always pop from the main stack
    }

    int top() {
        if (s.empty()) return -1; // Return -1 if stack is empty
        return s.top(); // Return the top element of the main stack
    }

    int getMin() {
        if (ss.empty()) return -1; // Return -1 if no minimum exists
        return ss.top(); // Return the top element of the auxiliary stack
    }
};