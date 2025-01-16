/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var xorAllNums = function(nums1, nums2) {
    let xor1 = 0, xor2 = 0;

    // XOR all elements of nums1
    nums1.forEach(num => xor1 ^= num);

    // XOR all elements of nums2
    nums2.forEach(num => xor2 ^= num);

    // Check even or odd length
    const n = nums1.length, m = nums2.length;

    let result = 0;
    if (m % 2 === 1) result ^= xor1;  // If m is odd, nums1 contributes
    if (n % 2 === 1) result ^= xor2;  // If n is odd, nums2 contributes

    return result;
};
