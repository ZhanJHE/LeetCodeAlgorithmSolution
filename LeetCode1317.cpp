class Solution {
    public int[] getNoZeroIntegers(int n) {
        int a = 0;
        for (int rest = n, base = 1; rest > 0; base *= 10) {
            int num = rest % 10;   // 取当前最低位数字
            rest /= 10;            // 去掉最低位，相当于右移一位

            if (num > 1) {
                a += base;         // 当前位分配 1 给 a（因为 1 ≠ 0）
            } else if (rest > 0) {
                // num == 0 或 num == 1，且还有更高位（rest > 0）
                rest--;            // 向高位借 1（相当于借位减法）
                a += 2 * base;     // 当前位分配 2 给 a（2 ≠ 0），而 b 就是 ...8（不会是 0）
            }
            // 注意：如果 num == 1 且 rest == 0（即最高位是 1），循环就结束了，a 不加任何值
        }
        return new int[]{a, n - a};
    }
}
