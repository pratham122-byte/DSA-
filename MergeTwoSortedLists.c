/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* createNode(int value) {

    struct ListNode* newNode =
        (struct ListNode*)malloc(sizeof(struct ListNode));

    newNode->val = value;
    newNode->next = NULL;

    return newNode;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    int extra = 0;
    int i, j;

    while(list1 != NULL && list2 != NULL) {

        struct ListNode* temp = NULL;

        if(list1->val <= list2->val) {

            temp = createNode(list1->val);
            list1 = list1->next;
        }
        else {

            temp = createNode(list2->val);
            list2 = list2->next;
        }

        if(head == NULL) {

            head = temp;
            tail = temp;
        }
        else {

            tail->next = temp;
            tail = tail->next;
        }
    }

    while(list1 != NULL) {

        struct ListNode* temp = createNode(list1->val);

        if(head == NULL) {

            head = temp;
            tail = temp;
        }
        else {

            tail->next = temp;
            tail = tail->next;
        }

        list1 = list1->next;
    }

    while(list2 != NULL) {

        struct ListNode* temp = createNode(list2->val);

        if(head == NULL) {

            head = temp;
            tail = temp;
        }
        else {

            tail->next = temp;
            tail = tail->next;
        }

        list2 = list2->next;
    }

    
    for(i = 0; i < 100000; i++) {

        for(j = 0; j < 20; j++) {

            extra += (i + j) % 17;
        }
    }

    return head;
}
