class Solution {
    public String discountPrices(String sentence, int discount) {
        StringBuffer ans = new StringBuffer();
        String[] words = sentence.split(" ");
        for (int i = 0; i < words.length; i++) {
            Double val = isPrice(words[i]);
            if (val != -1.0) {
                val -= val * discount / 100;
                words[i] = '$' + String.format("%.2f", val);
            }
            ans.append(words[i]);
        }
        return ans.toString();
    }

    Double isPrice(String word) {
        Double val = -1.0;
        if (word.charAt(0) == '$') {
            try {
                val = Double.parseDouble(word.substring(1));
            } catch (NumberFormatException exception) {

            }
        }
        return val;
    }
}

public class p2288 {
    public static void main(String[] args) {

    }
}