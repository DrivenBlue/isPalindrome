#include "pae2.h"
#include <string.h>
#include <stdlib.h>

void _zed32Swap(char* line, int length) {
    char* flip = strchr(line, '\0');
    while( flip != &line[length - 1]) {
        *flip = ' ';
        flip++;
    }
}


void _32zedSwap(char *line, int length) {
    char *flip = strchr(line, ' ');
    while( flip && flip != &line[length - 1]) {
        *flip = '\0';
        flip++;
    }
}

/*
 * Purpose: Fills the line buffer to a certain character
 *          Line buffer represents what you would eventually call displayString on
 * Inputs: line - first line
 *         c - character to fill the lines with
 * Returns: None
 * Assume: line will have exactly DISPLAY_BUFFER_SIZE+1 bytes (+1 for \0)
 * Required: The last byte in the line buffer MUST be the NULL terminator
 */
void fillLineBuffer(char* line, char c) {
	// STUDENT TODO: Fill in your solution here
    int i = 0;
    for ( i = 0; i < DISPLAY_BUFFER_SIZE; i++ ) {
        line[i] = c;
    }
    line[i] = '\0';
}

/*
 * Purpose: Checking if the word is a palindrome
 * Inputs: word - pointer to the word to check
 * Assume: the word is null-terminated
 * Return: 0 if word is palindrome, 1 otherwise
 * Examples: isPalindrome("aba") -> true
 *           isPalindrome("ab") -> false
 *			 isPalindrome("a") -> true
 */
int isPalindrome(char* word) {
	// STUDENT TODO: Fill in your solution here 
    int len = (int)strlen(word);
    int isPalin = 0;
    int bpos = len/2;
    int fpos = bpos - (len % 2 ? 0 : 1);
    
    char *front = &word[fpos]; 
    char *back = &word[bpos];
    
    if(*front != *back) {
        isPalin = 1;
    }

    while( !isPalin && front != word ) {
        front--;
        back++;
        if(*front != *back){
            isPalin = 1;
            break;
        }
    }
	return isPalin;
}

/*
 * Purpose: Move the cursor to a specified position
 * Inputs: line - the line buffer to be modified
 *		   pos - the current position of the cursor
 *		   offset - the offset from pos to move to
 * Return: the new position of the cursor
 * Note: if new position is less than 0, return 0. 
 *		 if the position is greater than or equal to DISPLAY_BUFFER_SIZE, return DISPLAY_BUFFER_SIZE-1
 */
int moveCursor(char *line,int pos,int offset){
	// STUDENT TODO: Fill in your solution here
    if( (pos + offset) < 0) { 
        pos = 0;
    } else if( (pos + offset) >= DISPLAY_BUFFER_SIZE) {
        pos = DISPLAY_BUFFER_SIZE - 1;   
    } else {
        pos += offset;
    }
    
    fillLineBuffer(line, ' ');
    line[pos] = CURSOR;
    
	return pos;
}

/*
 * Purpose: Increment or decrement a character at a given position
 * Inputs: line - a pointer to the line which contains the char
 *		   pos - the index of the character to change
 *		   offset - the amount by which to change the character
 * Required: The value of the character after changing must be between A and Z. 
 *           Incrementing and decrementing should wrap around 
 * Examples: changeCharAtPos("anna",2,1) -> "anna" should become "anoa"
 *			 changeCharAtPos("anna",2,-1) -> "anna" should become "anma"
 *           changeCharAtPos("annz",3,1) -> "annz" should become "anna" (wrap-around)
 *           changeCharAtPos("anna",0,-1) -> "anna" should become "znna" (wrap-around)
 */
void changeCharAtPos(char* line,int pos,int offset) {
	// STUDENT TODO: Fill in your solution here
    if(line[pos] + offset > 'Z')
        line[pos] = line[pos] + offset - 'Z' + 64;
    else if(line[pos] + offset < 'A')
        line[pos] = 'Z' + 1 + offset;
    else 
        line[pos] += offset;
    
}

/*
 * Purpose: Delays redrawing on the LCD screen so our animation is viewable
 * Inputs: speed - amount of delay, this value should come from the user-entered speed.
 * Returns: 0 - No delay, update the LCD display
 *          1 - Do not update the LCD display this time
 */
int delayCheck(int speed) {
	static int delayCounter = 0;
	
	delayCounter++;
	if(delayCounter >= speed) {
		delayCounter = 0;
		return 0;
	}
	return 1;
}
