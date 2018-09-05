
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct *Node next;
};

void print_list(struct Node *n){
    
    while (n!=NULL){
        printf("%d", n->value);
        n = n->next;
    }
    printf("NULL \n");
}

void push(struct Node** head, int input_value){
    struct Node new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head;
    new_node->value = input_value;
    new_node->next = NULL;

    if (*head == NULL){
        *head = new_node;
    }

    while (last->next != NULL){
        last = last->next
    }
    last->next = new_node;
    return;
}

void delete(struct Node **head, int key){
    struct Node* temp = *head, *prev;
    if (temp!=NULL && temp->value == key){
        *head = temp->next;
        free(temp);
    }
    
    while (temp!=NULL && temp->value!=key){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);

}

int main(){
    struct Node* begin = NULL;
    push(&begin, 2);
    push(&begin, 4);
    push(&begin, 5);
    push(&begin, 9);
    push(&begin, 13);

    print_listg(begin);

    delete(&begin, 1);
    delete(&begin, 9);

    print_list(begin);

    return 0;

}


