#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

// helper pointers
struct node *ptr, *current, *temp;

// accurate node count
int node_count = 0;

void create();
void display();
void insert_beg();
void insert_end();
void insert_after();
void delete_beg();
void delete_end();
void search();

int main() {
    int option;
    do {
        printf("\n-----------------------------------------\nOperations on singly linked list\n");
        printf(" 1: Create a list\n 2: Display the list\n 3: Insert node at first\n 4: Insert node at last\n 5: Insert node after a value (position)\n 6: Delete Node from beginning\n 7: Delete Node from end\n 8: Search Element in the linked list\n 9: Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice: ");
        if (scanf("%d", &option) != 1) { // guard against non-int input
            while (getchar() != '\n');
            option = 0;
        }

        switch(option) {
            case 1: create();
                    printf("\nLinked List created/extended. Total nodes = %d\n", node_count);
                    break;
            case 2: display();
                    break;
            case 3: insert_beg();
                    break;
            case 4: insert_end();
                    break;
            case 5: insert_after();
                    break;
            case 6: delete_beg();
                    break;
            case 7: delete_end();
                    break;
            case 8: search();
                    break;
            case 9: exit(0);
                    break;
            default: printf("INVALID CHOICE\n");
        }
    } while(1);
    return 0;
}

void create() {
    int ch = 1;
    while(ch) {
        ptr = (struct node *)malloc(sizeof(struct node));
        if(ptr == NULL) {
            printf("\nMemory can't be allocated\n");
            return;
        }
        printf("\nEnter data for new node: ");
        if (scanf("%d", &ptr->data) != 1) { while(getchar()!='\n'); free(ptr); break; }
        ptr->next = NULL;

        if(start == NULL) {
            start = ptr;
            current = ptr;
        } else {
            current->next = ptr;
            current = ptr;
        }
        node_count++;
        printf("\nDo you wish to add more nodes? Type 1 for YES and 0 for NO: ");
        if (scanf("%d", &ch) != 1) { while(getchar()!='\n'); ch = 0; }
    }
    if (current) current->next = NULL;
}

void display() {
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    temp = start;
    printf("\nStatus of the linked list:\n");
    int pos = 1;
    while(temp != NULL) {
        printf("[%d]: %d -> ", pos, temp->data);
        temp = temp->next;
        pos++;
    }
    printf("NULL\n");
    printf("No of nodes in the list = %d\n", node_count);
}

void insert_beg() {
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL) {
        printf("\nMemory can't be allocated\n");
        return;
    }
    printf("\nEnter data for new node: ");
    if (scanf("%d", &ptr->data) != 1) { while(getchar()!='\n'); free(ptr); return; }
    ptr->next = start;
    start = ptr;
    node_count++;
    printf("\nNode inserted successfully at the beginning. Total nodes = %d\n", node_count);
}

void insert_end() {
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL) {
        printf("\nMemory can't be allocated\n");
        return;
    }
    printf("\nEnter data for new node: ");
    if (scanf("%d", &ptr->data) != 1) { while(getchar()!='\n'); free(ptr); return; }
    ptr->next = NULL;

    if (start == NULL) {
        start = ptr;
    } else {
        temp = start;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    node_count++;
    printf("\nNode inserted successfully at the end. Total nodes = %d\n", node_count);
}

void insert_after() {
    int num;
    printf("\nEnter the value after which node has to be inserted: ");
    if (scanf("%d", &num) != 1) { while(getchar()!='\n'); return; }

    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL) {
        printf("\nMemory can't be allocated\n");
        return;
    }
    printf("\nEnter data for new node: ");
    if (scanf("%d", &ptr->data) != 1) { while(getchar()!='\n'); free(ptr); return; }

    temp = start;
    while(temp != NULL && temp->data != num) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("\nValue %d not found in the list. Node not inserted.\n", num);
        free(ptr);
        return;
    }

    // insert after temp
    ptr->next = temp->next;
    temp->next = ptr;
    node_count++;
    printf("\nNode successfully inserted after %d. Total nodes = %d\n", num, node_count);
}

void delete_beg() {
    if(start == NULL) {
        printf("\nUNDERFLOW: List is empty\n");
        return;
    }
    temp = start;
    start = start->next;
    free(temp);
    node_count--;
    printf("\nFirst node successfully deleted. Total nodes = %d\n", node_count);
}

void delete_end() {
    struct node *pre = NULL;
    if(start == NULL) {
        printf("\nUNDERFLOW: List is empty\n");
        return;
    }
    temp = start;
    // single-node list
    if(temp->next == NULL) {
        free(temp);
        start = NULL;
        node_count = 0;
        printf("\nLast node successfully deleted. List is now empty.\n");
        return;
    }
    // traverse to last node
    while(temp->next != NULL) {
        pre = temp;
        temp = temp->next;
    }
    pre->next = NULL;
    free(temp);
    node_count--;
    printf("\nLast node successfully deleted. Total nodes = %d\n", node_count);
}

void search() {
    int num, pos = 0;
    printf("\nEnter the value to be searched: ");
    if (scanf("%d", &num) != 1) { while(getchar()!='\n'); return; }

    temp = start;
    while(temp != NULL) {
        pos++;
        if(num == temp->data) {
            printf("\nElement %d found at position %d\n", num, pos);
            return;
        }
        temp = temp->next;
    }
    printf("\nElement %d not found in the list.\n", num);
}
