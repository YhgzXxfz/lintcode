// O(NlogN), O(1)
class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        sort(colors.begin(), colors.end());
    }
};

// O(N), O(N)
class SortColorsII {
public:
	void sortColors(vector<int>& nums, int k) {
		vector<int> colors(k, 0);
		for (auto num : nums) {
			++colors[num-1];
		}

		int left = 0;
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < colors[i]; ++j) {
				nums[left++] = i+1;
			}
		}
	}
};

// O(N*k), O(1)
class SortColorsII {
public:
	void sortColors(vector<int>& nums, int k) {
		int min_num = 1, max_num = k;
		int left = 0, right = nums.size()-1, i = 0;
		while (min_num < max_num) {
			while (i <= right) {
				if (nums[i] == min_num) swap(nums[left++], nums[i++]);
	    		else if (nums[i] == max_num) swap(nums[i], nums[right--]);
	    		else ++i;
			}
			i = left;
			++min_num; --max_num;
		}
	}
};

// O(Nlogk), O(1)
class SortColorsII {
public:
	void sortColors(vector<int>& nums, int k) {
		int len = nums.size();
		if (len <= 1) return ;

		dfs(nums, 0, len-1, 1, k);
	}

private:
	void dfs(vector<int>& nums, int left, int right, int min_num, int max_num) {
		if (min_num >= max_num) return ;
		if (left >= right) return ;

		int mid = min_num + (max_num-min_num) /2;
		int l = left, r = right;
		while (l <= r) {
			while (l <= r && nums[l] <= mid) ++l;
			while (r >= l && nums[r] > mid) --r;

			if (l <= r) {
				swap(nums[l++], nums[r--]);
			}
		}

		dfs(nums, left, r, min_num, mid);
		dfs(nums, l, right, mid+1, max_num);
	}
};
