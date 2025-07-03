	class Solution {
		public double findMedianSortedArrays(int[] nums1, int[] nums2) {
					int n1 = nums1.length;  // length of the first array
					int n2 = nums2.length;  // length of the second array
					if(n1 > n2){  // if the length of the first array is greater than the length of the second array
							return findMedianSortedArrays(nums2, nums1);  // call the function with the second array as the first array and the first array as the second array
					}
					int low = 0;  // variable to store the low index
					int high = n1;  // variable to store the high index
					while(low <= high){  // while the low index is less than or equal to the high index
							int cut1 = (low + high) / 2;  // variable to store the cut1
							int cut2 = (n1 + n2 + 1) / 2 - cut1;  // variable to store the cut2
							int left1 = cut1 == 0 ? Integer.MIN_VALUE : nums1[cut1 - 1];  // variable to store the left1
							int left2 = cut2 == 0 ? Integer.MIN_VALUE : nums2[cut2 - 1];  // variable to store the left2
							int right1 = cut1 == n1 ? Integer.MAX_VALUE : nums1[cut1];  // variable to store the right1
							int right2 = cut2 == n2 ? Integer.MAX_VALUE : nums2[cut2];  // variable to store the right2
							if(left1 <= right2 && left2 <= right1){  // if the left1 is less than or equal to the right2 and the left2 is less than or equal to the right1
									if((n1 + n2) % 2 == 0){  // if the sum of the lengths of the two arrays is even
											return (Math.max(left1, left2) + Math.min(right1, right2)) / 2.0;  // return the average of the max of the left1 and left2 and the min of the right1 and right2
									}
									else{  // if the sum of the lengths of the two arrays is odd
											return Math.max(left1, left2);  // return the max of the left1 and left2
									}
							}

									else if(left1 > right2){  // if the left1 is greater than the right2
											high = cut1 - 1;  // update the high index
									}
									else{  // if the left2 is greater than the right1
											low = cut1 + 1;  // update the low index
									}

					}
					return 0.0;  // return 0.0
			}
	}
