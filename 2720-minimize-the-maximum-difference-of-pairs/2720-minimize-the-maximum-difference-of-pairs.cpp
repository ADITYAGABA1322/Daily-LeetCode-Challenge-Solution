class Solution {
	public:
			bool ispos(vector<int>nums,int diff,int pairs){ // function to check if the difference is possible or not
				 int i =1; // variable to store the index
					int n = nums.size(); // variable to store the size of the vector nums
					int k = 0; // variable to store the number of pairs

					for(i;i<n && k<pairs;i++){ // loop for i
							if(nums[i]-nums[i-1]<=diff){ // if the difference is less than or equal to diff
									k++; // increment the k
									i++; // increment the i
							}
					}

					if(k>=pairs){ // if k is greater than or equal to pairs
							return true; // return true
					}
					return false; // return false

			}

			int minimizeMax(vector<int>& nums, int p) {
					sort(nums.begin(),nums.end()); // sort the vector nums
					int n = nums.size(); // variable to store the size of the vector nums
					int left = 0; // variable to store the left
					int right = nums[n-1]-nums[0]; // variable to store the right

					while(left<=right){ // loop till left is less than or equal to right

							int mid = (left+right)/2; // variable to store the mid

							if(ispos(nums,mid,p)){ // if the difference is possible
									right = mid-1; // update the right
							}
							else{
									left = mid+1; // update the left
							}
					}
					return left; // return the left
			}
	};
