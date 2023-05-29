#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printSubsets(struct Node* subsets) {
    printf("Subconjuntos:\n");
    while (subsets != NULL) {
        struct Node* temp = subsets;
        printf("[");
        while (temp != NULL) {
            printf("%d", temp->value);
            if (temp->next != NULL) {
                printf(", ");
            }
            temp = temp->next;
        }
        printf("]\n");
        subsets = subsets->next;
    }
}

void subconjuntos(int nums[], int length) {
    struct Node* output = NULL;
    append(&output, -1); // Inicializa a lista com um subconjunto vazio

    int i;
    for (i = 0; i < length; i++) {
        int num = nums[i];
        struct Node* temp = output;

        while (temp != NULL) {
            struct Node* curr = createNode(num);
            curr->next = temp->next;
            temp->next = curr;
            temp = temp->next->next;
        }
    }

    printSubsets(output->next); // Ignora o primeiro nó vazio

    // Libera a memória alocada
    struct Node* temp = output;
    while (temp != NULL) {
        struct Node* current = temp;
        temp = temp->next;
        free(current);
    }
}

int main() {
    int nums[] = {1, 2, 3};
    int length = sizeof(nums) / sizeof(nums[0]);

    subconjuntos(nums, length);

    return 0;
}

