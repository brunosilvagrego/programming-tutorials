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


/* Variables which are declared within a function, as well as the function
   parameters, have local scope. That means they are only visible within
   that function.
*/
function myLocalScope() {
    var myVar = "Hello"
    console.log("Inside myLocalScope: ", myVar);
}

myLocalScope();

// console.log("Outside myLocalScope: ", myVar); // ReferenceError: myVar is
                                                 // not defined
console.log();

/* It is possible to have both local and global variables with the same name.
   When you do this, the local variable takes precedence over the global
   variable.
*/
var outerWear = "T-Shirt";

function myOutfit() {
    var outerWear = "sweater";

    return outerWear;
}

console.log(myOutfit());
console.log();

/* A function can include the return statement but it does not have to. In the
   case that the function doesn't have a return statement, when you call it,
   the function processes the inner code but the returned value is undefined.
*/
var sum = 0;

function addSum(num) {
    sum = sum + num;
}

console.log(addSum(3));
console.log();

/* Simple queue in JavaScript */
function nextInLine(arr, item) {
    arr.push(item);
    item = arr.shift();

    return item;   
}

var testArr = [1, 2, 3, 4, 5];

console.log("Before: " + JSON.stringify(testArr));
console.log(nextInLine(testArr, 6));
console.log("After: " + JSON.stringify(testArr));
console.log();
