
  
  #include <stdio.h>
  #include<time.h>
  
  clock_t start,end;
  double cpu_time_used;
  
  void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
  }
  
  void heapify(int array[], int n, int i) {
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && array[left] > array[largest])
      largest = left;
  
    if (right < n && array[right] > array[largest])
      largest = right;
  
    // Swap and  heapify if root is not largest
    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, n, largest);
    }
  }
  
  
  void heapSort(int array[], int n) {
    // create max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(array, n, i);
  
    // after max heap,  sort heap 
    for (int i = n - 1; i >= 0; i--) {
      swap(&array[0], &array[i]);
  
      // Heapify root element to get highest element at root again
      heapify(array, i, 0);
    }
  }
  
  
  void print(int array[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", array[i]);
    printf("\n");
  }
  
  
  int main() {
      int n;
      printf("\n Enter the number of elements :> ");
      scanf("%d",&n);
      int array[n];
      
      printf("\n\t Insert the elements: \n");
      for(int i=0;i<n;i++)
        scanf("%d",&array[i]);
        
    printf("\n Displaying entered array: \n ");
    print(array,n);
    
    start=clock();
    heapSort(array, n);// function call to sort array
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("\n  Sorted array :> ");
    print(array, n);
    printf("\n It took %f sec to sort an array using Heap sort\n\n time complexity = >[ O(n*logn) ]",cpu_time_used);
  }