/* With JavaScript array variables, we can store several pieces of data in
   one place.
*/

var myArray = ["Bruno", 28];

console.log(myArray);
console.log(myArray[0]);
console.log(myArray[1]);
console.log();

/* Neste arrays */
var myArray = [["Portugal", 2], ["France", 2]];
console.log(myArray[0]);
console.log(myArray[0][0]);
console.log(myArray[0][1]);
console.log(myArray[1]);
console.log(myArray[1][0]);
console.log(myArray[1][1]);
console.log();

/* Change array value */
var myArray = [18,64,99];
console.log(myArray);

myArray[1] = 45;
console.log(myArray);
console.log();

/* push() takes one or more parameters and "pushes" them onto the end of
   the array.
*/
var myArray = [["John", 23], ["cat", 2]];
console.log(myArray);

myArray.push(["dog", 3], "USA");
console.log(myArray);
console.log();

/* pop() removes the last element from an array and returns that element. */
myData = myArray.pop();
console.log(myArray);
console.log(myData);
console.log();

/* shift() removes the first element from an array and returns that element. */
myData = myArray.shift();
console.log(myArray);
console.log(myData);
console.log();

/* unshift() takes one or more parameters and "pushes" them onto the beginning
   of the array.
*/
myArray.unshift(["Paul",35]);
console.log(myArray);
console.log();
