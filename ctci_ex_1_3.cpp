#include <stdio.h>
#include <string.h>
#include <conio.h>


int urlify (char *in_str,
            int   str_len)
/*------------------------------------------------------------------------------
    urlify         : Interview question 1.3 from Cracking the Coding
                     Interview.

                     Method to replace all space into %20 in the string. 
                     Assumed that input string has sufficient space 
                     to hold additional chars. Preferebly in place

    Written by     : RaspiRepo
    Date           : Apr 17, 2016
------------------------------------------------------------------------------*/
{
    int retval    = 1;

    //move the pointer to end of the string 
    //to copy from right to left
    char *end_ptr = (in_str + str_len -1);
    char *out_ptr = end_ptr;

    if (str_len > 0) {

        //find first letter from end postion. 
        //this will remove traling space as well
        while(--str_len > 0 && *end_ptr == 0x20) {
            --end_ptr;
        }
        
        //loop thru all chars to copy, also make sure
        //memory over/underflow error by checking
        //out pointer should not go less then start postion
        while(--str_len > 0 && !(out_ptr < in_str)) {
            if (*end_ptr != 0x20) {
                *out_ptr-- = *end_ptr;
            } else {
                *out_ptr-- = '0';
                *out_ptr-- = '2';
                *out_ptr-- = '%';
            }
            --end_ptr;
        }

        //check error if any char missed to copy
        retval = 0;
        if (out_ptr != in_str) {
            retval = 1;
        }
    }
    return retval;
}


void main ()
{
    char input[] = "Mr Jhon Smith    ";
    urlify(input, strlen(input));
    printf("%s\n", input);
    getchar();
}
