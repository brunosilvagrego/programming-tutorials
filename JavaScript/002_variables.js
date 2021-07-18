/* JavaScript provides eight different data types which are undefined, null,
   boolean, string, symbol, bigint, number, and object.
*/

var undef;
var empty = null;
var str = "12";
var num = 12;
var bool = true;

console.log(undef);
console.log(empty);
console.log(str);
console.log(num);
console.log(bool);
console.log();

/* Uninitialized Variables */
var a;
var b;
var c;

a = a + 1;
b = b + 5;
c = c + " String!";

console.log(a);
console.log(b);
console.log(c);
console.log();

/* Initialized Variables */
var a = 5;
var b = 10;
var c = "I am a";

a = a + 1;
b = b + 5;
c = c + " String!";

console.log(a);
console.log(b);
console.log(c);
console.log();

/* Best Practice: Write variable names in JavaScript in camelCase. In camelCase,
   multi-word variable names have the first word in lowercase and the first
   letter of each subsequent word is capitalized.
*/

/* Variables declaration */
var studlyCapVar;
var properCamelCase;
var titleCaseOver;

/* Variables assignment */
studlyCapVar = 10;
properCamelCase = "A String";
titleCaseOver = 9000;

/* In JavaScript, String values are immutable, which means that they cannot be
   altered once created. */
var myStr = "Bob";
console.log(myStr);

myStr[0] = "J";     // Does not change the value of the string first character
console.log(myStr);
console.log();
