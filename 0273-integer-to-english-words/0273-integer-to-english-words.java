import java.util.HashMap;
import java.util.Map;

class Solution {
    public StringBuilder sb = new StringBuilder();
    public Map<Integer, String> mp = new HashMap<>();

    public void adding(Map<Integer, String> mp) {
        mp.put(0, "Zero");
        mp.put(1, "One");
        mp.put(2, "Two");
        mp.put(3, "Three");
        mp.put(4, "Four");
        mp.put(5, "Five");
        mp.put(6, "Six");
        mp.put(7, "Seven");
        mp.put(8, "Eight");
        mp.put(9, "Nine");
        mp.put(10, "Ten");
        mp.put(11, "Eleven");
        mp.put(12, "Twelve");
        mp.put(13, "Thirteen");
        mp.put(14, "Fourteen");
        mp.put(15, "Fifteen");
        mp.put(16, "Sixteen");
        mp.put(17, "Seventeen");
        mp.put(18, "Eighteen");
        mp.put(19, "Nineteen");
        mp.put(20, "Twenty");
        mp.put(30, "Thirty");
        mp.put(40, "Forty");
        mp.put(50, "Fifty");
        mp.put(60, "Sixty");
        mp.put(70, "Seventy");
        mp.put(80, "Eighty");
        mp.put(90, "Ninety");
        mp.put(100, "Hundred");
        mp.put(1000, "Thousand");
        mp.put(1000000, "Million");
        mp.put(1000000000, "Billion");
    }

    private void appendWithSpace(String word) {
        if (sb.length() > 0) {
            sb.append(" ");
        }
        sb.append(word);
    }

    public void forOnes(int num) {
        String val = mp.get(num);
        if (val != null) {
            appendWithSpace(val);
        }
    }

    public void forTens(int num) {
        if (num < 20) {
            forOnes(num);
            return;
        }
        int tens = (num / 10) * 10;
        int ones = num % 10;

        String tensVal = mp.get(tens);
        if (tensVal != null) {
            appendWithSpace(tensVal);
        }
        if (ones != 0) {
            forOnes(ones);
        }
    }

    public void forHundreds(int num) {
        int hundreds = num / 100;
        int remaining = num % 100;

        if (hundreds > 0) {
            forOnes(hundreds);
            appendWithSpace(mp.get(100));
        }
        if (remaining > 0) {
            forTens(remaining);
        }
    }

    public void forThousands(int num) {
        int thousands = num / 1000;
        int remaining = num % 1000;

        if (thousands > 0) {
            forHundreds(thousands);
            appendWithSpace(mp.get(1000));
        }
        if (remaining > 0) {
            forHundreds(remaining);
        }
    }

    public void forMillions(int num) {
        int millions = num / 1000000;
        int remaining = num % 1000000;

        if (millions > 0) {
            forHundreds(millions);
            appendWithSpace(mp.get(1000000));
        }
        if (remaining > 0) {
            forThousands(remaining);
        }
    }

    public void forBillions(int num) {
        int billions = num / 1000000000;
        int remaining = num % 1000000000;

        if (billions > 0) {
            forHundreds(billions);
            appendWithSpace(mp.get(1000000000));
        }
        if (remaining > 0) {
            forMillions(remaining);
        }
    }

    public String numberToWords(int num) {
        sb.setLength(0); // Reset the StringBuilder
        adding(mp);

        if (num == 0) {
            return mp.get(0);
        }

        if (num < 100) {
            forTens(num);
        } else if (num < 1000) {
            forHundreds(num);
        } else if (num < 1000000) {
            forThousands(num);
        } else if (num < 1000000000) {
            forMillions(num);
        } else {
            forBillions(num);
        }

        return sb.toString().trim();
    }
}