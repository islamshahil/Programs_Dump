struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    ListNode *result = new ListNode(0);
    ListNode *temp = result;
    int i = 1, car = 0;
    while (l1 != NULL || l2 != NULL || car == 1)
    {
        int ans = car;
        if (l1 != NULL)
        {
            ans += (l1->val);
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            ans += (l2->val);
            l2 = l2->next;
        }
        ListNode *newNode = new ListNode(ans % 10);
        result->next = newNode;
        result = result->next;
        car = ans / 10;
    }

    return temp->next;
}
