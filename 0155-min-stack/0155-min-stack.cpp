class MinStack {
public:
    stack<int> s;
    stack<int> ss;

    MinStack() {}

    void push(int val) {
        s.push(val);
        if (ss.empty() || val <= ss.top()) {
            ss.push(val);
        }
    }

    void pop() {
        if (s.empty()) return;
        if (s.top() == ss.top()) {
            ss.pop();
        }
        s.pop();
    }

    int top() {
        if (s.empty()) return -1; // Optional safety check
        return s.top();
    }

    int getMin() {
        if (ss.empty()) return -1; // Optional: define behavior for empty stack
        return ss.top();
    }
};
