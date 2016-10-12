class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack2.push(element);
    }
 
    int pop() {
        // write your code here
        if (stack1.empty()) {
            while (!stack2.empty()) {
                int temp = stack2.top();
                stack2.pop();
                stack1.push(temp);
            }
        }
        int element = stack1.top();
        stack1.pop();
        return element;
    }

    int top() {
        // write your code here
        if (stack1.empty()) {
            while (!stack2.empty()) {
                int temp = stack2.top();
                stack2.pop();
                stack1.push(temp);
            }
        }
        return stack1.top();
    }
};


