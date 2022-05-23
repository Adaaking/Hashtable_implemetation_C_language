#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include <stdbool.h>

#define BUCKET_COUNT 1024

struct Binding{
    const char* key;
    int value;
    struct Binding* next;
};
struct HashTable{
    struct Binding* buckets[BUCKET_COUNT];
};

//this function returns the hashtable index for the character array provide to it
unsigned int hash(const char* key){
    int sum = 0;
    for(int i = 0; key[i];i++){
        sum = sum + key[i];
    }
}

//This function should create and initialize a HashTable and return it.
struct HashTable* create(){
    struct HashTable *table = (struct HashTable*)malloc(sizeof(struct HashTable));
    for(int i=0; i<BUCKET_COUNT;i++){
        table->buckets[i] = NULL;
    }
    return table;
}
// this just print the datas in the hashtable
void pintHashTable(HashTable *table){
    for(int i= 0; i<BUCKET_COUNT;i++){
        if(table->buckets[i]== NULL){
            printf("\t%i\t---\n",i);
        }else{
            printf("\t%i\t ",i);
            struct Binding* tmp = table->buckets[i];
            while(tmp!=NULL){
                printf("%s--",tmp->key);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
}

bool add(struct HashTable* table, const char* key, int value){
    int index = hash(key);
    struct Binding *node = (struct Binding*)malloc(sizeof(struct Binding));
    node->key = key;
    node->value = value;
    node->next = NULL;

    struct Binding* temp=table->buckets[index];
    while (temp!=NULL)
    {
        if (temp->key== key){
            temp->value = value;
            return false;
        }
        temp=temp->next;
    }
    node->next=table->buckets[index];
    table->buckets[index]=node;
    return true;
}

struct Binding* find(struct HashTable* table, const char* key){
    int index = hash(key); 
    struct Binding* temp=table->buckets[index];
   if(table->buckets[index]==NULL){
        return NULL;
    } 
    while (temp!=NULL)
    {
        if (temp->key== key){
            return temp;
        }
        temp=temp->next;
    }
   return NULL;
}


bool remove(struct HashTable* table, const char* key){
    int index = hash(key); 
    struct Binding* head=table->buckets[index];
    struct Binding* prev = table->buckets[index];

    if(table->buckets[index]==NULL){
        return false;
    }
    if(table->buckets[index]->key==key){
        table->buckets[index] = head->next;
        head->next = NULL;
        free(head);
        return true;
    }
    while (head!=NULL)
      {
        if (head->key== key){
            prev->next = head->next;
            head->next = NULL;
            free(head);
            return true;
        }
        prev = head;
        head = head->next;
    }
  return false;
}

void delete_table(struct HashTable* table){
    for(int i=0;i<BUCKET_COUNT;i++){
        struct Binding* ptr = table->buckets[i];
        struct Binding* pointer = table->buckets[i];
        while(ptr!=NULL){
            pointer = ptr;
            ptr = ptr->next;
            // free((void*)pointer->key);
            free(pointer);
        }
    }
    free(table);
}
    