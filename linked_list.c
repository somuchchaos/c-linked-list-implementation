#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node **head, int data) {
  Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
  printf("Inserted %d at the beginning.\n", data);
}

// Function to insert a node at the end of the list
void insertAtEnd(Node **head, int data) {
  Node *newNode = createNode(data);

  if (*head == NULL) {
    *head = newNode;
  } else {
    Node *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
  printf("Inserted %d at the end.\n", data);
}

// Function to insert a node after a specific value
void insertAfter(Node *head, int afterValue, int data) {
  Node *temp = head;
  while (temp != NULL && temp->data != afterValue) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Value %d not found in the list.\n", afterValue);
  } else {
    Node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d after %d.\n", data, afterValue);
  }
}

// Function to delete a node by value
void deleteNode(Node **head, int value) {
  if (*head == NULL) {
    printf("List is empty. Nothing to delete.\n");
    return;
  }

  Node *temp = *head, *prev = NULL;

  // If head node itself holds the value to be deleted
  if (temp != NULL && temp->data == value) {
    *head = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", value);
    return;
  }

  // Search for the value to be deleted
  while (temp != NULL && temp->data != value) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Value %d not found in the list.\n", value);
    return;
  }

  // Unlink the node from linked list
  prev->next = temp->next;
  free(temp);
  printf("Deleted %d from the list.\n", value);
}

// Function to traverse and display the list
void traverseList(Node *head) {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }

  printf("Linked List: ");
  Node *temp = head;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// Function to free the entire list
void freeList(Node **head) {
  Node *current = *head;
  Node *next;

  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }

  *head = NULL;
  printf("List freed from memory.\n");
}

// Helper function to clear input buffer
void clearInputBuffer() {
  while (getchar() != '\n')
    ;
}

int main() {
  Node *head = NULL;
  int choice, data, afterValue;

  printf("Singly Linked List Operations:\n");

  while (1) {
    printf("\nMenu:\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert after a value\n");
    printf("4. Delete a value\n");
    printf("5. Traverse the list\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
      printf("Invalid input. Please enter a number.\n");
      clearInputBuffer();
      continue;
    }

    switch (choice) {
    case 1:
      printf("Enter data to insert at beginning: ");
      if (scanf("%d", &data) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        break;
      }
      insertAtBeginning(&head, data);
      break;

    case 2:
      printf("Enter data to insert at end: ");
      if (scanf("%d", &data) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        break;
      }
      insertAtEnd(&head, data);
      break;

    case 3:
      printf("Enter the value after which to insert: ");
      if (scanf("%d", &afterValue) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        break;
      }
      printf("Enter data to insert: ");
      if (scanf("%d", &data) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        break;
      }
      insertAfter(head, afterValue, data);
      break;

    case 4:
      printf("Enter value to delete: ");
      if (scanf("%d", &data) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        break;
      }
      deleteNode(&head, data);
      break;

    case 5:
      traverseList(head);
      break;

    case 6:
      freeList(&head);
      printf("Exiting program.\n");
      exit(0);

    default:
      printf("Invalid choice! Please try again.\n");
    }

    // Clear any remaining characters in the input buffer
    clearInputBuffer();
  }

  return 0;
}
