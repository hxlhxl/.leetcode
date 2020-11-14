/*
 * @lc app=leetcode id=416 lang=c
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start

#define N 201 /* 数组大小 */
#define T 10001 /* total可能的最大值 */

// [1,2,5]
bool canPartition(int* nums, int numsSize){
    int sum = 0, total;
    for (int i = 0; i < numsSize; i++)
        sum += nums[i];
    if (sum % 2 == 0) {
        total = sum / 2;
        // f[i][j] 表示第i个元素，在总和为j的情况下，能否满足
        int f[N][T] = {0};
        // 初始化j为0时，全部不选
        for (int i = 0; i < N; i++) {
            f[i][0] = 1;
        }
        for (int i = 1; i < numsSize+1; i++) {
            for (int j = 1; j < total+1; j++) {
                // // 不选i
                // f[i][j] = f[i-1][j]
                // // 选,就看前面i-1个数在去掉自身是否满足
                // f[i][j] = f[i-1][j - nums[i-1]];
                f[i][j] = f[i-1][j]; // [1][1] = 0
                if (j - nums[i-1] >= 0) {
                    f[i][j] = f[i-1][j] || f[i-1][j-nums[i-1]];
                }
            }
        }
        // 遍历f[i][j]，看在j为total的情况下，能否有一个满足
        // for (int i = 0; i < numsSize; i++) {
        //     if (f[i][total] = 1)
        //         return 1;
        // }
        // return 0;
        return f[numsSize][total];
    } else {
        return 0;
    }
}
// @lc code=end

