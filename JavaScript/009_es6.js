/* With the var keyword you can overwrite variable declarations without an
   error.
*/
var camper = 'James';
var camper = 'David';
console.log(camper);
console.log();

/* When using the let keyword, a variable with the same name can only be
   declared once.
*/
let author = 'Alice';
console.log(camper);
console.log();

// let author = 'Bob';     // SyntaxError: Identifier 'author' has already
                           // been declared

/* When you declare a variable with the var keyword, it is declared globally,
   or locally if declared inside a function. */
var numArray = [];
for (var i = 0; i < 3; i++) {
    numArray.push(i);
}
console.log(numArray);
console.log(i);
console.log();

/* When you declare a variable with the let keyword inside a block, statement,
   or expression, its scope is limited to that block, statement, or expression.
*/
var numArray = [];
for (let i = 0; i < 3; i++) {
    numArray.push(i);
}
console.log(numArray);
console.log(i);     // The web browser prints the following error:
                    // Uncaught ReferenceError: i is not defined at
                    // <anonymous>:6:13
console.log();

function checkScope() {
    let i = 'function scope';

    if (true) {
        let i = 'block scope';
        console.log('Block scope i is: ', i);
    }

    console.log('Function scope i is: ', i);
    return i;
}

checkScope();
console.log();

/* const has all the awesome features that let has, with the added bonus that
   variables declared using const are read-only. They are a constant value,
   which means that once a variable is assigned with const, it cannot be
   reassigned.  A common practice when naming constants is to use all uppercase
   letters, with words separated by an underscore.
*/
const FAV_PET = "Cats";
// FAV_PET = "Dogs";   // TypeError: Assignment to constant variable.
console.log(FAV_PET);
console.log();

/* Some developers prefer to assign all their variables using const by default,
   unless they know they will need to reassign the value. Only in that case,
   they use let. However, it is important to understand that objects (including
   arrays and functions) assigned to a variable using const are still mutable.
   Using the const declaration only prevents reassignment of the variable
   identifier.
*/
const s = [5, 6, 7];
// s = [1, 2, 3];  // TypeError: Assignment to constant variable.
s[2] = 45;
console.log(s);
console.log();

/* JavaScript provides a function Object.freeze to prevent data mutation. Once
   the object is frozen, you can no longer add, update, or delete properties
   from it.
*/
const obj = {
    name:"FreeCodeCamp",
    review:"Awesome"
};
Object.freeze(obj);
obj.review = "bad";
obj.newProp = "Test";
console.log(obj);
console.log();

/* In JavaScript, we often don't need to name our functions, especially when
   passing a function as an argument to another function. Instead, we create
   inline functions. We don't need to name these functions because we do not
   reuse them anywhere else.
*/
const myFunc = function() {
    const myVar = "value";
    return myVar;
}

const foo = () => {
    const myVar = "foo";
    return myVar;
}

const date = () => new Date();

console.log(myFunc());
console.log(foo());
console.log(date());
console.log();
