//
// Created by huanyan on 2021/8/25.
//

int conquer(vector<int> &nums, int l, int r) {
    base = r;
    r--;

    while (l < r) {
        while (l < r && nums[l] < nums[base]) {
            l++;
        }
        while (l < r && nums[r] > nums[base]) {
            r--;
        }
        swap(nums[l], nums[r]);
    }
    swap(num[r], nums[base]);
    return base;
}

void divide(vector<int> &nums, int l, int r) {
    if (l >= r) {
        return;
    }
    int base = conquer(nums, l, r);
    divide(nums, l, base - 1);
    divide(nums, base + 1, r);
}