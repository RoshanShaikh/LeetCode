public class p7{
    public static void main(String[] args) {
        
    }
}
class Solution {
    public int reverse(int x) {
        StringBuffer s = new StringBuffer();
        s.append(x);
        if(s.charAt(0) == '-') s.deleteCharAt(0);
        s.append('-');
        s.reverse();
        return Integer.parseInt(s.toString());
    }
}