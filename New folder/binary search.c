// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    // printf("Try programiz.pro");
    int n ;

    printf("Enter the size of array:");
    scanf("%d",&n);
    
    int a[n];
    
    printf("\nEnter the values to be inserted into array:");
    for (int i=0;i<n;i++){
        
        printf("\ninsert at index%d:",i+1);
       scanf("%d",&a[i]); 
    }
    int key ;
    printf("\nenter the element to be searched :");
    scanf("%d",&key);
    
    int temp ;
    int j ;
    for (int i=0;i<n ;i++){
        
        
        temp=a[i];
        j=i-1;
        
        while(j>=0 && a[j]>temp){
            
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    
    
    printf("\nSorted array is:");
    for (int i=0;i<n ;i++){
        
        printf(" %d ",a[i]);
    }
    
    int left=0;
    int right=n-1;
    int mid= (left+ right) / 2 ;
    
    while (left<=right ){
        
        mid= (left+right)/2;
        
    
    if (a[mid] == key){
        
        printf("\n element %d found at index %d", key , mid);
    }
    if(a[mid]<key){
        
        left = mid+1;
    }
    else {
        right = mid-1;
    }
    }

    return 0;
}