/* While Loop */
var myArray = [];
var i = 0;

while(i < 5) {
    myArray.push(i);
    i++;
}

console.log(myArray);
console.log();

/* For Loop */
myArray = [];

for (var i = 0; i < 5; i++) {
    myArray.push(i);
}

console.log(myArray);
console.log();

/* Iterate Through an Array with a For Loop */
var arr = [10, 9, 8, 7, 6];

for (var i = 0; i < arr.length; i++) {
    console.log(arr[i]);
}

console.log();

/* Nesting For Loops */
var arr = [ [1,2], [3,4], [5,6] ];

for (var i = 0; i < arr.length; i++) {
    for (var j = 0; j < arr[i].length; j++) {
        console.log(arr[i][j]);
    }
}

console.log();

function multiplyAll(arr) {
    var product = 1;

    for (var i = 0; i < arr.length; i++) {
        for (var j = 0; j < arr[i].length; j++) {
            product *= arr[i][j];
        }
    }

    return product;
}
  
console.log(multiplyAll([[1,2],[3,4],[5,6,7]]));
console.log();

/* Do ... While Loops */
myArray = [];
var i = 0;

do {
    myArray.push(i);
    i++;
} while (i < 5);

console.log(myArray);
console.log();

/* Replace Loops using Recursion */
function multiply(arr, n) {
    if (n <= 0) {
        return 1;
    } else {
        return multiply(arr, n - 1) * arr[n - 1];
    }
}

function sum(arr, n) {
    if (n <= 0) {
        return 0;
    } else {
        return sum(arr, n - 1) + arr[n - 1];
    }
}

myArray = [1, 2, 3, 4, 5];
console.log(myArray);
console.log(multiply(myArray, 5));
console.log(sum(myArray, 5));
console.log();

/* Lookup Profile */
var contacts = [
    {
        "firstName": "Akira",
        "lastName": "Laine",
        "number": "0543236543",
        "likes": ["Pizza", "Coding", "Brownie Points"]
    },
    {
        "firstName": "Harry",
        "lastName": "Potter",
        "number": "0994372684",
        "likes": ["Hogwarts", "Magic", "Hagrid"]
    },
    {
        "firstName": "Sherlock",
        "lastName": "Holmes",
        "number": "0487345643",
        "likes": ["Intriguing Cases", "Violin"]
    },
    {
        "firstName": "Kristian",
        "lastName": "Vos",
        "number": "unknown",
        "likes": ["JavaScript", "Gaming", "Foxes"]
    }
];

function lookUpProfile(name, prop) {
    var result = "No such contact";
    var found = false;
    var i = 0;

    while (found == false && i < contacts.length) {
        if (contacts[i].firstName == name) {
            if (contacts[i].hasOwnProperty(prop)) {
                result = contacts[i][prop];
            } else {
                result = "No such property";
            }
        }
    
        i++;
    }

    return result;
}

console.log(lookUpProfile("Akira", "likes"));
console.log(lookUpProfile("Akira", "address"));
console.log(lookUpProfile("Sherlock", "likes"));
console.log(lookUpProfile("Harry", "likes"));
console.log(lookUpProfile("Bob", "number"));
console.log(lookUpProfile("Bob", "potato"));
console.log(lookUpProfile("Kristian", "lastName"));
console.log();
