//
// Created by huanyan on 2021/11/2.
//

/*
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 * O(n) solution:
 *      making dp[i] represent max sum from x to i, so dp[i] = max(dp[i-1], nums[i])
 *
 * divide and conquer:
 *      hypothesis nums arrays left board is l, right board is r, [l, r], divide it to [l, mid], [mid+1, r]
 *      in divide and conquer process, we have two problems need to solve.
 *          1. how to calculate max sum in part of divided array?
 *                  when we divide array to multiple array, once the array len is 1, this number is the max sum, so wo jump to the problem two.
 *          2. how to merge the max sum when two divided array merged?
 *                  because we need to merge two array and calculate contiguous array's items max sum, so for each sub array,
 *                  we need to maintain two sum, start at left in this array of max sum: lsum, end at right in this array of max sum: rsum,
 *                  and may be have case to across m, so we need to maintain a sum, all items in array's sum: tsum
 *
 *                  how to calculate lsum, rsum for [l, r]
 *                      lsum[l,r] = max(lsum[l,m], msum[l,m] + lsum[m+1,r])
 *                      rsum[l,r] = max(rsum[m+1,r], msum[m+1,r] + rsum[l,m])
 *
 *                  now how to calculate max contiguous items sum for [l,r]:
 *                      csum[l,r] = max(max(csum[l,m], csum[m+1,r]), rsum[l,m] + lsum[m+1,r])
 *
 *
 */

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int pre = 0, answer = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            pre = max(pre + nums[i], nums[i]);
            answer = max(answer, pre);
        }
        return answer;
    }

    struct Sums {
        int lSum, rSum, tSum, cSum;
    };

    Sums conquer(Sums &lSums, Sums &rSums) {
        return Sums{
                max(lSums.lSum, lSums.tSum + rSums.lSum),
                max(rSums.rSum, rSums.tSum + lSums.rSum),
                lSums.tSum + rSums.tSum,
                max(max(lSums.cSum, rSums.cSum), lSums.rSum + rSums.lSum),
        };
    }

    Sums divide(vector<int> &nums, int l, int r) {
        if (l == r) {
            return {nums[l], nums[l], nums[l], nums[l]};
        }
        int m = (l + r) >> 1;
        Sums lSums = divide(nums, l, m);
        Sums rSums = divide(nums, m + 1, r);
        return conquer(lSums, rSums);
    }

    int maxSubArray(vector<int> &nums) {
        int pre = 0, answer = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            pre = max(pre + nums[i], nums[i]);
            answer = max(answer, pre);
        }
        return answer;
    }
};