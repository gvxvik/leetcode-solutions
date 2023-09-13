/**
 * @return {number}
 */
var argumentsLength = function(...args) {
 var ans = [...args];
 return ans.length;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */