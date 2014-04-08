//
//  hash.h
//  hashtable
//
//  Created by Onome Ovedje on 4/3/14.
//  Copyright (c) 2014 oovedje. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#ifndef hashtable_hash_h
#define hashtable_hash_h
typedef struct hash_t{
    
    char input_str1[5];
    int h_count;
    int t_count;
}Hash_T;

typedef struct hash_table{
    
    Hash_T *items;
    int size;
}*Table;

extern Table ht_create();

extern void ht_free(Table items);

extern void ht_shuffle( char *ht);

extern int str_find(char *ht);

extern char pattern_com(Table h,int pos, char *ch);

extern void pos_update(Table h, int pos,char cho);

extern char take_input(Table h);

extern void ht_print(Table h);



#endif
