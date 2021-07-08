/* If statements are used to make decisions in code. The keyword if tells
   JavaScript to execute the code in the curly braces under certain conditions,
   defined in the parentheses. These conditions are known as Boolean conditions
   and they may only be true or false.
*/
function test (myCondition) {
    if (myCondition) {
        return "It was true";
    }

    return "It was false";
}

console.log(test(true));
console.log(test(false));
console.log();

/* Equality Operator */
function testEqual(val) {
    if (val == 12) {
        return "Equal";
    }

    return "Not Equal";
}
  
console.log(testEqual(10));
console.log();

/* Type Coercion */
console.log(1 == 1);
console.log(1 == 2);
console.log(1 == '1');
console.log("3" == 3);
console.log();

/* Strict Equality Operator - It does not perform a type conversion.*/
console.log(1 === 1);
console.log(1 === 2);
console.log(1 === '1');
console.log("3" === 3);
console.log();
