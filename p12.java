class Solution {
    public String intToRoman(int n) {
        StringBuffer sb = new StringBuffer("");

        String num = Integer.toString(n);

        int len = num.length();
        int i = len;
        if (len == 4) {
            int tmp = Integer.parseInt(num.substring(i - len, i - len + 1));
            for (int j = 0; j < tmp; j++) {
                sb.append('M');
            }
            len--;
        }
        if (len == 3) {
            int tmp = Integer.parseInt(num.substring(i - len, i - len + 1));
            sb.append(getRom(tmp, "C", "D", "M"));
            len--;
        }
        if (len == 2) {
            int tmp = Integer.parseInt(num.substring(i - len, i - len + 1));
            sb.append(getRom(tmp, "X", "L", "C"));
            len--;
        }
        if (len == 1) {
            int tmp = Integer.parseInt(num.substring(i - len, i - len + 1));
            sb.append(getRom(tmp, "X", "V", "I"));
        }

        return sb.toString();
    }

    private String getRom(int n, String first, String mid, String last) {
        if (n == 9) {
            return first + last;
        } else if (n >= 5) {
            int i = 5 - n;
            return mid + first.repeat(i);
        } else if (n == 4) {
            return first + mid;
        } else {
            return first.repeat(n);
        }
    }
}

public class p12 {
    public static void main(String[] args) {

    }
}