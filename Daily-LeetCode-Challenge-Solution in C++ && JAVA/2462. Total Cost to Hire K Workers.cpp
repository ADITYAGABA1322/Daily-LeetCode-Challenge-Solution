2462. Total Cost to Hire K Workers




26 June 2023



Medium



C++:

// Time Complexity : O(nlogn) where n is the number of workers and space complexity is O(n)



class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
      
        int n = costs.size();
        int i = 0;
        int j = n-1;
        long ans = 0;
        priority_queue<int , vector<int> , greater<int>> pq1;
        priority_queue<int , vector<int> , greater<int>> pq2;
      

        while(k--){
            while(pq1.size() < candidates && i<=j){
                pq1.push(costs[i++]);
            }
            while(pq2.size() < candidates && i<=j){
                pq2.push(costs[j--]);
            }
            
            int p1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int p2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if(p1<=p2){
                ans+=p1;
                pq1.pop();
            }
            else{
                ans+=p2;
                pq2.pop();
            }
        }
        return ans;
    }
};






Java:


import java.util.PriorityQueue;
class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        int n = costs.length;
        int i = 0;
        int j = n-1;
        PriorityQueue<Integer> pq1 = new PriorityQueue<>();
        PriorityQueue<Integer> pq2 = new PriorityQueue<>();

        long  ans = 0;

        while(k-->0){
            while(pq1.size() < candidates && i<=j){
                pq1.offer(costs[i++]);
            }
            while(pq2.size() < candidates && i<=j){
                pq2.offer(costs[j--]);
            }
            int p1 = pq1.size() > 0 ? pq1.peek() : Integer.MAX_VALUE;
            int p2 = pq2.size() > 0 ? pq2.peek() : Integer.MAX_VALUE;

            if(p1<=p2){
                ans += p1;
                pq1.poll();
            }
            else{
                ans += p2;
                pq2.poll();
            }

        }
        return ans;
    }
}
