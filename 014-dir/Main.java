
public class Main {
    public static void main(String args[]) {
        String string = "aaa456ac";  
        //查找指定字符是在字符串中的下标。在则返回所在字符串下标；不在则返回-1.  
        System.out.println(string.indexOf("b456")); // indexOf(String str); 返回结果：-1，"b"不存在  
        String[] test = {"abc", "abeee", "ab"}; 
        System.out.println(longestCommonPrefix(test));

    }
    public static String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        String prefix = strs[0];
        System.out.println("prefix " + prefix);
        for (int i = 1; i < strs.length; i++)
            while (strs[i].indexOf(prefix) != 0) {
                System.out.println("stri" + strs[i] +" index "+ prefix+" value:" + strs[i].indexOf(prefix));
                prefix = prefix.substring(0, prefix.length() - 1);
                if (prefix.isEmpty()) return "";
            }        
        return prefix;
    }
}
