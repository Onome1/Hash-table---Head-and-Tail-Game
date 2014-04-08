//
//  main.c
//  hashtable
//
//  Created by Onome Ovedje on 4/3/14.
//  Copyright (c) 2014 oovedje. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include "hash.h"

int main(int argc, const char * argv[])
{
    
    srand((unsigned)time(NULL));
    int com_guess;
    int computer_point = 0;
    int human_point = 0;
    int spot,i;
    char computer_guess;
    char human_guess;
    
    char last_g[5];
    last_g[4] ='\0';
    
    Table h = ht_create();
    printf("=======================================\n");
    printf("             GAME TIME                 \n");
    printf("=======================================\n");
    
    for (i = 0; i< 4 ; i++) {
        
        printf("pick h-->head or t---tail\n");
        printf("***Your pick will be Guess****\n");
        com_guess = rand() %2;
        if (com_guess == 0) {
            computer_guess = 'h';
        }
        else{
            
            computer_guess = 't';
        }
        
    //}
    printf(" \nWhat are you guessing head->h or tail->t\n");
    human_guess = take_input(h);
    last_g[i] = human_guess;
    
    if (computer_guess != human_guess) {
        
        printf(" Wrong Prediction..-->%c\n",computer_guess);
        human_point+=1;
        printf("                   Score Board                  \n");
        printf("========================================================\n");
        printf("  Computer Point---> %i| Human Point---> %i\n",computer_point,human_point);
        printf("========================================================\n");

        
    }
    else{
        
        printf(" Right Prediction..-->%c\n",computer_guess);
        computer_point+=1;
        printf("                   Score Board                  \n");
        printf("===========================================================\n");
        printf("  Computer Point---> %i| Human Point---> %i\n",computer_point,human_point);
        printf("===========================================================\n");
        
        
    }
        printf("\n");
}
    while (computer_point !=25 && human_point !=25) {
        
        spot =str_find(last_g);
        computer_guess = pattern_com(h,spot,last_g);
        
        printf("Next Guess\n");
        human_guess = take_input(h);
        ht_shuffle(last_g);
        last_g[3] = human_guess;
        pos_update(h,spot,human_guess);
        
        if (computer_guess != human_guess ) {
            
            printf(" Wrong Prediction..-->%c\n",computer_guess);
            human_point+=1;
            printf("                   Score Board                  \n");
            printf("========================================================\n");
            printf("  Computer Point---> %i| Human Point---> %i\n",computer_point,human_point);
            printf("========================================================\n");
            

        }
        else{
            
            printf(" Right Prediction..-->%c\n",computer_guess);
            computer_point+=1;
            printf("                   Score Board                  \n");
            printf("===========================================================\n");
            printf("  Computer Point---> %i| Human Point---> %i\n",computer_point,human_point);
            printf("===========================================================\n");
            
        }
        printf("\n");
    }
    if(human_guess == 25){
        
        printf(" HUMAN WON !!\n");
    }
    else{
       
        printf(" COMPUTER WON!!\n");
        
    }
     printf("           These are all the pick->GUESSES         \n");
     printf("===========================================================\n");
       ht_print(h);
       ht_free(h);
    
        return 0;
}

