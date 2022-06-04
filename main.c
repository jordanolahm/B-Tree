#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "btree.h"

unsigned int value(void * key) {
	return *((int *)key);
}

unsigned int keysize(void * key) {
        return sizeof(int);
}

unsigned int datasize(void * data) {
        return sizeof(int);
}

int main(int argc,char * argv[])
{
	int i = 0;
	btree *tree;
	bt_key_val * kv;
	int item = 0x43;
	int count;
	int order;
    int * values;

    printf("\n\nFontes baixados de ``http://www.ft.unicamp.br/liag/siteEd/''\n\n");
    getch();

    srand( (unsigned)time(NULL) );

	for(order=2;order<60;order++)
	{
		count = rand()%512;
        values = (int *)malloc(count*sizeof(int));

        for(i = 0;i<count;i++)
			values[i] = rand()%1024;

	    tree = btree_create(order);
		tree->value = value;
		tree->key_size = keysize;
		tree->data_size = datasize;

	    for (i=0;i<count;i++)
		{
		    kv              = (bt_key_val*)malloc(sizeof(*kv));
		    kv->key         = malloc(sizeof(int));
		    *(int *)kv->key = values[i];
		    kv->val         = malloc(sizeof(int));
		    *(int *)kv->val = values[i];
		    btree_insert_key(tree,kv);
	    }

		print_subtree(tree,tree->root);

	    for (i= count - 1; i > -1; i-= (rand()%5))
		{
		    item = values[i];
		    btree_delete_key(tree,tree->root,&item);
	    }
	    free(values);
		btree_destroy(tree);
	}

	return 0;
}
