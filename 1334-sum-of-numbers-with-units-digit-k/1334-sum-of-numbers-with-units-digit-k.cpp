class Solution {
public:
    int minimumNumbers(int num, int k) {
        // in this problme we not use the digit dp here ok in the given problem it ask like return  min possible set or -1 if we need to brak num be like in a set form to check its sum is = k and remeber of thses no we take for sum to check is equal to k just check that those no units digit means last digit contain those no ok means unit digit ok so start the approach just first by taking num we need to split into set form ok first and check those no which contains kth lst digit but how lets taking a loop of num we need to split it we go now digts are 0 to 9 means k is  single digit ok < 10 why as gievn lets take k = 9 max limit and we know these unit digit repated after every 10th multiplaction of a numer as we know 
//  9 * 1 = 9
// 9 * 11 = 99
// 9 * 2 = 18
// 9 * 12 = 108
// 9 * 3 = 27
// 9 * 13 = 117
// and the fact is that we take this no we go through that and check if gievn k multiply by ith index from 1to 10 and check their unit place should match with num unit place if yes we find the set size ok and we check sum <= num ok 
        if(num == 0) return 0;
        for(int i=1; i<=10 ; i++){
            int sum = i*k;
            if(sum%10 == num%10 && sum <= num) return i;
        }
        return -1;
    }
};