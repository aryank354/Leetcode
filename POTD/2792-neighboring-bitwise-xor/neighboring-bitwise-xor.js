/**
 * @param {number[]} derived
 * @return {boolean}
 */
var doesValidArrayExist = function(derived) {
    let n = derived.length;
    let xorSum = 0;

    for (let num of derived) {
        xorSum ^= num;
    }

    return xorSum === 0;
};
