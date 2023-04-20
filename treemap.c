#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) 
{
  TreeMap * map = (TreeMap*) malloc (sizeof(TreeMap));
  if(map == NULL) return NULL;
  map->root = NULL;
  map->current = NULL;
  map ->lower_than = lower_than; 
  return map;
}


void insertTreeMap(TreeMap * tree, void* key, void * value) {

}

TreeNode * minimum(TreeNode * x){
if (x == NULL) return NULL; 
    while (x->left != NULL) { 
        x = x->left;
    }
    return x;
  
}


void removeNode(TreeMap * tree, TreeNode* node) {
if (node->left == NULL && node->right == NULL) {
        if (node->parent->left == node) {
            node->parent->left = NULL;
        } else {
            node->parent->right = NULL;
        }
        free(node->pair);
        free(node);
        return;
    }
  
}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}

Pair * searchTreeMap(TreeMap * tree, void* key) 
{
  if (tree == NULL || tree->root == NULL) 
  {
    return NULL;
  }
  
  TreeNode* nodo = tree->root;
  
  while(nodo != NULL)
  {
    int comparacion = tree->lower_than(key,nodo->pair->key);
    
    if(comparacion < 0)
    {
      nodo = nodo->left;
    }
    else if(comparacion > 0)
    {
      nodo = nodo->right;
    }else{
      tree->current = nodo;
      return nodo->pair;
    }
  }
  return NULL;
}


Pair * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) {
    return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {
    return NULL;
}
