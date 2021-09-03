class Solution {

    public static int compress(char[] chars) 
    {
        int anchor = 0, write = 0;
        for (int read = 0; read < chars.length; read++)
        {
            if (read + 1 == chars.length || chars[read + 1] != chars[read]) 
            {
                chars[write++] = chars[anchor];
                if (read > anchor) 
                {
                    for (char c: ("" + (read - anchor + 1)).toCharArray()) 
                    {
                        chars[write++] = c;
                    }
                }
                anchor = read + 1;
            }
        }
        for(int i=0;i<chars.length;i++)
        {
            System.out.print(chars[i]);
        }
        System.out.println("");
        return write;
    }

    public static void main(String args[])
    {
        char[] ch = ['a', 'a', 'b', 'b', 'c', 'd', 'e'];
        compress(ch);
        
    }

}