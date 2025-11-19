#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int count = 0, ch = 1, i = 1;
struct node *ptr, *start = NULL, *current, *temp; //creating pointers

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
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Insert node at first");
        printf("\n 4: Insert node at last");
        printf("\n 5: Insert node at position");
        printf("\n 6: Delete Node from beginning");
        printf("\n 7: Delete Node from end");
        printf("\n 8: Search Element in the linked list");
        printf("\n 9: Exit");
        printf("\n-----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1: create();
                    printf("\n Linked List is created");
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
            default: printf("INVALID CHOICE");
        }
    } while(option != 0);
    printf("\n");
    return 0;
}

void create() {
    while(ch) {
        ptr = (struct node *)malloc(sizeof(struct node));
        if(ptr == NULL) {
            printf("\n Memory can't be allocated");
        } else {
            printf("\n Enter data for node no %d: ", i);
            scanf("%d", &ptr->data);
            i++;
            ptr->next = NULL;
            if(start == NULL) {
                start = ptr;
                current = ptr;
            } else {
                current->next = ptr;
                current = ptr;
            }
        }
        printf("\n Do you wish to add more nodes? \nType 1 for YES and 0 for NO: ");
        scanf("%d", &ch);
    }
    current->next = NULL;
}

void display() {
    current = start;
    printf("\n Status of the linked list:\n");
    while(current != NULL) {
        printf("%d\t", current->data);
        count++;
        current = current->next;
    }
    printf("NULL");
    printf("\n No of nodes in the list = %d", count);
}

void insert_beg() {
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL) {
        printf("\n Memory can't be allocated");
    } else {
        printf("\n Enter data for node no %d: ", i);
        scanf("%d", &ptr->data);
        ptr->next = start;
        start = ptr;
        i++;
        printf("\n Node inserted successfully at the beginning");
    }
}

void insert_end() {
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL) {
        printf("\n Memory can't be allocated");
    } else {
        printf("\n Enter data for node no %d: ", i);
        scanf("%d", &ptr->data);
        ptr->next = NULL;
        i++;
        temp = start;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        printf("\n Node inserted successfully at the end");
    }
}

void insert_after() {
    struct node *pre;
    int num;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL) {
        printf("\n Memory can't be allocated");
    } else {
        printf("\n Enter the value after which node has to be inserted: ");
        scanf("%d", &num);
        printf("\n Enter data for node no %d: ", i);
        scanf("%d", &ptr->data);
        i++;
        temp = start;
        pre = temp;
        while(pre->data != num) {
            pre = temp;
            temp = temp->next;
        }
        pre->next = ptr;
        ptr->next = temp;
        printf("\n Node successfully inserted after %d", num);
    }
}

void delete_beg() {
    if(start == NULL) {
        printf("\n UNDERFLOW");
    } else {
        temp = start;
        start = start->next;
        free(temp);
        printf("\n First node successfully deleted");
    }
}

void delete_end() {
    struct node *pre;
    if(start == NULL) {
        printf("\n UNDERFLOW");
    } else {
        temp = start;
        while(temp->next != NULL) {
            pre = temp;
            temp = temp->next;
        }
 
        pre->next = NULL;
        i--;
        free(temp);
        printf("\n Last node successfully deleted");
    }
}

void search() {
    int num, pos = 0;
    printf("\n Enter the value to be searched: ");
    scanf("%d", &num);
    temp = start;
    while(temp != NULL) {
        pos++;
        if(num == temp->data) {
            printf("\n Element found at position %d", pos);
            return;
        } else {
            temp = temp->next;
        }
    }
    printf("\n Element not found in the list.");
}
