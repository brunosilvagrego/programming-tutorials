/* In JavaScript the 'function' keyword declares a function */

function reusableFunction() {
    console.log("Hi World");
}
  
reusableFunction();     // Function call
console.log();

/* Passing Values to Functions with Arguments */
function testFun(param1, param2) {
    console.log(param1, param2);
}

testFun("Hello", "World");
console.log();

function addNumbers(param1, param2) {
    console.log(param1 + param2);
}
  
addNumbers(2, 3);
console.log();

/* In JavaScript, scope refers to the visibility of variables. Variables which
   are defined outside of a function block have Global scope. This means, they
   can be seen everywhere in your JavaScript code.
*/
var myGlobal = 10;

/* Variables which are declared without the var keyword are automatically
   created in the global scope. This can create unintended consequences
   elsewhere in your code or when running a function again. You should always
   declare your variables with var.
*/
function defineGlobal() {
    oopsGlobal = 5;
}

function testGlobals() {
    var output = "";

    if (typeof myGlobal != "undefined") {
        output += "myGlobal: " + myGlobal;
    }

    if (typeof oopsGlobal != "undefined") {
        output += "\noopsGlobal: " + oopsGlobal;
    }

    console.log(output);
}

testGlobals();
console.log();
