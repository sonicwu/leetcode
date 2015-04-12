#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *insertionSortList(struct ListNode *list) {
    if (list == NULL)
        return list;

    struct ListNode* sorted;
    struct ListNode* current;
    struct ListNode* search;

    // first split.
    sorted = list;
    list = list->next;
    sorted->next = NULL;

    while(list) {
        // advance the list.
        current = list;
        list = list->next;

        if (current->val < sorted->val) {
            // 'current' is new sorted head.
            current->next = sorted;
            sorted = current;
        } else {
            // search list for position of 'current'.
            search = sorted;
            while(search->next && current->val > search->next->val) {
                search = search->next;
            }

            // current goes after search('sorted').
            current->next = search->next;
            search->next = current;
        }
    }

    return sorted;
}

struct ListNode* newNode(int val) {
    // init struct's pointer (to avoid segmentation fault)
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));;
    
    node->val = val;
    node->next = NULL;
  
    return(node);
}

void printList(char *prefix, struct ListNode *list) {
    printf("%s:", prefix);
    while(list) {
        printf("%d->", list->val);
        list = list->next;
    }
    printf("%s\n", "NULL");
}

int main() {
    struct ListNode* head = newNode(5);
    head->next = newNode(3);
    head->next->next = newNode(2);
    head->next->next->next = newNode(4);

    head = insertionSortList(head);
    printList("result", head);
}
