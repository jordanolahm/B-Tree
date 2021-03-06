#ifndef _BTREE_H_
#define _BTREE_H_

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

typedef enum {false,true} bool;

typedef struct
{
    void *key;
    void *val;
} bt_key_val;

typedef struct bt_node
{
    struct bt_node *next;		// Pointer used for linked list
    bool leaf;			// Used to indicate whether leaf or not
    unsigned int nr_active;		// Number of active keys
    unsigned int level;		// Level in the B-Tree
    bt_key_val     **key_vals; 	// Array of keys and values
    struct bt_node **children;	// Array of pointers to child nodes
}bt_node;

typedef struct
{
    unsigned int order;			// B-Tree order
    bt_node      *root;			// Root of the B-Tree
    unsigned int (*value)    (void * key);	// Generate uint value for the key
    unsigned int (*key_size) (void * key);  // Return the key size
    unsigned int (*data_size)(void * data); // Return the data size
    void (*print_key)(void * key);		// printf the key
}btree;

btree* btree_create(unsigned int order);
int btree_insert_key(btree * btree, bt_key_val * key_val);
int btree_delete_key(btree * btree,bt_node * subtree ,void * key);
bt_key_val* btree_search(btree * btree,  void * key);
void btree_destroy(btree * btree);
void* btree_get_max_key(btree * btree);
void* btree_get_min_key(btree * btree);

void print_subtree(btree *btree,bt_node *node);

#endif
