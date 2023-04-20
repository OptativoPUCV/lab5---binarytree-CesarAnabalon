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


void removeNode(TreeMap * tree, TreeNode* node) 
{
if (node == NULL) return;

    TreeNode *parent = node->parent;

    // Case 1: No tiene hijos
    if (node->left == NULL && node->right == NULL) {
        if (parent != NULL) {
            if (parent->left == node) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
            node->parent = NULL;
        } else {
            tree->root = NULL;
        }
        free(node);
    }
    // Case 2: Tiene un hijo
    else if (node->left == NULL || node->right == NULL) {
        TreeNode *child = (node->left != NULL) ? node->left : node->right;
        if (parent != NULL) {
            if (parent->left == node) {
                parent->left = child;
            } else {
                parent->right = child;
            }
            child->parent = parent;
            node->parent = NULL;
        } else {
            tree->root = child;
            child->parent = NULL;
        }
        free(node);
    }
    // Case 3: Tiene dos hijos
    else {
        TreeNode *successor = minimum(node->right);
        node->key = successor->key;
        node->value = successor->value;
        removeNode(tree, successor);
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
