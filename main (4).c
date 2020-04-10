#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *create_node(int data);
void print_list(node **head);
void delete_node(node **node, int index);
void add(node **head, int data);
void add_last(node **tail, int data);
void insert(node **head, int index,int data);

int main(){
    node *head = NULL;
    node *tail = NULL;
    node *temp, *p;
    int i;
    temp = create_node(12);
    head = temp;
    tail = temp;
    for(i = 0; i < 5; i++){
        p = create_node(i);
        tail = p;
        temp -> next = p;
        temp = p;
    }
    print_list(&head);
    add(&head,678);
    add(&(head->next),999);
    add_last(&tail,444);
    printf("\n");
    print_list(&head);
    delete_node(&head, 0);
    printf("\n");
    print_list(&head);
    delete_node(&head, 2);
    printf("\n");
    print_list(&head);
    delete_node(&head, 20);
    printf("\n");
    print_list(&head);
    insert(&head, 0, 45);
    insert(&head, 30, 45);
    printf("\n");
    print_list(&head);
    insert(&head, 5, 45);
    printf("\n");
    print_list(&head);
    return 0;
}

node *create_node(int data){
      node *temp;
      temp = (node *)malloc(sizeof(node));
      temp -> data = data;
      temp -> next =NULL;
      return temp;
}

void print_list(node **head){
        node *p;
        p = *head;
        while(p != NULL){
            printf("%d ", p->data);
            p = p->next;
        }
}

void delete_node(node **head, int index){
    node *p,*p1;
    int i;
    p = (*head) -> next;
    if (index == 0){
        free(*head);
        *head = p;
    } else{
        p1 = *head;
        i = 0;
        while(i < index-1 && p1 != NULL){
            p1 = p1 -> next;
            i++;
        }
        if (p1 == NULL){
            printf("\nNo such node!");
        }else{
            p = p1 -> next;
            p1 -> next = p ->next;
            free(p);
        }
    }
}

add(node **head, int data){
    node *temp = (node *)malloc(sizeof(node));
    temp -> next = *head;
    temp -> data = data;
    *head = temp;
}

add_last(node **tail, int data){
    node *temp = (node *)malloc(sizeof(node));
    temp -> next = NULL;
    temp -> data = data;
    (*tail)->next = temp;
    *tail = temp;
}

void insert(node **head, int index,int data){
    node *p;
    int i;
    if (index == 0) {
            add(head, data);
    } else{
        p = *head;
        i = 0;
        while(i < index-1 && p != NULL){
            p = p -> next;
            i++;
        }
        if (p == NULL){
            printf("\nNo such node!");
        } else {
            add(&(p->next),data);
        }
    }
}
