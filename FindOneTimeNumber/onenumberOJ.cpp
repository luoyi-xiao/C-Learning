#include<iostream>
#include<vector>

using namespace std;

/*class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        //vector<vector<int>> map;
        vector<vector<int>> map(100, vector<int>(2));
        for (int i = 0; i < 10000; i++)
            map[i][0] = i;
        //创建一个二维数组map 第一列为数字，第二列为出现次数
        int j;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (j = 0; j < nums.size(); ++j)
            {
                if (nums[i] == map[j][0])
                {
                    map[j][1]++;
                    break;
                }
           
            }
            if (j == map.size())
            {
                vector<int> val{ nums[i],1 };
                map.push_back(val);
            }
        }
        int result;
        for (int i = 0; i < map.size(); ++i)
        {
            if (map[i][1] == 1)
                result = map[i][0];
        }
        return result;
    }
};*/
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        vector<vector<int>> map(10000, vector<int>(2, 0));
        //创建一个二维数组map 第一列为数字，第二列为出现次数
        int j;
        for (int i = 0; i < 10000; i++)
            map[i][0] = i;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (j = 0; j < nums.size(); ++j)
            {
                if (nums[i] == map[j][0])
                {
                    map[j][1]++;
                    break;
                }

            }
            if (j == map.size())
            {
                vector<int> val{ nums[i],1 };
                map.push_back(val);
            }
        }
        int result;
        for (int i = 0; i < map.size(); ++i)
        {
            if (map[i][1] == 1)
                result = map[i][0];
        }
        return result;
    }
};

int main()
{
    int num []= { 122,22,122,22,33,44,44,6,6 };
    vector<int> nums(num, num + sizeof(num) / sizeof(int));
    Solution t1;
    int tmp = t1.singleNumber(nums);
    cout << tmp << endl;
}