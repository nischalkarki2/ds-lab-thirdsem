#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define Max 5
int top = -1;
char stack[Max];

void push(int item) {
    if (top >= Max-1){
        printf("Stack Overflow.");
        return;
    }
    top=top+1;
    stack[top] = item;
}

int pop(){
    if (top == -1){
        printf("Stack Underflow");
        return 0;
    }
    return stack[top--];

//     printf("stack Elementsare:\n");


}

void disp(){
    int i;

    if(top==-1){
        printf("Stack Empty");
        return;
        // printf("|%d|", stack[i]);
    }
    printf("stack Elements are:\n");
    for(int i =top; i>=0;i--){
        printf("|%d| ", stack[i]);
    }
    printf("\n");
}

void palin(){
    int i; 
    char p[100];
    top = -1;
    printf("Enter a number to check for palindrome: ");
    scanf("%s", p);
    
    for (i =0; i<strlen(p);i++){
        push((p[i]-'0'));
    }

    for (i = 0; i<strlen(p)/2; i++){
        if ((p[i]-'0' != pop())){
            printf("The number is not palindrome\n");
            return;
        }
    }
    printf("The number is palindrome\n");
}

int main(){
    int ch, k, item;

    while(1){
        printf("\n-----MAIN MENU-----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Palindrome\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: printf("Enter an item to push: ");
            scanf("%d", &item);
            push(item);
            break;
        
        case 2: k = pop(); if(k){printf("Popped element is %d\n", k);} break;

        case 3: disp(); break;

        case 4: palin(); break;

        case 5: printf("Exited"); exit(0);

        default: printf("Invalid choice\n"); break;
        }
    }
    return 0;
}