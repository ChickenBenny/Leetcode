#include <iostream>
#include <vector>

using namespace std;

vector<int> two_sum(vector<int>& nums, int target) {
    vector<int> answer;
    for(int i = 0;i < nums.size() - 1;i ++){
        for(int j = i + 1;j < nums.size();j ++){
            if(nums[i] + nums[j] == target){
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
    }
    return{0, 0};
}

int main(){
    vector<int> v1 = {2, 7, 11, 15}, v2 = {3, 2, 4}, v3 = {3, 3};
    int t1 = 9, t2 = 6, t3 = 6;
    two_sum(v1, t1);
    two_sum(v2, t2);
    two_sum(v3, t3);
}