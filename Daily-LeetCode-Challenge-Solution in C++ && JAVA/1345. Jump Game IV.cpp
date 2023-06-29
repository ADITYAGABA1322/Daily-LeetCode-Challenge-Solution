1345. Jump Game IV



5 March 2023

    

Hard


C++:




// Time Complexity : O(n) where n is the length of the array and space complexity is O(n)



class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();  // variable to store the length of the array
        unordered_map<int, vector<int>> mp;  // map to store the indices of the elements
        for(int i = 0; i < n; i++){  // iterate through the array
            mp[arr[i]].push_back(i);  // store the indices of the elements
        }
        queue<int> q;  // queue to store the indices
        q.push(0);  // push the first index
        vector<bool> visited(n, false);  // vector to store thae visited indices
        visited[0] = true;  // mark t first index as visited
        int steps = 0;  // variable to store the number of steps
        while(!q.empty()){  // iterate until the queue is empty
            int size = q.size();  // variable to store the size of the queue
            for(int i = 0; i < size; i++){  // iterate through the queue
                int index = q.front();  // variable to store the current index
                q.pop();  // pop the current index
                if(index == n - 1){  // if the current index is the last index
                    return steps;  // return the number of steps
                }
                if(index - 1 >= 0 && !visited[index - 1]){  // if the previous index is valid and not visited
                    q.push(index - 1);  // push the previous index
                    visited[index - 1] = true;  // mark the previous index as visited
                }
                if(index + 1 < n && !visited[index + 1]){  // if the next index is valid and not visited
                    q.push(index + 1);  // push the next index
                    visited[index + 1] = true;  // mark the next index as visited
                }
                for(int j = 0; j < mp[arr[index]].size(); j++){  // iterate through the indices of the current element
                    if(!visited[mp[arr[index]][j]]){  // if the current index is not visited
                        q.push(mp[arr[index]][j]);  // push the current index
                        visited[mp[arr[index]][j]] = true;  // mark the current index as visited
                    }
                }
                mp[arr[index]].clear();  // clear the indices of the current element
            }
            steps++;  // increment the number of steps
        }
        return steps;  // return the number of steps
    }
};
                    




Java:


// Time Complexity : O(n) where n is the length of the array and space complexity is O(n)



class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length;  // variable to store the length of the array
        Map<Integer, List<Integer>> mp = new HashMap<>();  // map to store the indices of the elements
        for(int i = 0; i < n; i++){  // iterate through the array
            mp.putIfAbsent(arr[i], new ArrayList<>());  // store the indices of the elements
            mp.get(arr[i]).add(i);
        }
        Queue<Integer> q = new LinkedList<>();  // queue to store the indices
        q.add(0);  // push the first index
        boolean[] visited = new boolean[n];  // vector to store the visited indices
        visited[0] = true;  // mark the first index as visited
        int steps = 0;  // variable to store the number of steps
        while(!q.isEmpty()){  // iterate until the queue is empty
            int size = q.size();  // variable to store the size of the queue
            for(int i = 0; i < size; i++){  // iterate through the queue
                int index = q.poll();  // variable to store the current index
                if(index == n - 1){  // if the current index is the last index
                    return steps;  // return the number of steps
                }
                if(index - 1 >= 0 && !visited[index - 1]){  // if the previous index is valid and not visited
                    q.add(index - 1);  // push the previous index
                    visited[index - 1] = true;  // mark the previous index as visited
                }
                if(index + 1 < n && !visited[index + 1]){  // if the next index is valid and not visited
                    q.add(index + 1);  // push the next index
                    visited[index + 1] = true;  // mark the next index as visited
                }
                for(int j = 0; j < mp.get(arr[index]).size(); j++){  // iterate through the indices of the current element
                    if(!visited[mp.get(arr[index]).get(j)]){  // if the current index is not visited
                        q.add(mp.get(arr[index]).get(j));  // push the current index
                        visited [mp.get(arr[index]).get(j)] = true;  // mark the current index as visited
                    }
                }
                mp.get(arr[index]).clear();  // clear the indices of the current element
            }
            steps++;  // increment the number of steps
        }
        return steps;  // return the number of steps
    }
}
