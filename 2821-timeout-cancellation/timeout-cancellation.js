/**
 * @param {Function} fn - Function to be executed
 * @param {Array} args - Arguments to be passed to fn
 * @param {number} t - Delay time in milliseconds
 * @return {Function} - A cancel function to stop fn from executing
 */
var cancellable = function(fn, args, t) {
    // Schedule the function to run after t milliseconds
    const timerId = setTimeout(() => {
        fn.apply(null, args); // Use apply to pass array elements as individual args
    }, t);

    // Return a function that cancels the scheduled execution
    return function cancelFn() {
        clearTimeout(timerId); // Cancels the timeout before fn is executed
    };
};