#include <stdint.h>
#include <stdio.h>

/*
 * An array 'x' contains 'n' non-negative integers.
 * Write a function that determines if you can add together any
 * 'k' of the elements in 'x' and get precisely 'v'.
 */
bool sumsTo(uint32_t x[], uint32_t n, uint32_t k, uint32_t v) {
    // add 0 of the elements to get sum 0
    if (v == 0 && k == 0) { return true; }
    // 'x' has only non-negative integers, sum will never be 0
    if (v != 0 && k == 0) { return false; }
    // empty array
    if (n == 0) { return false; }

    int result_1 = 0;
    if (v >= x[0]) {
        // first item in array included in sum
        result_1 = sumsTo(x + 1, n - 1, k - 1, v - x[0]);
    }
    // first number in the excluded from sum
    int result_2 = sumsTo(x + 1, n - 1, k, v);
    return result_1 + result_2 > 0;
}

//int main() {
//    uint32_t test[5] = {1, 2, 3, 4, 5};
//    printf("%d", sumsTo(test, 5, 4, 10));
//    return 0;
//}
