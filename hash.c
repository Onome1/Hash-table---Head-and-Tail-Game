//
//  hash.c
//  hashtable
//
//  Created by Ovedje Onome on 4/3/14.
//  Copyright (c) 2014 oovedje. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"



Table ht_create(){
    
    int index = 16;
    Table h = malloc(sizeof(Hash_T));
   // h->input_str1 = malloc(sizeof());
    h->items = malloc(sizeof(Table)*index);
    h->size = 0;
    
    int i;
    for (i = 0; i < index; i++) {
        
        h->items[i].h_count = -1;
        h->items[i].t_count = -1;
    }
    
    return h;
}
void ht_free(Table h){
    
    free(h->items);
    free(h);
    
}
void ht_shuffle( char *ht){
    
    ht[0] = ht[1];
    ht[1] = ht[2];
    ht[2] = ht[3];
    
}
int str_find(char *str){
    
    int var;
    var = 0;
    if (str[0] == 'h') {
        
        var +=1;
    }
    if (str[1] == 'h') {
        var+=2;
    }
    if (str[2] == 'h'){
        var+=4;
    }
    if (str[3] == 'h') {
        var+=4;
    }
    
    
    return var;
}
char pattern_com(Table h,int pos, char *ch){
    
    if (h->items[pos].h_count == -1 ) {
        
        h->items[pos].h_count = 0;
        h->items[pos].t_count = 0;
        h->size++;
        
        strcpy( h->items[pos].input_str1, ch);
    }
    if (h->items[pos].h_count > h->items[pos].t_count) {
        
        return 'h';
    }
    else if (h->items[pos].t_count  > h->items[pos].h_count){
        return 't';
    }
    else{
        
        int draw_score;
        draw_score =0;
        draw_score = rand() %2;
        
        if (draw_score == 0) {
            
            return 'h';
        }
        else{
            
            return 't';
        }
      }
}
void pos_update(Table h, int pos,char cho){
    
    if (cho == 'h') {
        
        h->items[pos].h_count+=1;
        
    }
    else{
        
      h->items[pos].t_count+=1;
    
    }
}
char take_input(Table h){
    
    char take[5];
    
    fgets(take, 5, stdin);
    return take[0];
}

void ht_print(Table h){
    
    int i;
    int count = 16;
    for (i = 0; i < count; i++) {
        if (h->items[i].h_count !=-1) {
            printf("===============\n");
            
            printf("Guess-->%s\n ",h->items[i].input_str1);
            printf("Heads-->%d\n",h->items[i].h_count);
            printf("Tails-->%d\n",h->items[i].t_count);
            
            printf("================\n");
        }
    }
    
    
    
}

