/*
    CS50 PSET01 - Hacker Edition

    Bad Credit
    Odds are you have a credit card in your wallet. Though perhaps the bill does not (yet) get
    sent to you! That card has a number, both printed on its face and embedded (perhaps with
    some other data) in the magnetic stripe on back. That number is also stored in a database
    somewhere, so that when your card is used to buy something, the creditor knows whom to bill.
    There are a lot of people with credit cards in this world, so those numbers are pretty
    long: American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa
    uses 13- and 16-digit numbers. And those are decimal numbers (0 through 9), not binary,
    which means, for instance, that American Express could print
    as many as 10^(15) = 1,000,000,000,000,000 unique cards! (That’s, ahem, a quadrillion.)

    Now that’s a bit of an exaggeration, because credit card numbers actually have some
    structure to them. American Express numbers all start with 34 or 37; MasterCard numbers all
    start with 51, 52, 53, 54, or 55; and Visa numbers all start with 4. But credit card
    numbers also have a "checksum" built into them, a mathematical relationship between at
    least one number and others. That checksum enables computers (or humans who like math) to
    detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a
    database, which can be slow. (Consider the awkward silence you may have experienced at some
    point whilst paying by credit card at a store whose computer uses a dial-up modem to verify
    your card.) Of course, a dishonest mathematician could certainly craft a fake number that
    nonetheless respects the mathematical constraint, so a database lookup is still necessary
    for more rigorous checks.

    So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter
    Luhn, a nice fellow from IBM. According to Luhn’s algorithm, you can determine if a credit
    card number is (syntactically) valid as follows:

    Multiply every other digit by 2, starting with the number's second-to-last digit, and then
    add those products' digits together.
    Add the sum to the sum of the digits that weren't multiplied by 2.
    If the total's last digit is 0 (or, put more formally, if the total modulo 10 is congruent
    to 0), the number is valid!
    That's kind of confusing, so let's try an example with Nate's AmEx: 378282246310005.
    For the sake of discussion, let's first underline every other digit, starting with the
    number's second-to-last digit:

    378282246310005

    Okay, let's multiply each of the underlined digits by 2:

    7•2 + 2•2 + 2•2 + 4•2 + 3•2 + 0•2 + 0•2

    That gives us:

    14 + 4 + 4 + 8 + 6 + 0 + 0

    Now let's add those products' digits (i.e., not the products themselves) together:

    1 + 4 + 4 + 4 + 8 + 6 + 0 + 0 = 27

    Now let's add that sum (27) to the sum of the digits that weren't multiplied by 2:

    27 + 3 + 8 + 8 + 2 + 6 + 1 + 0 + 5 = 60

    Yup, the last digit in that sum (60) is a 0, so Nate's card is legit!

    So, validating credit card numbers isn’t hard, but it does get a bit tedious by hand. Let’s
    write a program.

    In credit.c, write a program that prompts the user for a credit card number and then
    reports (via printf) whether it is a valid American Express, MasterCard, or Visa card
    number, per the definitions of each’s format herein. So that we can automate some tests of
    your code, we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or
    VISA\n or INVALID\n, nothing more, nothing less, and that main always return 0.
    For simplicity, you may assume that the user’s input will be entirely numeric
    (i.e., devoid of hyphens, as might be printed on an actual card). But do not assume that
    the user’s input will fit in an int! Best to use GetLongLong from CS50’s library to get
    users' input. (Why?)

    Of course, to use GetLongLong, you’ll need to tell clang about CS50’s library. Be sure to
    put

    #include <cs50.h>
    toward the top of credit.c. And be sure to compile your code with a command like the below.

    clang -o credit credit.c -lcs50
    Note that -lcs50 must come at this command’s end because of how clang works.

    Incidentally, recall that make can invoke clang for you and provide that flag for you, as
    via the command below.

    make credit
    Assuming your program compiled without errors (or, ideally, warnings) via either command,
    you can run your program with the command below.

    ./credit
    Consider the below representative of how your own program should behave when passed a
    valid credit card number (sans hyphens); highlighted in bold is some user’s input.

    jharvard@appliance (~/Dropbox/hacker1): ./credit
    Number: 378282246310005
    AMEX
    Of course, GetLongLong itself will reject hyphens (and more) anyway:

    jharvard@appliance (~/Dropbox/hacker1): ./credit
    Number: 3782-822-463-10005
    Retry: foo
    Retry: 378282246310005
    AMEX
    But it’s up to you to catch inputs that are not credit card numbers (e.g., Lauren’s phone
    number), even if numeric:

    jharvard@appliance (~/Dropbox/hacker1): ./credit
    Number: 7722574501
    INVALID
    Test out your program with a whole bunch of inputs, both valid and invalid. (We certainly
    will!) Here are a few card numbers that PayPal recommends for testing:

    https://www.paypalobjects.com/en_US/vhelp/paypalmanager_help/credit_card_numbers.htm

    Google (or perhaps a roommate’s wallet) should turn up more. (If your roommate asks what
    you’re doing, don’t mention us.) If your program behaves incorrectly on some inputs (or
    doesn’t compile at all), time to debug!

    Author: Felipe Nogueira de Souza Twitter: @felipen_souza
*/

//This implementation don't use cs50.h library
#include <stdio.h>

int main() {

    //lon long for receive the card number
    long long card;
    int cardNumber[16];                 //array for separated numbers
    int i, j, type, sum, mul, temp;     //index and operations
    sum = 0;

    //ask for a card number
    printf("Give me the card number\n");
    scanf("%lld", &card);

    //separate the numbers
    for (i = 15; i >= 0; i--) {

        cardNumber[i] = card % 10;
        card = card / 10;
    }

    //find the first valid number in array
    i = 0;

    while (cardNumber[i] < 1) {

        i++;
    }

    //verify if the digits is ok
    if ((i == 3) || (i == 1) || (i == 0)) {

        //realize operations for verify is is a valid number
        for (j = i+1; j < 16; j = j + 2) {

            mul = cardNumber[j] * 2;

            if (mul < 10) {

                sum += mul;
            }
            else {

                temp = mul % 10;
                mul = mul / 10;
                sum += temp;
                sum += mul;
            }
        }

        for (j = i; j < 16; j = j + 2) {

            sum += cardNumber[j];
        }

        //verify if is valid number
        if (sum % 10 == 0) {

            //if was valid verify the initial numbers for find cia of card
            if ((i == 1) && (cardNumber[i] == 3) && ((cardNumber[i+1] == 4) || cardNumber[i+1] == 7)) {

                type = 1; //AMEX
            }
            else if ((i == 0) && (cardNumber[i] == 5) && (cardNumber[i+1] < 0) && (cardNumber[i+1] < 6)) {

                type = 2; //MASTERCARD
            }
            else if (((i == 0) || (i == 3)) && cardNumber[i] == 4) {

                type = 3; //VISA
            }
            else {

                //valid digits but initial numbers not ok
                type = 4; //INVALID
            }
        }
        else {

            //invalid sum
            type = 4; //INVALID
        }
    }
    else {

        //invalid digits
        type = 4;
    }

    //verify the variable type, for print the type of the card
    switch (type) {

        case 1:

            printf("AMEX\n");
            break;

        case 2:

            printf("MASTERCARD\n");
            break;

        case 3:

            printf("VISA\n");
            break;

        case 4:

            printf("INVALID\n");
    }

    return 0;
}
