class Solution {
public:   
    int max (int a , int b  )  {   
        if (a > b) {
            return a ;  
        }   
        return  b  ;  
    }
    int  produit (vector<int>& arr) {        
            int length = static_cast<int>(arr.size());      
            if (length <=  0 ) {   
                return 0 ;  
            }
            long long  result =  arr[0] ;     
            for (int i =1  ; i <  length  ; i++) {   
                result*= arr[i];  
            }   
            return  result ;  
        }
    int lcmoftwo (int a , int b)  {  
            if (a == 0 || b == 0)  {   
                return 0 ;  
            }
            /*int result = max(a ,b) ;      
            while(result % a != 0  ||  result % b !=  0)  {   
                result += max(a , b) ; 
            } */  
            long long g = gcdoftwo(static_cast<int>(a), static_cast<int>(b));
            return (a / g) * b;  
        }   

        int lcmList (const vector<int>& arr) {   
            long length = static_cast<int>(arr.size());   
            long long res = arr[0] ;      
            for  (int i = 0;  i  <  length ; i++)  {   
                res = lcmoftwo(res, arr[i]);  
            }
            return res ;  
        }
    int gcdoftwo  (int a ,  int  b )  {    
            if (a == 0 ) {   
                return b  ;  
            }    
            return gcdoftwo(b % a, a) ;   
        }    
    int  gcdofarray(const vector<int>& arr) {    
            int length = static_cast<int>(arr.size());    
            if  (length  == 0 ) {   
                return  0 ; 
            }      
            int res = arr[0] ;  
            for (int i = 1 ;  i  <  length ; i++) {      
                res = gcdoftwo(res , arr[i]) ;  
                if  (res  == 1) {   
                    return  1 ; 
                } 
            }   
            return  res ;  
        }
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        long long totalLcm = lcmList(nums);
        int maxNum = nums[0];
        for (int i = 1; i < n; i++) {
            maxNum = max(maxNum, nums[i]);
        }
        long long bound = totalLcm * maxNum;

        int best = 0;
        for (int i = 0; i < n; i++) {
            vector<int> sub;
            for (int j = i; j < n; j++) {
                sub.push_back(nums[j]);
                long long result_3 = produit(sub);
                if (result_3 > bound) {
                    break;
                }
                long long result_1 = lcmList(sub);
                long long result_2 = gcdofarray(sub);

                if (result_3 == result_1 * result_2) {
                    best = max(best, j - i + 1);
                }
            }
        }
        return best;
    }
};   