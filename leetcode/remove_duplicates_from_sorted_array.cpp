//
// Created by huanyan on 2021/8/31.
//

/*
 * 在没遇到重复数字之前，slow 和 fast 始终指向同一元素
 * 一旦出现fast == fast -1， 就说明slow停止的位置需要下一个不一样的数字进行替换，并且后面的数字需要左移，此时slow不动，fast继续寻找新的数字
 * 所以当 fast 走到最后的时候，也就是全部元素左移完成的时候
 *
 * fast == fast -1，解决左移的过程中当遇到重复元素，直接把第一个元素左移，后面的跳过，等待slow指针遇见他们的时候再让fast用后面的数字覆盖掉它
 */

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int slow = 1, fast = 1, n = nums.size();
        if (n == 0) {
            return 0;
        }
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }

    int removeDuplicates(vector<int> &nums) {
        int slow = 0, fast = 1, n = nums.size();
        if (n == 0) {
            return 0;
        }
        while (fast < n) {
            if (nums[slow] != nums[fast]) {
                nums[slow + 1] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow + 1;
    }

    int removeDuplicates(vector<int> &nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        // slow 用作寻找重复的元素， fast 用来需要新的数字去替换slow， mark标记当前最新的slow元素，如果出现重复，mark就是当前重复的元素，直接判断fast对应元素不等于mark就可以去替换slow
        int slow = 1, fast = 1, mark = nums[0], n = nums.size();
        while (fast < n) {
            if (nums[fast] != mark) {
                nums[slow] = nums[fast];
                mark = nums[slow];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};