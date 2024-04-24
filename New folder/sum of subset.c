#include <stdio.h>

#define MAXSIZE 100

int subset[MAXSIZE]; // array to store the current subset
int n, targetSum;
int set[MAXSIZE];

int main() {
    printf("Enter the size of the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    // Initialize sum to 0
    int sum = 0;
    
    // Loop through the elements of the set
    for (int i = 0; i < n; i++) {
        // If adding the current element doesn't exceed the target sum
        if (sum + set[i] <= targetSum) {
            // Include the current element in the subset
            subset[i] = 1;
            // Update the sum
            sum += set[i];
        } else {
            // Exclude the current element from the subset
            subset[i] = 0;
        }
    }

    // If the final sum matches the target sum, print the subset
    if (sum == targetSum) {
        printf("Subset with sum %d is: ", targetSum);
        for (int i = 0; i < n; i++) {
            if (subset[i])
                printf("%d ", set[i]);
        }
        printf("\n");
    } else {
        printf("Subset not found with sum %d\n", targetSum);
    }

    return 0;
}
