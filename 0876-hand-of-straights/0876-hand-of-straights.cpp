class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        priority_queue<int, vector<int>, greater<int>> karan;
        unordered_map<int, int> freq;

        for (int i = 0; i < hand.size(); i++) {
            freq[hand[i]]++;
            karan.push(hand[i]);
        }

        while (!karan.empty()) {
            int start = karan.top();
            karan.pop();

            if (freq[start] == 0) continue;

            for (int i = 0; i < groupSize; i++) {
                int card = start + i;
                if (freq[card] == 0) return false;
                freq[card]--;
            }
        }

        return true;
    }
};
