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

/* Equality Operator - It converts data types. */
console.log("Equality Operator");
console.log(1 == 1);
console.log(1 == 2);
console.log(1 == '1');
console.log("3" == 3);
console.log();

/* Strict Equality Operator - It does not convert data types. */
console.log("Strict Equality Operator");
console.log(1 === 1);
console.log(1 === 2);
console.log(1 === '1');
console.log("3" === 3);
console.log();

/* Inequality Operator - It converts data types. */
console.log("Inequality Operator");
console.log(1 != 2);
console.log(1 != "1");
console.log(1 != '1');
console.log(1 != true);
console.log(0 != false);
console.log();

/* Strict Inequality Operator - It does not convert data types. */
console.log("Strict Inequality Operator");
console.log(3 !== 3);
console.log(3 !== '3');
console.log(4 !== 3);
console.log();

/* Greater Than Operator - It converts data types. */
console.log("Greater Than Operator");
console.log(5 > 3);
console.log(7 > '3');
console.log(2 > 3);
console.log('1' > 9);
console.log();

/* Greater Than Or Equal To Operator - It converts data types. */
console.log("Greater Than Or Equal To Operator");
console.log(6 >= 6);
console.log(7 >= '3');
console.log(2 >= 3);
console.log('7' >= 9);
console.log();

/* Less Than Operator - It converts data types. */
console.log("Less Than Operator");
console.log(2 < 5);
console.log('3' < 7);
console.log(5 < 5);
console.log(3 < 2);
console.log('8' < 4);
console.log();

/* Less Than Or Equal To Operator - It converts data types. */
console.log("Less Than Or Equal To Operator");
console.log(4 <= 5);
console.log('7' <= 7);
console.log(5 <= 5);
console.log(3 <= 2);
console.log('8' <= 4);
console.log();

/* Logical And Operator */
console.log("Logical And Operator");

function testLogicalAnd(num) {
    if (num > 5 && num < 10) {
        return "Yes";
    }

    return "No";
}

console.log(testLogicalAnd(7));
console.log(testLogicalAnd(12));
console.log();

/* Logical Or Operator */
console.log("Logical Or Operator");

function testLogicalOr(num) {
    if (num < 5 || num > 10) {
        return "Yes";
    }

    return "No";
}

console.log(testLogicalOr(3));
console.log(testLogicalOr(7));
console.log(testLogicalOr(12));
console.log();

/* Else Statement */
console.log("Else Statement");

function testLogicalElse(num) {
    if (num > 10) {
        return "Bigger than 10";
    } else {
        return "10 or Less";
    }
}

console.log(testLogicalElse(12));
console.log(testLogicalElse(10));
console.log(testLogicalElse(7));
console.log();

/* Else If Statement */
console.log("Else If Statement");

function testLogicalElseIf(num) {
    if (num > 15) {
        return "Bigger than 15";
    } else if (num < 5) {
        return "Smaller than 5";
    } else {
        return "Between 5 and 15";
    }
}

console.log(testLogicalElseIf(20));
console.log(testLogicalElseIf(10));
console.log(testLogicalElseIf(2));
console.log();

/* Switch Statement - Statements are executed from the first matched case value
   until a break is encountered. Case values are tested with strict equality
   (===). The break tells JavaScript to stop executing statements. If the break
   is omitted, the next statement will be executed.*/
console.log("Switch Statement");

function caseInSwitch(val) {
    var answer = "";

    switch(val) {
        case 1:
            answer = "alpha";
            break;
        case 2:
            answer = "beta";
            break;
        case 3:
            answer = "gamma";
            break;
        case 4:
            answer = "delta";
            break;
        default:
            answer = "unknown";
            break;
    }

    return answer;
}

console.log(caseInSwitch(1));
console.log(caseInSwitch(2));
console.log(caseInSwitch(3));
console.log(caseInSwitch(4));
console.log(caseInSwitch(10));
console.log();
