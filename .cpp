class Solution {
public:
    void solve ( vector <string> &ans , int n , int open , int close , string output )
    {
        // base case 
        if ( open == 0 && close == 0 )
        {
            ans.push_back(output) ;
            return ;
        }

        // include open bracket 
        // condition --> opening bracket != 0 , that's it .

        if (open>0) 
        {   
            output.push_back ('(') ;
            solve ( ans , n , open - 1 , close , output ) ;
            output.pop_back () ;
        } 

        // include closed bracket 
        // condition --> opening bracket must be present and also opening bracket   should be greater than count of closing bracket

        if (open<close)
        {   
            output.push_back (')') ;
            solve ( ans , n , open , close - 1 , output ) ;
            // backtracking 
            output.pop_back() ;
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans ;
        int open = n ;
        int close = n ;
        string output = "" ;
        solve ( ans , n , open , close , output );
        return ans ;
    }
};
