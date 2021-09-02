//
// Created by huanyan on 2021/8/25.
//

#include <vector>

using namespace std;

void conquer(vector<int> &nums, int begin, int mid, int end, vector<int> &cp) {
    int l = begin, r = mid + 1, i = begin;

    while (l <= mid && r <= end) {
        if (nums[l] < nums[r]) {
            cp[i] = nums[l];
            l++;
        } else {
            cp[i] = nums[r];
            r++;
        }
        i++;
    }

    while (l <= mid) {
        cp[i] = nums[l];
        l++;
        i++;
    }

    while (r <= end) {
        cp[i] = nums[r];
        r++;
        i++;
    }

    for (int j = begin; j < i; j++) {
        nums[j] = cp[j];
    }
}

void divide(vector<int> &nums, int begin, int end, vector<int> &cp) {
    if (begin >= end) {
        return;
    }
    int mid = (begin + end) / 2;
    divide(nums, begin, mid, cp);
    divide(nums, mid + 1, end, cp);
    conquer(nums, begin, mid, end, cp);
}

int main() {
    vector<int> nums = {4, 7, 1, 3, 9, 10, 6};
    vector<int> cp(nums.size());
    divide(nums, 0, nums.size() - 1, cp);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}