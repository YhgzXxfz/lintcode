class MinStack {
private:
    vector<int> stack;
    vector<int> min_stack;
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        stack.push_back(number);
        if (min_stack.empty() || number <= min_stack.back()) 
            min_stack.push_back(number);
    }

    int pop() {
        // write your code here
        if (stack.empty()) return 0;
        int elem = stack.back();
        if (!min_stack.empty() && elem == min_stack.back()) {
            min_stack.pop_back();
        }
        stack.pop_back();
        return elem;
    }

    int min() {
        // write your code here
        if (!min_stack.empty()) return min_stack.back();
        return 0;
    }
};


