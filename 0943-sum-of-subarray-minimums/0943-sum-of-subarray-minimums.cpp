class Solution {
public:

vector<int> nsr(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    vector<int> karan(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        karan[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    return karan;
}

vector<int> nsl(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    vector<int> karan(n);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            s.pop();
        }
        karan[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    return karan;
}

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    int mod = 1e9 + 7;

    vector<int> left = nsl(arr);
    vector<int> right = nsr(arr);

    long long result = 0;

    for (int i = 0; i < n; i++) {
        long long l = i - left[i];
        long long r = right[i] - i;
        result = (result + arr[i] * l * r) % mod;
    }

    return (int)result;
}
};
