/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    return async function(...args) {
        return new Promise((resolve, reject) => {
            // Create a timeout that rejects the promise after t milliseconds
            const timer = setTimeout(() => {
                reject("Time Limit Exceeded");
            }, t);

            // Call the provided function and handle its resolution or rejection
            fn(...args)
                .then((result) => {
                    clearTimeout(timer); // Clear the timeout if function resolves in time
                    resolve(result);
                })
                .catch((error) => {
                    clearTimeout(timer); // Clear the timeout if function rejects in time
                    reject(error);
                });
        });
    };
};


/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */