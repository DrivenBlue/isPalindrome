#ifndef __PAE2_H__
#define __PAE2_H__

#define STRING_BLANK "                "
#define STATE_START 0
#define STATE_EDIT 1
#define STATE_DISPLAY 2

#define LINE_NULL 0

#define RANDOM_SEED 2

#define DISPLAY_BUFFER_SIZE 16
#define CURSOR 94 // ascii for ^

void _zed32Swap(char *line, int length);
void _32zedSwap(char *line, int length);

int isPalindrome(char* word); 
void changeCharAtPos(char* line,int pos,int offset);
void fillLineBuffer(char* line, char c);
int moveCursor(char *line,int pos,int offset);
int delayCheck(int speed);

#endif

//[] END OF FILE
