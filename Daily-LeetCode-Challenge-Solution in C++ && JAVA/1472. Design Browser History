1472. Design Browser History


18 March 2023


Medium


2 Methods



BY USING :  DYNAMIC ARRAY || USING STACK


C++:


// Time Complexity : O(n) where n is the number of operations and space complexity is O(n) where n is the number of operations





class BrowserHistory {
public:
    stack<string> forw;  // stack to store the forward history
    stack<string> backward;  // stack to store the backward history
    BrowserHistory(string homepage) {
        forw.push(homepage);  // push the homepage into the forward stack
    }
    
    void visit(string url) {
        forw.push(url);  // push the url into the forward stack
        while(!backward.empty()){  // iterate through the backward stack
            backward.pop();  // pop the backward stack
        }
    }
    
    string back(int steps) {
        while(steps > 0 && forw.size() > 1){  // iterate through the forward stack
            backward.push(forw.top());  // push the top of the forward stack into the backward stack
            forw.pop();  // pop the forward stack
            steps--;  // decrement the steps
        }
        return forw.top();  // return the top of the forward stack
    }
    
    string forward(int steps) {
        while(steps > 0 && backward.size() > 0){  // iterate through the backward stack
            forw.push(backward.top());  // push the top of the backward stack into the forward stack
            backward.pop();  // pop the backward stack
            steps--;  // decrement the steps
        }
        return forw.top();  // return the top of the forward stack
    }
};



2ND Method 

class BrowserHistory {
public:
    string arr[101];
    int curr;
    int last;
    BrowserHistory(string homepage) {
        curr =0;
        last =0;
        arr[0] = homepage;
    }
    
    void visit(string url) {
        curr = curr+1;
        arr[curr] = url;
        last = curr;
    }
    
    string back(int steps) {
        int temp = curr;
        if(temp>=steps) curr = temp - steps;
        else curr = 0;
        return arr[curr];
    }
    
    string forward(int steps) {
        int temp = last- curr;
        if(temp>=steps) curr = curr+steps;
        else curr = last;
        return arr[curr];
    }
};





Java:




// Time Complexity : O(n) where n is the number of operations and space complexity is O(n) where n is the number of operations





class BrowserHistory {
    Stack<String> forw;  // stack to store the forward history
    Stack<String> backward;  // stack to store the backward history
    public BrowserHistory(String homepage) {
        forw = new Stack<>();  // create a new stack
        forw.push(homepage);  // push the homepage into the forward stack
    }
    
    public void visit(String url) {
        forw.push(url);  // push the url into the forward stack
        while(!backward.empty()){  // iterate through the backward stack
            backward.pop();  // pop the backward stack
        }
    }
    
    public String back(int steps) {
        while(steps > 0 && forw.size() > 1){  // iterate through the forward stack
            backward.push(forw.pop());  // push the top of the forward stack into the backward stack
            steps--;  // decrement the steps
        }
        return forw.peek();  // return the top of the forward stack
    }
    
    public String forward(int steps) {
        while(steps > 0 && backward.size() > 0){  // iterate through the backward stack
            forw.push(backward.pop());  // push the top of the backward stack into the forward stack
            steps--;  // decrement the steps
        }
        return forw.peek();  // return the top of the forward stack
    }
}


2nd Method



class BrowserHistory {
    String[] arr;
    int curr;
    int last;
    public BrowserHistory(String homepage) {
        arr = new String[101];
        curr =0;
        last =0;
        arr[0] = homepage;
    }
    
    public void visit(String url) {
        curr = curr+1;
        arr[curr] = url;
        last = curr;
    }
    
    public String back(int steps) {
        int temp = curr;
        if(temp>=steps) curr = temp - steps;
        else curr = 0;
        return arr[curr];
    }
    
    public String forward(int steps) {
        int temp = last- curr;
        if(temp>=steps) curr = curr+steps;
        else curr = last;
        return arr[curr];
    }
}

