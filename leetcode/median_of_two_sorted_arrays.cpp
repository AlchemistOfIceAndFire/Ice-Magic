//
// Created by huanyan on 2021/8/11.
//

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        // length of nums1, nums1, can be used to judge even or ood.
        int m = nums1.size(), n = nums2.size();
        // if total length is even, just use the right, if not, use the left and right
        int left = -1, right = -1;
        // use i to iterate nums1, j to iterate nums2
        int i = 0, j = 0;

        // find median, so just iterate (m+n)/2 elements.
        for (int k = 0; k <= (m + n) / 2; k++) {
            left = right;
            if (i < m && (j >= n || nums1[i] < nums2[j])) {
                right = nums1[i];
                i++;
            } else {
                right = nums2[j];
                j++;
            }
        }

        return (m + n) % 2 == 0 ? (double(left) + double(right)) / 2 : right;
    }

    double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        bool even = (m + n) % 2 == 0 ? true : false;
        int i = 0, j = 0, counter = 0, answer = 0;

        while (i < m && j < n) {
            counter++;

            int num = 0;
            if (nums1[i] < nums2[j]) {
                num = nums1[i];
                i++;
            } else {
                num = nums2[j];
                j++;
            }

            if (even && counter == (m + n) / 2) {
                answer += num;
            }
            if (counter == (m + n) / 2 + 1) {
                answer += num;
                break;
            }
        }

        while (i < m) {
            counter++;
            if (even && counter == (m + n) / 2) {
                answer += nums1[i];
            }
            if (counter == (m + n) / 2 + 1) {
                answer += nums1[i];
                break;
            }
            i++;
        }

        while (j < n) {
            counter++;
            if (even && counter == (m + n) / 2) {
                answer += nums2[j];
            }
            if (counter == (m + n) / 2 + 1) {
                answer += nums2[j];
                break;
            }
            j++;
        }

        return even ? double(answer) / 2 : answer;
    }
};