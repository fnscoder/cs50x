/*
    CS50 PSET01 - Hacker Edition

    Itsa Mario Hacker Edition
    Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over
    two "half-pyramids" of blocks as he heads toward a flag pole. Below is a screenshot.

    Super Mario Brothers

    Write, in a file called mario.c in your ~/Dropbox/hacker1 directory, a program that
    recreates these half-pyramids using hashes (#) for blocks. However, to make things more
    interesting, first prompt the user for the half-pyramids' heights, a non-negative integer
    no greater than 23. (The height of the half-pyramids pictured above happens to be 4, the
    width of each half-pyramid 4, with an a gap of size 2 separating them.) Then, generate
    (with the help of printf and one or more loops) the desired half-pyramids. Take care to
    left-align the bottom-left corner of the left-hand half-pyramid, as in the sample output
    below, wherein boldfaced text represents some user’s input.

    jharvard@appliance (~/Dropbox/hacker1): ./mario
    Height: 4
       #  #
      ##  ##
     ###  ###
    ####  ####
    No need to generate the bricks, cloud, numbers, or text in the sky or Mario himself. Just
    the half-pyramids! And be sure that main returns 0.

    Author: Felipe Nogueira de Souza Twitter: @felipen_souza
*/

//This code don't use the cs50.h library
#include <stdio.h>

int main() {

    //variables for index and height
    int i, j, k, l, height;

    //get the height from user
    printf("Height: ");
    scanf("%d", &height);

    //validation of Height
    while ((height < 1) || (height > 23)) {

        printf("Retry: ");
        scanf("%d", &height);
    }

    //this for control the lines
    for (i = 0; i < height; i++) {

        //this for print the white spaces in atual line
        for (j = 0; j < height - i; j++) {

            printf(" ");
        }

        //this for print the # until the half of atual line
        for (k = j; k < height + 1; k++) {

            printf("#");
        }

        //print two spaces for separate pyramids
        printf("  ");

        //this for print the lasts #
        for (l = 0; l < k - j; l++) {

            printf("#");
        }

        //move for next line
        printf("\n");
    }

    return 0;
}
