class Solution {
public:
    int reverse(int x) {
        long long ans = 0; // Using a 64-bit integer container
        while (x != 0) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        // If the 64-bit result doesn't fit in a 32-bit bounds, return 0
        if (ans > INT_MAX || ans < INT_MIN) return 0;
        return (int)ans;
    }
};
 