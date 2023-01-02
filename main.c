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
        printf("\n\nCircular City - Finite State Automata\n----------------------\n");
        
        printf("Current state = %d%d%d\n", s0,s1,s2);
        if (s0 == 0 && s1 == 0 && s2 == 0){
            printf("You are currently at home.");
        }

        else if(s0 == 1 && s1 == 0 && s2 == 1){
            printf("You are currently at your destination.");
        }

        else if((s0 == 0 && s1 == 1 && s2 == 1) || (s0 == 1 && s1 == 1 && s2 == 1)){
            printf("You are walking in the city.");
        }
        else{
            printf("You are currently in the train station.");
        }
        
        printf("\n\nHow do you want to travel?\n\n0 - Enter/leave Train Station\n1 - Move to next area\n");

        scanf("%d", &input);

        // s0 next state

        if((s0 == 1 && input == 0) || (s2 == 1 && input == 1 && s0 == 0) || (s0 == 1 && s1 == 0 && s2 == 1 && input == 1) || (s0 == 1 && s1 == 1 && s2 == 0 && input == 1)){
            next_s0 = 1;
        } else { next_s0 = 0; }


        // s1 next state

        if((s1^input) == 1 /* s1 XOR input */){
            next_s1 = 1;
        } else { next_s1 = 0;}

        // s2 next state

        if((s2 == 0 && input == 0) || (s0 == 0 && s2 == 0) || ((s2 == 1 && input == 1) && (s0^s1) == 1)){ 
            next_s2 = 1;
        } else { next_s2 = 0; }


        // Update the values

        s0 = next_s0;
        s1 = next_s1;
        s2 = next_s2;
        input = -1;

    }

    return 0;
}
