    class Solution {
    public:
        bool canReach(vector<int>& nums, int start){
            int n=nums.size();
            vector<bool>vis(n,false);
            deque<int>dq;
            dq.push_back(start);
            while(!dq.empty()){

                int index=dq.front();
                dq.pop_front();
                if(nums[index]==0) return true;
                int left=index-nums[index];
                int right= index+nums[index];
                if(left>=0 && !vis[left]){
                    vis[left] = true;
                    dq.push_back(left);
                }

                if (right < n && !vis[right]){
                    vis[right] = true;
                    dq.push_back(right);
                }
                    
                

                
                
            }
            return false;
            
            
            
        }
    };
    // leetcode question -:1306