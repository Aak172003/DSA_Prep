/*
GFG Link - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
*/

// Pdf Also - ..\..\My-Prep-main\Faltu\Document\Count-Inversions.docx


class Solution{
  public:

    // arr[]: Input Array

    // N : Size of the Array arr[]

    /* Function to count inversions in the array.
       HERE PERFORM MERGESORT
     */

    long long int mergeSort(long long arr[],long long left,long long mid,long long right)

    {

       /* 
       The function first Two declares and initializes some variables: 
       n1 is the number of elements in the left half of the array (arr[left] through arr[mid])
       m1 is the number of elements in the right half of the array (arr[mid+1] through arr[right]). 
       */
        long long n1=mid-left+1;  // Return size from First Half 
        long long m1=right-mid;   // Return size from Second Half 
        
       /*  
        The arrays a and b are then created and filled with the elements of the left and right halves of arr, respectively. 
       */
        long long a[n1]; // create an array a of size n1 size 
        long long b[m1]; // create an array b of size n2 size

        // Put those first half array value in array a which because partition 
        for(long long i=0;i<n1;i++)
        {
            a[i]=arr[left+i];
        }
        
        // Put those Second half array value in array a which because partition 
        for(long long i=0;i<m1;i++)
        {
            b[i]=arr[mid+i+1];
        }
        
        long long i=0,j=0,k=left,count=0;
        // Then array a and array b me do pointer bnaenge i for a array and j for b array two merge both array into single
        
        while(i<n1 && j<m1)
        {
            if(a[i]<=b[j])
            {
                arr[k]=a[i];
                i++;
                k++;
            }
            else
            {
                arr[k]=b[j];
                j++;
                k++;
                // Left gives count
                count+=(n1-i);
    
                // When right calls Functions , so also gives Count
            }
        }
        while(i<n1)
        {
            arr[k]=a[i];
            i++;
            k++;
        }
        while(j<m1)
        {
            arr[k]=b[j];
            j++;k++;
        }
        return count;

    }
    // Here Perform Partitioning 
    long long int merging(long long arr[],long long left ,long long right)
    {
        long long int count=0;
        if(left<right)
        {
            // This is used to find middle elemenet 
            long long mid=left+(right-left)/2;
            
            // SPLITTING
            count+=merging(arr,left,mid);

            count+=merging(arr,mid+1,right);
             // APPLY MERGESORT
            count+=mergeSort(arr,left,mid,right);
        }
        return count;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        // Here 0 is starting index , N-1 is ending index 
        return merging(arr,0,N-1);
    }
};




