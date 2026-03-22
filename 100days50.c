#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Search in BST
struct Node* search(struct Node* root, int key) {
    // Base case
    if (root == NULL || root->data == key)
        return root;

    // Go left or right
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Driver code
int main() {
    struct Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);

    int key = 4;

    struct Node* result = search(root, key);

    if (result != NULL)
        printf("Element %d found in BST\n", key);
    else
        printf("Element %d not found in BST\n", key);

    return 0;
}