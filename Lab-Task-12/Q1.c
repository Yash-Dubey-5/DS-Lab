#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left, *right;
};

struct node* createNode(int val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = new_node->right = NULL;
    return new_node;
}

struct node* make_node() {
    int val;
    printf("Enter value (-1 to stop): ");
    scanf("%d", &val);

    if (val == -1) return NULL;

    struct node* new_node = createNode(val);
    printf("Enter left child of %d - ", val);
    new_node->left = make_node();
    printf("Enter right child of %d - ", val);
    new_node->right = make_node();
    
    return new_node;
}

void inorder(struct node* root, int *i, int arr[]) {
    if (root == NULL) return;
    inorder(root->left, i, arr);
    arr[(*i)++] = root->data;
    inorder(root->right, i, arr);
}

int main() {
    struct node* root = NULL;
    root = make_node();

    int arr[100];
    int i = 0; 

    inorder(root, &i, arr);

    int k;
    printf("Enter k: ");
    scanf("%d", &k);

    if (k > i || k < 1) {
        printf("Invalid k value\n");
    } else {
        printf("K-th smallest element: %d\n", arr[k-1]);
    }

    return 0;
}

