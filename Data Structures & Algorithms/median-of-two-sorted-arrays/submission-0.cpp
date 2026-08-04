class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2;

        if (B.size() < A.size()) {
            swap(A, B);
        }

        int l = 0;
        int r = A.size();
        while (l <= r) {
            int mid1 = (l + r) / 2;
            int mid2 = half - mid1;

            int Aleft = mid1 > 0 ? A[mid1 - 1] : INT_MIN;
            int Aright = mid1 < A.size() ? A[mid1] : INT_MAX;
            int Bleft = mid2 > 0 ? B[mid2 - 1] : INT_MIN;
            int Bright = mid2 < B.size() ? B[mid2] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 != 0) {
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright) {
                r = mid1 - 1;
            } else {
                l = mid1 + 1;
            }
        }
        return -1;
    }
};