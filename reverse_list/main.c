//
//  main.c
//  reverse_list
//
//  Created by stefano on 12/10/13.
//  Copyright (c) 2013 stefano. All rights reserved.
//

/*
 
root    ->  A
            |
            |
NEXT    ->  B
            |
            |
            C
            |
            |
            D               NULL
                             ^
                             |
                             |
                         NEW_ROOT
 
 
 quelli maiuscoli sono le variabili necessarie per eseguire la computazione
 
 A-B-C-D
 
 1) prendi root
 2) prendi NEXT
 3) sgancia la root (ponilo uguale a NEW_ROOT)
 4) aggiorna NEW_ROOT
 5) aggiorna root con NEXT
 goto 1)
 
 D-C-B-A
 
 */

#include <stdio.h>

#include <stdio.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void print_list(Node* root) {
    while (root) {
        printf("%c ", root->data);
        root = root->next;
    }
    printf("\n");
}

Node* reverse(Node* root) {
    Node* new_root = 0;                 // nuova testa
    while (root) {                      // prendi root
        Node* next = root->next;        // prendi next
        root->next = new_root;          // stacca root
        new_root = root;                // attacca al next
        root = next;                    // avanza al successivo
    }
    return new_root;
}

int main(void) {
    Node d = { 'd', 0 };
    Node c = { 'c', &d };
    Node b = { 'b', &c };
    Node a = { 'a', &b };
    
    Node* root = &a;
    print_list(root);
    root = reverse(root);
    print_list(root);
    
    return 0;
}
