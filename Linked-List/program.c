#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a node at the front of the linked list
struct Node *insertFront(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    if (newNode) {
        newNode->next = head;
        return newNode;
    } else {
        printf("Memory allocation failed. Element not added.\n");
        return head;
    }
}

// Function to insert a node at the end of the linked list
struct Node *insertEnd(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    if (!newNode) {
        printf("Memory allocation failed. Element not added.\n");
        return head;
    }

    if (head == NULL) {
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to delete the front node of the linked list
struct Node *deleteFront(struct Node *head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

// Function to delete the end node of the linked list
struct Node *deleteEnd(struct Node *head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Node *current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    return head;
}

// Function to insert a node in the middle of the linked list
struct Node *insertMiddle(struct Node *head, int data, int position) {
    if (position <= 0) {
        printf("Invalid position. Element not added.\n");
        return head;
    }

    if (position == 1) {
        return insertFront(head, data);
    }

    struct Node *newNode = createNode(data);
    if (!newNode) {
        printf("Memory allocation failed. Element not added.\n");
        return head;
    }

    struct Node *current = head;
    for (int i = 1; i < position - 1; i++) {
        if (current->next == NULL) {
            printf("Invalid position. Element not added.\n");
            free(newNode);
            return head;
        }
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete a node from the middle of the linked list
struct Node *deleteMiddle(struct Node *head, int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }

    if (position <= 0) {
        printf("Invalid position. Element not deleted.\n");
        return head;
    }

    if (position == 1) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *current = head;
    for (int i = 1; i < position - 1; i++) {
        if (current->next == NULL) {
            printf("Invalid position. Element not deleted.\n");
            return head;
        }
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Invalid position. Element not deleted.\n");
    } else {
        struct Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
    return head;
}

// Function to print the linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nLinked List Operations\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from End\n");
        printf("5. Insert in Middle\n");
        printf("6. Delete from Middle\n");
        printf("7. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the front: ");
                scanf("%d", &data);
                head = insertFront(head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertEnd(head, data);
                break;
            case 3:
                head = deleteFront(head);
                break;
            case 4:
                head = deleteEnd(head);
                break;
            case 5:
                printf("Enter data to insert in the middle: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                head = insertMiddle(head, data, position);
                break;
            case 6:
                printf("Enter the position to delete from the middle: ");
                scanf("%d", &position);
                head = deleteMiddle(head, position);
                break;
            case 7:
                printf("Linked List: ");
                displayList(head);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}