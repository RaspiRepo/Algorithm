
void printKMax(int arr[], int n, int k)
/*------------------------------------------------------------------------------
 Given a set of arrays of size N and an integer K, you have to
 find the maximum integer for each and every contiguous subarray
 of size  for each of the given arrays.
 
 Written by     : RaspiRepo
 Date           : june 20, 2016
 ------------------------------------------------------------------------------*/
{
    int lw = 0; //slide window left position (start)
    int rw = k; //slide window right postion (end of current slice window)
    
    int max_val_index = 0;
    int max = arr[0]; //first element as max
    
    //find max in first slice window
    for (int i = 1; i < k; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_val_index = i;
        }
    }
    
    //print or store max value of current slide window
    //cout << max << " ";
    
    //move to next window start postion by 1
    ++lw;
    
    //check each new element is max than previous max (n - k)
    for (int i = k; i < n; i++) {
        
        //current max value index is with in current slide window (left - right)?
        //if yes then some of the elements already compared so skip those
        if (max_val_index >= lw) {
            
            //last element of current window is a max then that's max for this slide range
            if (arr[i] > max) {
                max = arr[i];
                max_val_index = i;
            }
            //update slide left and right end
            ++lw;
            ++rw;
            
            //current max element is previous slide window range then
            //find new max for current window range (left - right)
        } else {
            max = arr[lw];
            max_val_index = lw;
            
            ++lw;
            ++rw;
            for (int x = lw; x < rw; x++) {
                if (arr[x] > max) {
                    max = arr[x];
                    max_val_index = x;
                }
            }
        }
        
        //print or store max value of current slide window
        //cout << max << " ";
    }
}

#define MAX_ARR_SIZE    10
int main ()
{
    
    int window_size = 3;
    
    int arr_sz = MAX_ARR_SIZE;
    int myints[MAX_ARR_SIZE];
    
    //fill random number
    for (int x = 0; x < arr_sz; x++) {
        myints[x] = rand() % 10;
    }
    printKMax(myints, arr_sz, window_size);
}
