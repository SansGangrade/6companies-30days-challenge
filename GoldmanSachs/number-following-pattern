import java.util.*;

class goldmanprblm_9{
  public static void main(String[] args) {
    try (Scanner scn = new Scanner(System.in)) {
      String str=  scn.next();
      
      String res = Solution.printMinNumberForPattern(str);
      System.out.println(res);
    }
  }
}


class Solution{
    static String printMinNumberForPattern(String S){
         Stack<Integer> st=new Stack<>();
       String ss="";
       for(int i=0;i<=S.length();i++)
       {
           st.push(i+1);
           if(i==S.length() || S.charAt(i)=='I')
           {
             while(st.size()>0)
             {
                 ss+=String.valueOf(st.pop());
             }
           }
       }
       return ss;
    }
}
