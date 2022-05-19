public class p10 {
    public static boolean matches(int i, int j, String S, String R) {
        if ((i == -1 && (j == -1) || R.substring(0, j + 1).equals("*"))) {
            return true;
        } else if (i == -1 || j == -1) {
            return false;
        }
        if (S.charAt(i) == R.charAt(j)) {
            return matches(i - 1, j - 1, S, R);
        } else if (R.charAt(j) == '.') {
            return matches(i - 1, j - 1, S, R);

        } else if (R.charAt(j) == '*') {
            return matches(i - 1, j, S, R) || matches(i, j - 1, S, R);

        }
        return false;
    }
    public static void main(String[] args) {
        System.out.println(matches(1,3,"ba","ba*a"));
    }
}