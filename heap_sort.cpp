//swap element
void swap (int *a, int *b)
/*------------------------------------------------------------------------------
    swap value

    Written by     : RaspiRepo
    Date           : Nov 21, 2016
 ------------------------------------------------------------------------------*/
{
    int t = *a;
    *a = *b;
    *b = t;
}


void max_heapify (int arr[], int i, int n)
/*------------------------------------------------------------------------------
    max_heapify    : build max heapify...recursive call

    Written by     : RaspiRepo
    Date           : Nov 21, 2016
 ------------------------------------------------------------------------------*/
{
    int left = (2 * i) + 1;
    int right = left + 1;
    int largest = i;

    if (left < n && arr[left] > arr[i]) {
        largest = left;
    }
    if (right < n && arr[right]> arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, largest, n);
    }
}


void heap_sort(int arr[], int n)
/*------------------------------------------------------------------------------
    heap_sort     : heap sort algorithm in place time O(nlogn)

    Written by     : RaspiRepo
    Date           : Nov 21, 2016
 ------------------------------------------------------------------------------*/
{
    //build heap
    for (int i = n/2; i >= 0; i--) {
        max_heapify(arr, i, n);
    }

    //root is max element so put max element into last element of array.
    //i.e. swap last element with root. run thru heapify from root 
    //to swapped postion which is n-1
    //next loop n-2, n-3.... until reach 0.
    for (int i = n-1; i > 0; i--) {
        swap(&arr[i], &arr[0]);
        max_heapify(arr, 0, i);
    }
}


void main () 
{
    int n = 7;
    int input_a[] = {7, 12, 1, 2, 5, 15, 4};
    heap_sort(input_a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", input_a[i]);
    }
}

