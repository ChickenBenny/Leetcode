#include <iostream>
#include <vector>
#include <map>

using namespace std;

void two_sum(vector<int>& nums, int target) {
    vector<int> answer;
    map<int, int> diff;
    map<int, int>::iterator iter;
    for(int i = 0;i < nums.size();i ++){
        iter = diff.find(target - nums[i]);
        if(iter != diff.end()){
            answer.push_back(iter->second);
            answer.push_back(i);
        }
        else{
            diff[nums[i]] = i;
        }
    }
    cout << answer[0] << " " << answer[1] << endl;
}

int main(){
    vector<int> v1 = {2, 7, 11, 15}, v2 = {3, 2, 4}, v3 = {3, 3};
    int t1 = 9, t2 = 6, t3 = 6;
    two_sum(v1, t1);
    two_sum(v2, t2);
    two_sum(v3, t3);
}