#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

typedef struct _data {
   int x;
   int y;
   int z;
   int a;
} DATA, *PDATA;

typedef struct _key {
   unsigned int  a;
   unsigned long b;
} KEY, *PKEY;

#define true 1
#define false 0
/* Type representing a node in the B+ tree.
 * This type is general enough to serve for both
 * the leaf and the internal node.
 * The heart of the node is the array
 * of keys and the array of corresponding
 * pointers.  The relation between keys
 * and pointers differs between leaves and
 * internal nodes.  In a leaf, the index
 * of each key equals the index of its corresponding
 * pointer, with a maximum of order - 1 key-pointer
 * pairs.  The last pointer points to the
 * leaf to the right (or NULL in the case
 * of the rightmost leaf).
 * In an internal node, the first pointer
 * refers to lower nodes with keys less than
 * the smallest key in the keys array.  Then,
 * with indices i starting at 0, the pointer
 * at i + 1 points to the subtree with keys
 * greater than or equal to the key in this
 * node at index i.
 * The num_keys field is used to keep
 * track of the number of valid keys.
 * In an internal node, the number of valid
 * pointers is always num_keys + 1.
 * In a leaf, the number of valid pointers
 * to data is always num_keys.  The
 * last leaf pointer points to the next leaf.
 */
typedef struct _ondisk_node {
	off_t *values;
	off_t *keys;
	off_t parent_ondisk_node;
	off_t next_ondisk_node; // Used for queue.
   int   isleaf;
} ondisk_node, *pondisk_node;

typedef struct b_plus_tree {
   char filename[PATH_MAX];
   FILE *fd;
   int  order;
   int  n_keys;
   //recovery?
} BP_TREE, *PBP_TREE;

pondisk_node make_ondisk_node(PBP_TREE bptree)
{
   pondisk_node node = calloc(1, sizeof(ondisk_node));
   node->keys = calloc(bptree->order, sizeof(off_t));
   node->values = calloc(bptree->order, sizeof(off_t));
   memset(node, 0, sizeof(ondisk_node));
   return pondisk_node;
}

/* Inserts a new key and pointer
 * to a new record into a leaf so as to exceed
 * the tree's order, causing the leaf to be split
 * in half.
 */
node * insert_into_leaf_after_splitting(node * root, node * leaf, int key, record * pointer) {

	node * new_leaf;
	int * temp_keys;
	void ** temp_pointers;
	int insertion_index, split, new_key, i, j;

	new_leaf = make_leaf();

	temp_keys = malloc( order * sizeof(int) );
	if (temp_keys == NULL) {
		perror("Temporary keys array.");
		exit(EXIT_FAILURE);
	}

	temp_pointers = malloc( order * sizeof(void *) );
	if (temp_pointers == NULL) {
		perror("Temporary pointers array.");
		exit(EXIT_FAILURE);
	}

	insertion_index = 0;
	while (insertion_index < order - 1 && leaf->keys[insertion_index] < key)
		insertion_index++;

	for (i = 0, j = 0; i < leaf->num_keys; i++, j++) {
		if (j == insertion_index) j++;
		temp_keys[j] = leaf->keys[i];
		temp_pointers[j] = leaf->pointers[i];
	}

	temp_keys[insertion_index] = key;
	temp_pointers[insertion_index] = pointer;

	leaf->num_keys = 0;

	split = cut(order - 1);

	for (i = 0; i < split; i++) {
		leaf->pointers[i] = temp_pointers[i];
		leaf->keys[i] = temp_keys[i];
		leaf->num_keys++;
	}

	for (i = split, j = 0; i < order; i++, j++) {
		new_leaf->pointers[j] = temp_pointers[i];
		new_leaf->keys[j] = temp_keys[i];
		new_leaf->num_keys++;
	}

	free(temp_pointers);
	free(temp_keys);

	new_leaf->pointers[order - 1] = leaf->pointers[order - 1];
	leaf->pointers[order - 1] = new_leaf;

	for (i = leaf->num_keys; i < order - 1; i++)
		leaf->pointers[i] = NULL;
	for (i = new_leaf->num_keys; i < order - 1; i++)
		new_leaf->pointers[i] = NULL;

	new_leaf->parent = leaf->parent;
	new_key = new_leaf->keys[0];

	return insert_into_parent(root, leaf, new_key, new_leaf);
}


/* Inserts a new pointer to a record and its corresponding
 * key into a leaf.
 * Returns the altered leaf.
 */
