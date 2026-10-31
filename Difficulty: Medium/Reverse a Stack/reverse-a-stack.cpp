class Solution {
  public:
    void reverseStack(stack<int> &st) {
        vector<int> v;
        while(!st.empty()){
        v.push_back(st.top());
        st.pop();
        }
        for(int x :v){
            st.push(x);
        }
         
    }
};