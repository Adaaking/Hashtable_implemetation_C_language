#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "./part1/hashtable.c"

int main(){
    struct HashTable *table = create();
    add(table,"abebe",11);
    add(table,"abe",10);
    // add(table,"key",80);
    add(table,"bruk",10);
    add(table,"bko",10);
    add(table,"bko",100);
    // assert(add(table,"bko",340));
   
    find(table,"bruk");
    find(table,"bko");
    find(table,"key");
    removed(table,"bruk");
    removed(table,"abe");
    removed(table,"abebe");
    find(table,"bruk");
    find(table,"bko");
    find(table,"abebe");

    delete_table(table);
    
    // assert(removed(table,"abe"));
    //  assert(add(table,"y",20));
    //  assert(find(table,"y"));
    // assert(find(table,"y"));
    // removed(table,"bruk");
    // removed(table,"bko");
    // removed(table,"abebe");
    // removed(table,"key");
    
    //  struct HashTable* table = create();
    // assert( find(table, "Test Key") == NULL);
    // assert( add(table, "Test Key", 11) == true);

    // assert( add(table, "Test Key", 11) == false);

    // struct Binding* binding =  find(table, "Test Key");

    // assert( binding != NULL &&  binding->value == 11);
    
    // delete_table(table);




  
    
    return 0;

}