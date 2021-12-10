//
// Created by huanyan on 2021/12/8.
//

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int l = m - 1, r = n - 1;
        for (int i = m + n - 1; i >= 0; i--) {
            if (l >= 0 && r >= 0) {
                if (nums1[l] >= nums2[r]) {
                    nums1[i] = nums1[l--];
                } else {
                    nums1[i] = nums2[r--];
                }
            } else if (l >= 0) {
                nums1[i] = nums1[l--];
            } else {
                nums1[i] = nums2[r--];
            }
        }
    }

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int l = m - 1, r = n - 1, i = m + n - 1;
        while (l >= 0 && r >= 0) {
            if (nums1[l] >= nums2[r]) {
                nums1[i--] = nums1[l--];
            } else {
                nums1[i--] = nums2[r--];
            }
        }
        while (r >= 0) {
            nums1[i--] = nums2[r--];
        }
    }
};