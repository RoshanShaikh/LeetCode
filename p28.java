class Solution {
    public int strStr(String haystack, String needle) {
        return haystack.indexOf(needle);
    }
}

public class p28 {
    public static void main(String[] args) {
        System.out.println(new Solution().strStr("jsdhfh", ""));
    }
}