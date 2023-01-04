#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    int s0, s1, s2, input;
    s0 = 0;
    s1 = 0;
    s2 = 0;
    int next_s0, next_s1, next_s2;
    

    while(true){
        printf("\n\nCircular City Train Station - Finite State Automata\n----------------------\n");

        if (s0 == 0 && s1 == 0){
            printf("11");
            printf(" - - ");
            printf("\033[1;32m"); // Green
            printf("10");
            printf("\033[0;37m"); // White
            printf("\n|      |\n");
            printf("\033[1;33m"); // Yellow
            printf("Y");
            printf("\033[0;37m"); // White
            printf(" - - ");
            printf("01");
            printf("\033[0;37m"); // White
            printf("\nYou are currently at Station 00");
        }
        
        else if (s0 == 0 && s1 == 1){
            printf("11");
            printf(" - - ");
            printf("\033[1;32m"); // Green
            printf("10");
            printf("\033[0;37m"); // White
            printf("\n|      |\n");
            printf("00");
            printf(" - - ");
            printf("\033[1;33m"); // Yellow
            printf("Y");
            printf("\033[0;37m"); // White
            printf("\nYou are currently at Station 01");
        }

        else if (s0 == 1 && s1 == 0){
            printf("11");
            printf(" - - ");
            printf("\033[1;33m"); // Yellow
            printf("Y");
            printf("\033[0;37m"); // White
            printf("\n|      |\n");
            printf("00");
            printf(" - - ");
            printf("01");
            printf("\033[0;37m"); // White
            printf("\nYou are currently at Station 10");
        }
        else if (s0 == 1 && s1 == 1){
            printf("\033[1;33m");
            printf("Y");
            printf(" - - ");
            printf("\033[1;32m"); // Green
            printf("10");
            printf("\033[0;37m"); // White
            printf("\n|      |\n");
            printf("00");
            printf(" - - ");
            printf("01");
            printf("\033[0;37m"); // White
            printf("\nYou are currently at Station 11");
        }

        printf("\nCurrent state = %d%d%d\n", s0,s1,s2);

        if(s0 == 1 && s1 == 0 && s2 == 1){
            printf("You are currently at your destination.");
        }

        if ((s0 == 0 && s1 == 0 && s2 == 0) || (s0 == 0 && s1 == 1 && s2 == 1) || (s0 == 1 && s1 == 0 && s2 == 1) || (s0 == 1 && s1 == 1 && s2 == 1)){
            printf("\nYou are travelling clockwise.");
        }
        else{
            printf("\nYou are travelling anticlockwise.");
        }
        
        printf("\nHow do you want to travel?\n\n0 - Change track \n1 - Move to next station\n");

        scanf("%d", &input);


        // According to K-map values

        next_s0 = (s0 && !input) || (s2 && input && !s0) || (s0 && !s1 && s2 && input) || (s0 && s1 && !s2 && input);

        next_s1 = (s1^input);

        next_s2 = (!s2 && !input) || (!s0 && !s2) || (s2 && input && (s0^s1));


        // Update the values

        s0 = next_s0;
        s1 = next_s1;
        s2 = next_s2;
        input = -1;

    }

    return 0;
}