#include <stdio.h> 
#include <stdlib.h>   

struct Day{         
    char *name;         
    int date;         
    char *activity; 
}; 

struct Day create() {     
    struct Day day;     
    day.name = (char *) malloc(20 * sizeof(char));     
    day.activity = (char *) malloc(100 * sizeof(char));          
    
    printf("Enter the day name: ");     
    scanf(" %s", day.name); // Added space to clear previous newlines
         
    printf("Enter the date: "); // Fixed prompt text
    scanf("%d", &day.date);          
         
    printf("Enter the activity for the day: : ");     
    scanf(" %[^\n]", day.activity); // Changed to allow spaces in activities
         
    return day; 
}   

void read(struct Day calender[], int size){      
    for(int i = 0; i<size;i++){          
        calender[i] = create();      
    } 
} 

void display(struct Day calender[], int size) {      
    printf("\nWeekly Activity details:\n");            
    for (int i = 0; i<size; i++){           
        printf("Day %d: %s\n", i+1, calender[i].name);           
        printf("Day %d: %d\n", i+1, calender[i].date);           
        printf("Day %d: %s\n", i+1, calender[i].activity);     
    } 
}  

int main() {     
    int weekSize = 7;     
    struct Day calender[weekSize];          
         
    read(calender, weekSize);          
    display(calender, weekSize);          
         
    for (int i = 0; i<weekSize; i++){         
        free(calender[i].name);         
        free(calender[i].activity);     
    }     
    return 0; 
}
