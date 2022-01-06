/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
 */

// @lc code=start
class Solution {
public:
    string modifyString(string s) {
        string t = "#" + s + "#";
        int n = s.length();
        for(int i=0;i<n;++i){
            if(s[i] == '?'){
                for(int j=0;j<3;++j){ // abc三个就足够保证前后不同了
                
                    char c = 'a' + j;
                    if(c != t[i] && c != t[i+2]){
                        s[i] = c;
                        t[i+1] = c;
                        break;
                    }
                }
            }
        }
        return s;
    }
};
// @lc code=end

