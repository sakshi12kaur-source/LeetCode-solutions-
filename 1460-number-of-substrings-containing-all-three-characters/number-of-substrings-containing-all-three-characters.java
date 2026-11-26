class Solution {
    public int numberOfSubstrings(String s) {
        int subStringCount = 0;
        int size = s.length();
        char[] sChar = s.toCharArray();
        
        int[] aCount = new int[size];
        int[] bCount = new int[size];
        int[] cCount = new int[size];
        
        // Build prefix count arrays
        for(int i = 0; i < size; i++) {
            char c = sChar[i];
            aCount[i] = i > 0 ? (c == 'a') ? aCount[i - 1] + 1 : aCount[i - 1] : ((c == 'a') ? 1 : 0 );
            bCount[i] = i > 0 ? (c == 'b') ? bCount[i - 1] + 1 : bCount[i - 1] : ((c == 'b') ? 1 : 0 );
            cCount[i] = i > 0 ? (c == 'c') ? cCount[i - 1] + 1 : cCount[i - 1] : ((c == 'c') ? 1 : 0 );
        }
        
        // Iterate over all starting indices
        for(int i = 0, j = i + 2; i < size; i++) {
            for(; j < size; j++) {
                if(i == 0) {
                    if(aCount[j] > 0 && bCount[j] > 0 && cCount[j] > 0){
                        subStringCount += size - j;
                        break;
                    }
                } else {
                    if(aCount[j] - aCount[i-1] > 0 && 
                       bCount[j] - bCount[i-1] > 0 && 
                       cCount[j] - cCount[i-1] > 0){
                        subStringCount += size - j;
                        break;
                    }
                }
            }
        }
        return subStringCount;
    }
}