class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        // lets review the question i get with the approach like by seeing the
        // example 1 and theri explanation like nums1 contains [2,0,1,3] we
        // follow this rules in this pos1x < pos1y < pos1z ok so first the
        // tripets first -> 4 triplets (2 , 0 ,1) , (2, 0 , 3) , (2 , 1 , 3) ,
        // (0 , 1 , 3) ok lets review the nums2 and check which follow the rule
        // of this one pos2x < pos2y < pos2z same way in nums1 after review we
        // see only  this one follow (0 , 1 , 3) it so this only one good
        // triplet we get ok as y go through a question i get a smell of binary
        // search i am right or wrong i think i am right this is getting solve
        // or we say divide and conqurer ok if u relate this also a problem wiht
        // segment ree or binary indexed tree but as u know segment full work on
        // divide and conqurer so using inthis mid left right we solve this
        // problme by. query ,  search and using this but what about brute force
        // if i am thinking about brute force in my mind we take 3 loops to
        // check that it contain this one triplet os1x < pos1y < pos1z or not if
        // yes just check same triplet in nums2 or not if yes cnt it and return
        // it and this solve in O(n^3) ok but acc to the constraints 10^5 means
        // NlogN wokrs here here we just solve it by divide conqurer
        // Brute force Time Limit Exceeded 102 / 148 testcases passed
        // Time Complexity: O(n³) Space Complexity: O(n)
        //     int n = nums1.size();
        //     long long cnt = 0;
        //     // map the values of nums2;
        //     vector<int> pos2(n);
        //     for(int i=0; i<n; i++) pos2[nums2[i]] = i;
        //     for(int i=0; i<n-2; i++){
        //         for(int j=i+1; j<n-1; j++){
        //             for(int k=j+1; k<n; k++){
        //                 int val1 = nums1[i] , val2 = nums1[j] , val3 =
        //                 nums1[k];
        //                 if(pos2[val1] < pos2[val2] && pos2[val2] <
        //                 pos2[val3]) cnt++;
        //             }
        //         }
        //     }
        //     return cnt;
        // }

        // Optimized Approach Using Binary Indexed Tree (BIT) / Fenwick Tree
        // Time and Space Complexity:
        // Time Complexity: O(n log n)
        // Space Complexity: O(n)
        int n = nums1.size();
        vector<int> pos1(n);
        for(int i=0; i<n; i++) pos1[nums1[i]] = i;
        vector<int> mapped(n);
        for(int i=0; i<n; i++) mapped[i] = pos1[nums2[i]];

        // For each position j in mapped array, count:
        // 1. How many elements to its left are smaller (smaller in nums1 and appear earlier in nums2)
        // 2. How many elements to its right are larger (larger in nums1 and appear later in nums2)
        vector<int> bit(n+1 , 0);
        vector<long long> smaller(n);
        for(int j=0; j<n; j++){
            smaller[j] = query(bit , mapped[j]);
            update(bit , mapped[j]+1, 1,  n);
        }
        fill(bit.begin() , bit.end() , 0);
        long long res = 0;
        for(int j=n-1; j>=0; j--){
            long long larger = query(bit , n) - query(bit , mapped[j] );
            res += smaller[j] * larger;
            update(bit , mapped[j] + 1 , 1 , n);
        }
        return res;
    }
    private:
        int query(vector<int>& bit , int i){
            int sum = 0;
            while(i>0){
                sum += bit[i];
                i -= i & (-i);
            }
            return sum;
        }
        void update(vector<int>& bit , int i , int val , int n){
            while(i<=n){
                bit[i] += val;
                i += i & (-i);
            }
        }
};