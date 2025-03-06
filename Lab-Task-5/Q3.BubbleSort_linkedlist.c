#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* getTail(struct Node* head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

struct Node* partition(struct Node* head, struct Node* tail, struct Node** newHead, struct Node** newTail) {
    struct Node* pivot = tail;
    struct Node* prev = NULL, *cur = head, *tailNode = pivot;

    *newHead = NULL;
    *newTail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (*newHead == NULL) *newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev != NULL) prev->next = cur->next;
            struct Node* temp = cur->next;
            cur->next = NULL;
            tailNode->next = cur;
            tailNode = cur;
            cur = temp;
        }
    }

    if (*newHead == NULL) *newHead = pivot;
    *newTail = tailNode;

    return pivot;
}

struct Node* quickSortRecursive(struct Node* head, struct Node* tail) {
    if (head == NULL || head == tail) return head;

    struct Node* newHead, *newTail;
    struct Node* pivot = partition(head, tail, &newHead, &newTail);

    if (newHead != pivot) {
        struct Node* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = NULL;

        newHead = quickSortRecursive(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecursive(pivot->next, newTail);
    return newHead;
}

void quickSort(struct Node** headRef) {
    *headRef = quickSortRecursive(*headRef, getTail(*headRef));
}

void append(struct Node** headRef, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) temp = temp->next;
    temp->next = new_node;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    append(&head, 3);
    append(&head, 6);
    append(&head, 8);
    append(&head, 10);
    append(&head, 1);
    append(&head, 7);
    append(&head, 2);
    append(&head, 4);

    printf("Unsorted List:\n");
    printList(head);

    quickSort(&head);

    printf("Sorted List:\n");
    printList(head);

    return 0;
}

