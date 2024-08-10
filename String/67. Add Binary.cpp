//https://leetcode.com/problems/add-binary/description/
//67. Add Binary
// TC - O(n), SC - O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        string ans = "";
        while(i >= 0 || j >= 0 || carry)
        {
            int dig1 = (i == -1) ? 0 : a[i--] - '0';
            int dig2 = (j == -1) ? 0 : b[j--] - '0';

            int sum = dig1 + dig2 + carry;
            ans += to_string(sum % 2);
            carry = sum / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
