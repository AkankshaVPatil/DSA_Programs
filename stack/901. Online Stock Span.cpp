//https://leetcode.com/problems/online-stock-span/description/
//901. Online Stock Span
//TC - O(1), SC - O(n)

class StockSpanner {
public:
    stack<pair<int, int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty())
        {
            st.push({price, 1});
            return 1;
        }
        else
        {
            long counter = 1;
            while(!st.empty() && price >= st.top().first)
            {  
                counter += st.top().second;
                st.pop();
            }
            st.push({price, counter});
            return counter;
        }       
    }
};
