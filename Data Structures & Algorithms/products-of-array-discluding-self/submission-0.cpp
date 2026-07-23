#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> op;
        int mul = 1, c = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (c == 0) {
                    c++;
                    continue;
                }
                if (c == 1) {
                    mul = 0;
                    break;
                }
            }
            mul *= nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {

            // more than one zero
            if (mul == 0) {
                op.push_back(0);
            }

            // exactly one zero
            else if (nums[i] == 0 && c == 1) {
                op.push_back(mul);
            }

            // non-zero positions when one zero exists
            else if (c == 1) {
                op.push_back(0);
            }

            // no zero
            else {
                op.push_back(mul / nums[i]);
            }
        }

        return op;
    }
};