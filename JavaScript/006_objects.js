/* Objects are useful for storing data in a structured way, and can represent
   real world objects. */

var cat = {
    "name": "Whiskers",
    "legs": 4,
    "tails": 1,
    "enemies": ["Water", "Dogs"]
};

console.log(cat.name);
console.log(cat.legs);
console.log(cat.tails);
console.log(cat.enemies);
console.log();

/* If your object has any non-string properties, JavaScript will automatically
   typecast them as strings. */
var anotherObject = {
    make: "Ford",
    5: "five",
    "model": "focus"
};

console.log(anotherObject.make);
console.log(anotherObject[5]);
console.log(anotherObject.model);
console.log();

/* Bracket Notation */
var myObj = {
    "Space Name": "Kirk",
    "More Space": "Spock",
    "NoSpace": "USS Enterprise"
};

console.log(myObj["Space Name"]);
console.log(myObj['More Space']);
console.log(myObj["NoSpace"]);
console.log();

/* Updating Object Properties */
myObj["Space Name"] = "Neo";
myObj.NoSpace = "NASA";
console.log(myObj);
console.log();

/* Add New Properties */
myObj.species = "Human";
myObj["age"] = 277;
console.log(myObj);
console.log();

/* Delete a Property */
delete myObj["More Space"];
console.log(myObj);
console.log();

/* Using Objects for Lookups */
var lookup = {
    1: "A",
    2: "B",
    3: "C",
    4: "D",
    5: "E"
};

console.log(lookup[1]);
console.log(lookup[2]);
console.log(lookup[3]);
console.log(lookup[4]);
console.log(lookup[5]);
console.log();

/* Testing Objects for Properties */
console.log(lookup.hasOwnProperty(1));
console.log(lookup.hasOwnProperty(6));
console.log();

var myObj = {
    top: "hat",
    bottom: "pants"
};

console.log(myObj.hasOwnProperty("top"));
console.log(myObj.hasOwnProperty("middle"));
console.log();

/* Accessing Nested Objects */
var ourStorage = {
    "desk": {
      "drawer": "stapler"
    },
    "cabinet": {
      "top drawer": { 
        "folder1": "a file",
        "folder2": "secrets"
      },
      "bottom drawer": "soda"
    }
};

console.log(ourStorage.cabinet["top drawer"].folder2);
console.log(ourStorage.desk.drawer);
console.log();

/* Accessing Nested Arrays */
var ourPets = [
    {
        animalType: "cat",
        names: [
            "Meowzer",
            "Fluffy",
            "Kit-Cat"
      ]
    },
    {
        animalType: "dog",
        names: [
            "Spot",
            "Bowser",
            "Frankie"
      ]
    }
];

console.log(ourPets[0].names[1]);
console.log(ourPets[1].names[0]);
console.log();
