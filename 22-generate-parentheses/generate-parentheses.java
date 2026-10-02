class Solution {


    public void generateParathesisString(String res, int n, List<String> allCombinations,int open, int close)
    {
        if(n==0)
        {
            if(open!=close)
                {
                    for(int i=close; i<open; i++)
                    {
                        res+=")";
                    }
                }

            allCombinations.add(res);
            return;
        }
        if(n>=1)
        {
            //case 1: open another
            generateParathesisString(res+"(", n-1, allCombinations, open+1, close);

            //case 2:only close
            if(close<open)
            {
                 generateParathesisString(res+")", n, allCombinations, open, close+1);
            }
            
        }
    }
    public List<String> generateParenthesis(int n) {
        List<String> allCombinations= new ArrayList<>();
        generateParathesisString("",n,allCombinations, 0, 0);

        return allCombinations;
    }
}