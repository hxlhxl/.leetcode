/*
 * @lc app=leetcode id=61 lang=c
 *
 * [61] Rotate List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    // 链表为空
    if (head == NULL || k == 0) return head;

    struct ListNode *tail = head;
    int len = 1;
    while(tail->next != NULL) {
        len++;
        tail = tail->next; // p指向最后一个元素
    }
    printf("len is %d", len);

    int step = k % len;
    // head -> [a, b, c, d, e] -> null
    // k: 2

    // k与链表长度相同
    if (step == 0) return head;

    struct ListNode *ptr = head;
    for (int j = 0; j < len - 1 - step; j++) {
        ptr = ptr->next;
    }
    struct ListNode *newHead;
    tail->next = head;
    newHead = ptr->next;
    ptr->next = NULL;

    return newHead;
}
// @lc code=end

