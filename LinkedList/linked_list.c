#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int value;
    struct Node* next;
} Node;


void push(Node** head, int data) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}


int pop(Node** head) {
    Node* prev = NULL;
    int value;
    if (head == NULL) {
        return -1;
    }
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
    return value;
}


Node* get_Nth(Node* head, int n) {
    int count = 0;
    while (count < n && head) {
        head = head->next;
        ++count;
    }
    return head;
}


Node* get_Last(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}


void push_back(Node* head, int value) {
    Node* last = get_Last(head);
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp;
}


Node* get_LastButOne(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    while (head->next->next) {
        head = head->next;
    }
    return head;
}



// void pop_back(Node** head) {
//     Node* lastBO = NULL;

//     if (!head) {
//         return -1;
//     }
//     if (!(*head) == NULL) {
//         return -1;
//     }

//     lastBO = get_LastButOne(*head);

//     if (lastBO == NULL) {
//         free(*head);
//         *head = NULL;
//     } else {
//         free(lastBO->next);
//         lastBO->next = NULL;
//     }
// }



int pop_back(Node** head) {
    Node* curr = NULL;
    Node* prev = NULL;

    if (!(*head)) {
        return -1;
    }

    curr = *head;
    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL) {
        free(*head);
        *head = NULL;
    } else {
        free(curr->next);
        prev->next = NULL;
    }
}


void insert(Node* head, unsigned n, int value) {
    unsigned i = 0;
    Node* tmp = NULL;

    while (i < n && head->next) {
        head = head->next;
        ++i;
    }
    tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    if (head->next) {
        tmp->next = head->next;
    } else {
        tmp->next = NULL;
    }
    head->next = tmp;
}


int delete_Nth(Node** head, int n) {
    if (n == 0) {
        return pop(head);
    } else {
        Node* prev = get_Nth(*head, n - 1);
        Node* element = prev->next;
        int value = element->value;
        prev->next = element->next;
        free(element);
        return value;
    }
}


void delete_List(Node **head) {
    Node* prev = NULL;
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}


void list_fromArray(Node** head, int* arr, size_t size) {
    if (arr == NULL || size == 0) {
        return;
    }
    for (size_t i = size; i > 0; --i) {
        push(head, arr[i - 1]);
    }
}


int length(const Node* head) {
    int count = 0;
    const Node* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}


int* list_toArray(const Node* head) {
    int leng = length(head);
    int* values = (int*) malloc(leng*sizeof(int));
    while (head) {
        values[--leng] = head->value;
    }
    return values;
}


void printList(const Node* head) {
    while (head) {
        printf("%d", head->value);
        printf(" ");
        head = head->next;
    }
    printf("\n");
}


int main(int argc, char** argv) {
    Node* head = NULL;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    list_fromArray(&head, arr, 10);
     
    printList(head);
 
    insert(head, 4, 333);
    printList(head);
 
    push_back(head, 13223554);
    push_back(head, 7);
    push_back(head, 17);
    push_back(head, 18);
    printList(head);
 
    printf("%d\n", pop(&head));
    printf("%d\n", pop_back(&head));
 
    printList(head);

    delete_Nth(&head, 4);
    printList(head);
    delete_List(&head);

    return 0;
}