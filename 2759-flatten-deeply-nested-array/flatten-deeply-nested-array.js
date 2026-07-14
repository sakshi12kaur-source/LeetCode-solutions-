/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (source, level) {
    const result = [];
    const toFlat = (arr, n) => {
        for (let i = 0; i < arr.length; i++) {
            if (Array.isArray(arr[i]) && n > 0) {
                toFlat(arr[i], n - 1);
            } else {
                result.push(arr[i]);
            }
        }
    };
    toFlat(source, level);
    return result;
};