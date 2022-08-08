#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        for(int i = 0;i <= nums.size() - 3;i++){
            if(binary_search(nums.begin()+i,nums.end(),nums[i]+diff)){
                if(binary_search(nums.begin()+i,nums.end(),nums[i]+diff*2))
                   ans++;
            }
        }
                   
        return ans;
    }
};
int main(){
    return 0;
}