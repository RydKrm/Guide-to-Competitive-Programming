#include <iostream>
using namespace std;

class Queue {
private:
    int *queue;      // Array to store the queue elements
    int front;       // Points to the front of the queue
    int rear;        // Points to the rear of the queue
    int capacity;    // Maximum capacity of the queue
    int size;        // Current size of the queue

public:
    // Constructor to initialize the queue
    Queue(int capacity) {
        this->capacity = capacity;
        queue = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor to free allocated memory
    ~Queue() {
        delete[] queue;
    }

    // Add an item to the end of the queue
    void add(int item) {
        if (size == capacity) {
            cout << "Queue is full. Cannot add more elements." << endl;
            return;
        }
        rear = (rear + 1) % capacity;  // Circular increment
        queue[rear] = item;
        size++;
    }

    // Remove the first item in the queue
    void remove() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot remove elements." << endl;
            return;
        }
        front = (front + 1) % capacity;  // Circular increment
        size--;
    }

    // Return the top (front) item of the queue without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No elements to peek." << endl;
            return -1;  // Return -1 if queue is empty
        }
        return queue[front];
    }

    // Return true if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Return the current size of the queue
    int getSize() {
        return size;
    }
};

int main() {
    // Create a queue with a capacity of 5
    Queue q(5);

    // Add elements to the queue
    q.add(10);
    q.add(20);
    q.add(30);
    q.add(40);

    // Peek at the front element
    cout << "Front element: " << q.peek() << endl;

    // Remove an element from the queue
    q.remove();

    // Peek again to see the front element
    cout << "Front element after removal: " << q.peek() << endl;

    // Check if the queue is empty
    if (q.isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    // Add more elements to the queue
    q.add(50);
    q.add(60);

    // Remove all elements
    while (!q.isEmpty()) {
        cout << "Removing: " << q.peek() << endl;
        q.remove();
    }

    return 0;
}
