class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();

        // Traverse from end to start
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;  // Simple increment
                return digits;
            }
            digits[i] = 0;  // Set 9 to 0 and carry over
        }

        // If all digits were 9 (e.g., 999 + 1 = 1000)
        digits.insert(digits.begin(), 1);
        return digits;
    }
};