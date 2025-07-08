class Solution {
public:

vector<int> nsr(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    vector<int> karan(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            karan[i] = n;
        } else {
            karan[i] = s.top();
        }
        s.push(i);
    }

    return karan;
}

vector<int> nsl(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    vector<int> karan(n);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            karan[i] = -1;
        } else {
            karan[i] = s.top();
        }
        s.push(i);
    }

    return karan;
}

vector<int> nsrMin(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    vector<int> karan(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            karan[i] = n;
        } else {
            karan[i] = s.top();
        }
        s.push(i);
    }

    return karan;
}

vector<int> nslMin(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    vector<int> karan(n);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            karan[i] = -1;
        } else {
            karan[i] = s.top();
        }
        s.push(i);
    }

    return karan;
}

long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();

    vector<int> leftMax = nsl(nums);
    vector<int> rightMax = nsr(nums);
    vector<int> leftMin = nslMin(nums);
    vector<int> rightMin = nsrMin(nums);

    long long result = 0;

    for (int i = 0; i < n; i++) {
        long long maxCount = (i - leftMax[i]) * (rightMax[i] - i);
        long long minCount = (i - leftMin[i]) * (rightMin[i] - i);
        result += (long long)nums[i] * (maxCount - minCount);
    }

    return result;
}
};
