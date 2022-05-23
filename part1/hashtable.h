#include <stdbool.h>


 struct Binding;
 typedef struct Binding Binding;

struct HashTable;
typedef struct HashTable HashTable;

//This function should create and initialize a HashTable and return it.
struct HashTable* create();
//This function hashes the key and returns an integer mod BUCKET_COUNT
unsigned int hash(const char* key);
void pintHashTable(HashTable *table);
/**
*This function associates the value 'value' using the key 'key'. Two cases
to consider.
Case 1 The key does not already exists in the HashTable. Then you should
create a struct Binding with key 'key' and value 'value', hash the key
and insert the binding into the table using the hash value of the key.
The function then return true.

Case 2 The key already exists in the HashTable. Then you should update
the Bindings old value to the new supplied 'value'. The function 
return false.
*/
bool add(struct HashTable* table, const char* key, int value);
/**
* This function should search for the key 'key' in the HashTable and return
the Binding if it finds one with the key. Otherwise it return
null.
*/
struct Binding* find(struct HashTable* table, const char* key);
/**
* This function should try to remove a binding with key 'key' from the
HashTable. It should return true if it was able to remove/delete the
binding otherwise it return false
**/
bool remove(struct HashTable* table, const char* key);
/**
* This free all dynamically allocated memory for the HashTable
**/
void delete_table(struct HashTable* table);