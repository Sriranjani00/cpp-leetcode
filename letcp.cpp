class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case: S1 is "0"
        if (n == 1) {
            return '0';
        }

        // Length of Sn is (2^n) - 1
        int length = (1 << n) - 1;
        int mid = length / 2 + 1;

        if (k == mid) {
            return '1';
        } else if (k < mid) {
            // Bit is in the left part, which is Sn-1
            return findKthBit(n - 1, k);
        } else {
            // Bit is in the right part, which is reverse(invert(Sn-1))
            // The mirrored position in Sn-1 is: length - k + 1
            char bit = findKthBit(n - 1, length - k + 1);
            // Invert the bit
            return (bit == '0') ? '1' : '0';
        }
    }
};
