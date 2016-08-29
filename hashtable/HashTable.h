// HashTable.h
// My Hash Table ADT implementation
// by Nuno Das Neves
//
// Features:
// Automatically resizing
// Maps key strings to ints
// 

typedef htRep * HTable;

typedef u_int32_t HTableItem;
typedef char * HTableKey;

// Create a new table
HTable HTableNew();

// Return how many values are currently stored in the table
u_int32_t HTableGetSize(HTable);

// Insert a new value into the table with the specified key
void HTableInsert(HTable, HTableKey, HTableItem);

// Look up a value based on a key
HTableItem HTableLookup(HTable, HTableKey);

// Delete a key and associated value from the table
void HTableRemove(HTable, HTableKey);

// Destroy the table and free associated memory
void HTableFree(HTable);
