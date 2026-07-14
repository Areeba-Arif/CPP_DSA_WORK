void bubbleSort() {
    if (list == NULL) return;

    bool swapped;
    LL_Node* ptr1;
    LL_Node* lptr = NULL;

    do {
        swapped = false;
        ptr1 = list;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // swap data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}




void selectionSort() {
    LL_Node* temp = list;

    while (temp != NULL) {
        LL_Node* min = temp;
        LL_Node* r = temp->next;

        while (r != NULL) {
            if (r->data < min->data)
                min = r;
            r = r->next;
        }

        // swap
        int x = temp->data;
        temp->data = min->data;
        min->data = x;

        temp = temp->next;
    }
}