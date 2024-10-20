class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 比较版本号
     * @param version1 string字符串
     * @param version2 string字符串
     * @return int整型
     */
    vector<int> splitAndConvert(const string& version) {
        vector<int> res;
        int n = version.size();
        int num = 0;

        for (int i = 0; i < n; ++i) {
            if (version[i] == '.') {
                res.push_back(num); // 遇到"."时，将当前修订号加入结果数组
                num = 0; // 重置num，用于记录下一个修订号
            } else {
                num = num * 10 + (version[i] -
                                  '0'); // 计算当前修订号，去掉前导0的效果
            }
        }
        res.push_back(num); // 最后一个修订号加入结果数组
        return res;
    }

    int compare(string version1, string version2) {
        // write code here
        vector<int> v1 = splitAndConvert(version1);
        vector<int> v2 = splitAndConvert(version2);

        int len1 = v1.size();
        int len2 = v2.size();
        int maxLen = max(len1, len2); // 找出两个版本号中较长的长度

        // 比较两个版本号的每个修订号
        for (int i = 0; i < maxLen; ++i) {
            int num1 = (i < len1) ? v1[i] : 0; // 如果v1的修订号不足，补0
            int num2 = (i < len2) ? v2[i] : 0; // 如果v2的修订号不足，补0
            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
        }

        return 0; // 如果所有修订号都相等，返回0
    }
};