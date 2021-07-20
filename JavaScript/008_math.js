/* The JavaScript Math object allows you to perform mathematical tasks on
   numbers.*/

/* Math Properties */
console.log("Math Properties");
console.log(Math.E);        // returns Euler's number
console.log(Math.PI);       // returns PI
console.log(Math.SQRT2);    // returns the square root of 2
console.log(Math.SQRT1_2);  // returns the square root of 1/2
console.log(Math.LN2);      // returns the natural logarithm of 2
console.log(Math.LN10);     // returns the natural logarithm of 10
console.log(Math.LOG2E);    // returns base 2 logarithm of E
console.log(Math.LOG10E);   // returns base 10 logarithm of E
console.log();

/* Math.round() returns the nearest integer. */
console.log("Math.round()");
console.log(Math.round(4.9));
console.log(Math.round(4.7));
console.log(Math.round(4.4));
console.log(Math.round(4.2));
console.log(Math.round(-4.2));
console.log();

/* Math.ceil() returns the value of x rounded up to its nearest integer. */
console.log("Math.ceil()");
console.log(Math.ceil(4.9));
console.log(Math.ceil(4.7));
console.log(Math.ceil(4.4));
console.log(Math.ceil(4.2));
console.log(Math.ceil(-4.2));
console.log();

/* Math.floor() returns the value of x rounded down to its nearest integer. */
console.log("Math.floor()");
console.log(Math.floor(4.9));
console.log(Math.floor(4.7));
console.log(Math.floor(4.4));
console.log(Math.floor(4.2));
console.log(Math.floor(-4.2));
console.log();

/* Math.trunc() returns the integer part of x. */
console.log("Math.trunc()");
console.log(Math.trunc(4.9));
console.log(Math.trunc(4.7));
console.log(Math.trunc(4.4));
console.log(Math.trunc(4.2));
console.log(Math.trunc(-4.2));
console.log();

/* Math.sign() returns negative, null or positive. */
console.log("Math.sign()");
console.log(Math.sign(-4));
console.log(Math.sign(0));
console.log(Math.sign(4));
console.log();

/* Math.random() returns a random number between 0 (inclusive), and 1
   (exclusive) */
console.log("Math.random()");
console.log(Math.random());
console.log();

/* Generate Random Whole Numbers */
console.log("Random integer number between 0 and 9:");
console.log(Math.floor(Math.random() * 10));
console.log();

/* Generate Random Whole Numbers within a Range */
function randomRange(myMin, myMax) {
    return Math.floor(Math.random() * (myMax - myMin + 1)) + myMin;
}

console.log("Random integer number between 10 and 19:");
console.log(randomRange(10, 20));
console.log();

console.log("Random integer number between 20 and 99:");
console.log(randomRange(20, 100));
console.log();

/* The parseInt() function parses a string and returns an integer. It takes a
   second argument for the radix, which specifies the base of the number in the
   string. The radix can be an integer between 2 and 36. */
console.log("parseInt(\"007\"):", parseInt("007"));
console.log("parseInt(\"11\", 2):", parseInt("11", 2));     // Binary conversion
console.log();

/* Ternary Operator */
function findGreater(a, b) {
    return a > b ? "a is greater" : "b is greater";
}

console.log(findGreater(4, 5));
console.log(findGreater(5, 5));
console.log(findGreater(6, 5));
console.log();

function checkEqual(a, b) {
    return a == b ? "Equal" : "Not Equal";
}

console.log(checkEqual(1, 2));
console.log(checkEqual(2, 2));
console.log();

function findGreaterOrEqual(a, b) {
    return (a === b) ? "a and b are equal"
        : (a > b) ? "a is greater"
        : "b is greater";
}

console.log(findGreaterOrEqual(1, 2));
console.log(findGreaterOrEqual(2, 2));
console.log(findGreaterOrEqual(3, 2));
console.log();

function checkSign(num) {
    return (num > 0) ? "positive"
        : (num < 0) ? "negative"
        : "zero";
}

console.log(checkSign(10));
console.log(checkSign(0));
console.log(checkSign(-10));
console.log();

/* Recursion */
function countUp(n) {
    if (n < 1) {
        return [];
    } else {
        const countArray = countUp(n - 1);
        countArray.push(n);
        return countArray;
    }
}

console.log(countUp(5));
console.log();

function countDown(n){
    if (n < 1) {
        return [];
    } else {
        const countArray = countDown(n - 1);
        countArray.unshift(n);
        return countArray;
    }
}

console.log(countDown(5));
console.log();

function rangeOfNumbers(startNum, endNum) {
    if (endNum - startNum == 0) {
        return [startNum];
    } else {
        const countArray = rangeOfNumbers(startNum, endNum - 1);
        countArray.push(endNum);
        return countArray;
    }
};

console.log(rangeOfNumbers(1, 5));
console.log(rangeOfNumbers(5, 10));
console.log(rangeOfNumbers(5, 5));
console.log();
