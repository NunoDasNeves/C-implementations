// List ADT for stacking, queueing etc

#ifndef LIST_H

typedef struct _list * List;
// this points to an item of the user's choice
typedef ListItem void *;

// create new list
List ListNew();

// push to the front
void ListShift(List,ListItem);
// remove first element. takes a function that frees the list item
void ListUnShift(List, (void)f(ListItem));

// append to the end
void ListPush(List,ListItem);

// returns top item
ListItem ListTop(List);
// returns bottom item
ListItem ListBottom(List);

// frees the list items; takes a function that frees the list item (can just be free() for non-structs)
void ListDestroy(List, (void)f(ListItem));

#endif
