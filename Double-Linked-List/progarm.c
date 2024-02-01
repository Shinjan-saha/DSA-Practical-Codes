#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertAtMiddle(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position for insertion.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (position == 1) {
        insertAtFront(head, data);
        return;
    }

    struct Node* temp = *head;
    int count = 1;

    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position for insertion.\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deleteAtFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from the front.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
}

void deleteAtMiddle(struct Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Invalid position for deletion.\n");
        return;
    }

    struct Node* temp = *head;
    int count = 1;

    while (count < position && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position for deletion.\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    int choice, data, position;

    do {
        printf("\n1. Insert at End\n2. Insert at Front\n3. Insert at Middle\n");
        printf("4. Delete at Front\n5. Delete at Middle\n6. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 3:
                printf("Enter data to insert at middle: ");
                scanf("%d", &data);
                printf("Enter position for insertion: ");
                scanf("%d", &position);
                insertAtMiddle(&head, data, position);
                break;
            case 4:
                deleteAtFront(&head);
                break;
            case 5:
                printf("Enter position for deletion: ");
                scanf("%d", &position);
                deleteAtMiddle(&head, position);
                break;
            case 6:
                displayList(head);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
