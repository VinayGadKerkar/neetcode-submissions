class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2)
            return findMedianSortedArrays(nums2 , nums1);
        int total = n1 + n2;
        int half = (total + 1) / 2;
        int l = 0;
        int r = n1;
        while(l <= r){
            int mid1 = (l + r) / 2;
            int mid2 = half - mid1;
            
            int l1 = mid1 > 0 ? nums1[mid1 - 1] : INT_MIN;
            int l2 = mid2 > 0 ? nums2[mid2 - 1] : INT_MIN;
            int r1 = mid1 < n1 ? nums1[mid1] : INT_MAX;
            int r2 = mid2 < n2 ? nums2[mid2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1){
                if(total & 1){
                    return max(l1 , l2);
                }else{
                    return (max(l1 , l2) + min(r1 , r2)) / 2.0;
                }
            }else if(l1 > r2){
                r = mid1 - 1;
            }else{
                l = mid1 + 1;
            }
        }
        return -1;
    }
};
