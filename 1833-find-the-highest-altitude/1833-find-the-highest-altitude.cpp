class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max = 0;
        int height = 0;  // Moved outside the loop

        for (int i = 0; i < gain.size(); i++) {
            height += gain[i];  // Keep adding gain to total height

            if (height > max) {
                max = height;
            }
        }

        return max;
    }
};
