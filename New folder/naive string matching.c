# include <stdio.h>


int main(){
    char text[100];
    char pattern [100];
  
    
    printf("\nprintf entere the text : ");
    scanf("%s",text);
    
      printf("printf entere the pattern: ");
    scanf("%s",pattern);
    
    int i , j ;
     for (i = 0; text[i] != '\0'; i++) { // corrected comparison
        for (j = 0; pattern[j] != '\0'; j++) { // corrected comparison
            
            // Check if the characters match
            if (text[i + j] != pattern[j]) {
                break; // Break the inner loop if characters don't match
            }
        }
        
        // If the inner loop ended normally (i.e., pattern found completely)
        if (pattern[j] == '\0') {
            printf("Pattern found at index %d\n", i);
            break; // Break the outer loop since pattern found
        }
    }
    
    
    
    
    return 0 ; 
}