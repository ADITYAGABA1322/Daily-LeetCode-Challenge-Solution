class Solution {
    public String longestPalindrome(String s) {
        String t = "#"+ String.join("#" , s.split("")) + "#";
        int n = t.length();
        int C = 0, R =0;
        int[] p = new int[n];
        
        for(int i=1; i<n-1; i++){
            int mirror = 2*C - i;
            if(i<R){
                p[i] = Math.min(R-i , p[mirror]);
            }
            while(i+p[i]+1 < n && i-p[i]-1 >=0 && t.charAt(i-p[i]-1) == t.charAt(i+p[i] + 1) ){
                    p[i]++;
            }
            if(i+p[i] > R){
                C = i;
                R = i+p[i];
                
            }
        }
        
        int maxLen = 0 , centerIdx = 0;
        for(int i=1; i<n-1; i++){
            if(p[i] > maxLen){
                centerIdx = i;
                maxLen = p[i];
            }
        }
        int start = (centerIdx - maxLen)/2;
        return s.substring(start , start + maxLen);
    }
}