
//Used only for char range from 0x20 (space to ~) 0x72
#define BIT_VECTOR_LEN   (0x7F- 0x20)

int get_hash_code (char in_char) 
{
    return (in_char - 0x20);
}

bool is_unique (char *in_string) 
/*------------------------------------------------------------------------------
    is_unique      : Interview question 1.1 from Cracking the Coding
                     Interview.

                     To determine if a string has all unique characters.
                     NO additional data structures other than bit vecrtor

    Written by     : RaspiRepo
    Date           : Apr 17, 2016
------------------------------------------------------------------------------*/
{
    bool unique_char = true;
    int hashcode     = 0;

    bool bitvector [BIT_VECTOR_LEN];

    //set bitvector to not unique by default
    for (int i = 0; i < BIT_VECTOR_LEN; i++) {
        bitvector[i] = false;
    }

    while (*in_string != '\0') {

        //valid display char range, map ascii value
        //to array index from 0 to BIT_VECTOR_LEN
        if (*in_string >= 0x20 || *in_string < 0x7f) {
            hashcode = *in_string - 0x20;

            //if already char mapped then 
            //string is not unique, break the loop
            //otherwise set bitvector true (already char mapped)
            if (bitvector[hashcode] == true) {
                unique_char = false;
                break;
            }
            bitvector[hashcode] = true;
            ++in_string;
        }
    }
    return unique_char;
}


void main ()
{
    char input[] = "MJonSmith";
    printf("is unique %d\n", is_unique(input));
    getchar();
}