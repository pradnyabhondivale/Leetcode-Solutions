class Solution {
public:
    int mergeSort(vector<int>& nums, int left, int right)
    {
        if(left>=right)
            return 0;

        int pairs = 0;
        int mid = left+(right-left)/2;

        pairs += mergeSort(nums, left, mid);
        pairs += mergeSort(nums, mid+1, right);
        pairs += countPairs(nums, left, mid, right);

        merge(nums,left,mid,right);

        return pairs;
    }

    int countPairs(vector<int>& nums, int left, int mid, int right)
    {
        int cnt=0;
        int rightPointer = mid+1;

        for(int i=left;i<=mid;i++)
        {
            long long leftPointer = nums[i];
            while(rightPointer <= right && leftPointer > 2LL*nums[rightPointer])
            {
                rightPointer++;
            }

            cnt += (rightPointer - (mid+1));
        }

        return cnt;
    }

    void merge(vector<int>& nums, int left, int mid, int right)
    {
        vector<int> temp;
        int low = left, high=mid+1;

        while(low<=mid && high<=right)
        {
            if(nums[low]<=nums[high])
            {
                temp.push_back(nums[low]);
                low++;
            }
            else
            {
                temp.push_back(nums[high]);
                high++;
            }
        }

        while(low<=mid)
        {
            temp.push_back(nums[low]);
            low++;
        }

        while(high<=right)
        {
            temp.push_back(nums[high]);
            high++;
        }

        for(int i=0;i<temp.size();i++)
        {
            nums[left + i] = temp[i];
        }
    }

    int reversePairs(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        
        return mergeSort(nums,0,nums.size()-1);
    }
};