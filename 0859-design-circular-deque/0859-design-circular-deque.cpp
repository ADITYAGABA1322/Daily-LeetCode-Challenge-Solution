struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int val, Node* next = NULL, Node* prev = NULL)
        : val(val), next(next), prev(prev) {}
};

class MyCircularDeque {
private:
    Node* head;
    Node* rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) {
        head = NULL;
        rear = NULL;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        if (head == NULL) {
            head = new Node(value);
            rear = head;
        } else {
            Node* newHead = new Node(value);
            newHead->next = head;
            head->prev = newHead;
            head = newHead;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        if (head == NULL) {
            head = new Node(value);
            rear = head;
        } else {
            Node* newNode = new Node(value, NULL, rear);
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        if (size == 1) {
            head = NULL;
            rear = NULL;
        } else {
            Node* nextNode = head->next;
            delete head;
            head = nextNode;
        }
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        if (size == 1) {
            head = NULL;
            rear = NULL;
        } else {
            Node* prevNode = rear->prev;
            delete rear;
            rear = prevNode;
        }
        size--;
        return true;
    }

    int getFront() { return (isEmpty()) ? -1 : head->val; }

    int getRear() { return (isEmpty()) ? -1 : rear->val; }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
};