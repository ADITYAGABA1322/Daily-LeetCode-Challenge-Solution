1046. Last Stone Weight


    

24 April 2023
    

    
Easy

    

C++:


// Time Complexity : O(nlogn) where n is the number of stones and space complexity is O(n) where n is the number of stones








class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;  // priority queue to store the stones
        for(int i = 0; i < stones.size(); i++){  // for loop to iterate through the stones
            pq.push(stones[i]);  // push the stones into the priority queue
        }
        while(pq.size() > 1){  // while the size of the priority queue is greater than 1
            int x = pq.top();  // get the first stone
            pq.pop();  // pop the first stone
            int y = pq.top();  // get the second stone
            pq.pop();  // pop the second stone
            if(x != y){  // if the stones are not equal
                pq.push(x-y);  // push the difference of the stones into the priority queue
            }
        }
        if(pq.empty()){  // if the priority queue is empty
            return 0;  // return 0
        }
        return pq.top();  // return the top of the priority queue
    }
};



                        OR

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin() , stones.end());
        while(pq.size()>1){
            int x = pq.top() ;
             pq.pop();
            int y = pq.top() ;
              pq.pop();
            if(x > y) pq.push(x - y); 
        }
        return pq.empty() ? 0 : pq.top();
    }
};







Java:



// Time Complexity : O(nlogn) where n is the number of stones and space complexity is O(n) where n is the number of stones






class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());  // priority queue to store the stones
        for(int i = 0; i < stones.length; i++){  // for loop to iterate through the stones
            pq.add(stones[i]);  // add the stones into the priority queue
        }
        while(pq.size() > 1){  // while the size of the priority queue is greater than 1
            int x = pq.poll();  // get the first stone
            int y = pq.poll();  // get the second stone
            if(x != y){  // if the stones are not equal
                pq.add(x-y);  // add the difference of the stones into the priority queue
            }
        }
        if(pq.isEmpty()){  // if the priority queue is empty
            return 0;  // return 0
        }
        return pq.poll();  // return the top of the priority queue
    }
}





                OR





class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int i = 0; i < stones.length; i++){
            pq.add(stones[i]);
        }
        while(pq.size() > 1){
            int x = pq.poll();
            int y = pq.poll();
            if(x != y){
                pq.add(x-y);
            }
        }
        return pq.isEmpty() ? 0 : pq.poll();
    }
}