node * insert_into_leaf( node * leaf, int key, record * pointer ) {

	int i, insertion_point;

	insertion_point = 0;
	while (insertion_point < leaf->num_keys && leaf->keys[insertion_point] < key)
		insertion_point++;

	for (i = leaf->num_keys; i > insertion_point; i--) {
		leaf->keys[i] = leaf->keys[i - 1];
		leaf->pointers[i] = leaf->pointers[i - 1];
	}
	leaf->keys[insertion_point] = key;
	leaf->pointers[insertion_point] = pointer;
	leaf->num_keys++;
	return leaf;
}


/* First insertion:
 * start a new tree.
 */
node * start_new_tree(int key, record * pointer) {

   node * root = make_leaf();
   root->keys[0] = key;
   root->pointers[0] = pointer;
   root->pointers[order - 1] = NULL;
   root->parent = NULL;
   root->num_keys++;
   return root;
}


/* Master insertion function.
 * Inserts a key and an associated value into
 * the B+ tree, causing the tree to be adjusted
 * however necessary to maintain the B+ tree
 * properties.
 */
int insert(PBP_TREE bptree, void *key, size_t key_size, void *value, size_t val_size) 
{

	/* The current implementation ignores
	 * duplicates.
	 */

	if (find(root, key, false) != NULL)
		return root;

	/* Case: the tree does not exist yet.
	 * Start a new tree.
	 */

	if (bptree->n_keys == 0) {
      //start a new tree
      pondisk_node root = make_node(bptree);
      fwrite(bptree,); 
      root->isleaf = 0;
      lseek(bptree, 0, SEEK_SET);
      

		//start_new_tree(bptree, key, key_size, value, val_size);


	/* Case: the tree already exists.
	 * (Rest of function body.)
	 */

	leaf = find_leaf(root, key, false);

	/* Case: leaf has room for key and pointer.
	 */

	if (leaf->num_keys < order - 1) {
		leaf = insert_into_leaf(leaf, key, pointer);
		return root;
	}


	/* Case:  leaf must be split.
	 */

	return insert_into_leaf_after_splitting(root, leaf, key, pointer);
}


PBP_TREE bptree_open(char *filename, int order, int create)
{
   FILE *fd;
   size_t  nbytes;
   PBP_TREE tree = malloc(sizeof(BP_TREE));
   if (!access(filename , F_OK)) {
      fd = fopen(filename , "ab+");
      if (fd > 0) {
         fseek(fd, 0, SEEK_SET);
         nbytes = fread(tree, sizeof(BP_TREE), 1, fd);
         if (nbytes != 1) {
            fprintf(stderr, "error in reading db data\n");
            exit(1);
         }
         tree->fd = fd;
      }
   } else if (create) {
      strncpy(tree->filename, filename, strlen(filename)+1);
      tree->order = order;
      tree->n_keys = 0;
      tree->fd = fopen(filename , "ab+");
      if (tree->fd) {
         nbytes = fwrite(tree, sizeof(BP_TREE), 1,tree->fd);
            if (nbytes != 1) {
            fprintf(stderr, "error in writing db data, nbytes %d, %s\n", 
                  nbytes, strerror(errno));
            exit(1);
         }
      }
   }
   return tree;
}

void bptree_close(PBP_TREE tree)
{
   fsync(fileno(tree->fd));
   fclose(tree->fd);
   free(tree);
}

/* Creates a new general node, which can be adapted
 * to serve as either a leaf or an internal node.
 */
node * make_node( void ) {
	node * new_node;
	new_node = malloc(sizeof(node));
	if (new_node == NULL) {
		perror("Node creation.");
		exit(EXIT_FAILURE);
	}
	new_node->keys = malloc( (order - 1) * sizeof(size_t *) );
	if (new_node->keys == NULL) {
		perror("New node keys array.");
		exit(EXIT_FAILURE);
	}
	new_node->pointers = malloc( order * sizeof(void *) );
	if (new_node->pointers == NULL) {
		perror("New node pointers array.");
		exit(EXIT_FAILURE);
	}
	new_node->is_leaf = false;
	new_node->num_keys = 0;
	new_node->parent = NULL;
	new_node->next = NULL;
	return new_node;
}

/* Creates a new leaf by creating a node
 * and then adapting it appropriately.
 */
node * make_leaf( void ) {
	node * leaf = make_node();
	leaf->is_leaf = true;
	return leaf;
}

int main(int argc, char *argv[])
{
   PBP_TREE bptree;
   if (argc < 2) {
      fprintf(stderr, "Usage: ./<prog> <dbpathname>\n");
      exit(1);
   }

   bptree = bptree_open(argv[1], 5, 1);
   if (bptree) fprintf(stdout, "open success\n");


   bptree_close(bptree);
   fprintf(stdout, "close success\n");

   bptree = bptree_open(argv[1], 10, 0);
   if (bptree) fprintf(stdout, "open success\n");
   bptree_close(bptree);fprintf(stdout, "close success\n");
   return 0;
}
