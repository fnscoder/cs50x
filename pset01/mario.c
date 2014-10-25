/*
    CS50 PSET01

    Itsa Mario
    Toward the end of World 1-1 in Nintendo’s Super Mario Brothers, Mario must ascend a
    "half-pyramid" of blocks before leaping (if he wants to maximize his score) toward a flag
    pole. Below is a screenshot.

    Super Mario Brothers

    Write, in a file called mario.c in your ~/Dropbox/pset1 directory, a program that recreates
    this half-pyramid using hashes (#) for blocks. However, to make things more interesting,
    first prompt the user for the half-pyramid’s height, a non-negative integer no greater
    than 23. (The height of the half-pyramid pictured above happens to be 8.) If the user
    fails to provide a non-negative integer no greater than 23, you should re-prompt for the
    same again. Then, generate (with the help of printf and one or more loops) the desired
    half-pyramid. Take care to align the bottom-left corner of your half-pyramid with the
    left-hand edge of your terminal window, as in the sample output below, wherein underlined
    text represents some user’s input.

    jharvard@appliance (~/Dropbox/pset1): ./mario
    Height: 8
           ##
          ###
         ####
        #####
       ######
      #######
     ########
    #########
    Note that the rightmost two columns of blocks must be of the same height. No need to
    generate the pipe, clouds, numbers, text, or Mario himself.

    By contrast, if the user fails to provide a non-negative integer no greater than 23, your
    program’s output should instead resemble the below, wherein underlined text again
    represents some user’s input. (Recall that GetInt will handle some, but not all,
    re-prompting for you.)

    Author: Felipe Nogueira de Souza Twitter: @felipen_souza
*/

//This code don't use the cs50.h library
#include <stdio.h>

int main() {

    //variables for index and height
    int i, j, k, height;

    //get the height from user
    printf("Height: ");
    scanf("%d", &height);

    //verify the integer if invalid ask for Retry
    while ((height < 1) || (height > 23)) {

        printf("Retry: ");
        scanf("%d", &height);
    }

    //this for control the total of lines
    for (i = 0; i < height; i++) {

        //this for print the white spaces in atual line
        for (j = 0; j < height - i; j++) {

            printf(" ");
        }

        //this for print the # until the end of atual line
        for (k = j; k < height + 1; k++) {

            printf("#");
        }

        //print the last # of the line and move for next line
        printf("#\n");
    }
}
