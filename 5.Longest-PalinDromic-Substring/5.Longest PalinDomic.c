/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 1002

char * longestPalindrome(char * s) 
{
	int longestLen = 1;
	int firstPoint = 0;
	int index = 0;
	int LastPoint = 0;
	int len = strlen(s);
	int **dp = (int**)malloc(sizeof(int*)*(len + 1));
	for (int i = 0; i <= len; i++) {
		dp[i] = (int*)malloc(sizeof(int)*(len + 1));
	}
	
	if (len == 0 || len > MAX_STR_LEN) {
		return s;
	}

	/*
	1.if s[i]=s[j]&&dp[i+1]==dp[j-1]，则dp[i][j]==1(i-j>=2)
    2.if s[i]==s[j],则dp[i][j]=1(i-j==1)
	3.dp[i][j]=1(i==j)
	*/
	for (int i = 0; i < len; ++i) {
		dp[i][i] = 1;
		for (int j = 0; j<i; ++j) {
			// 这里需要j在i后面，因为需要先判断子串再判断母串
			if (((i-j==1)&&(s[i]==s[j]))||(dp[j+1][i-1]==1&&s[i]==s[j])) {
				dp[j][i] = 1;
				if (i - j + 1 > longestLen) {
					longestLen = i - j + 1;
					firstPoint = j;
					LastPoint = i;
					//break;
				}
			}
			else {
				dp[j][i] = 0;
			}
		}
	}
	char *strOut = (char*)malloc(sizeof(char)*(longestLen + 1));
	strncpy(strOut,s+firstPoint,longestLen);
	strOut[longestLen] = '\0';
	free(dp);
	return strOut;
}

// 递归解法
int isPalinDromic(char *str,int len)
{
	if (NULL == str) {
		return -1;
	}
	if (len == 1) {
		return 1;
	}
	else if (len == 2) {
		if (str[0] == str[1]) {
			return 1;
		}else
		{
			return 0;
		}
	}
	if (str[0] == str[len - 1]) {
		// 传入子串
		return isPalinDromic(str+1, len - 2);
	}
	else {
		return 0;
	}
}

int main() {
	char *strIn = (char*)malloc(sizeof(char)*(MAX_STR_LEN + 1));
	memset(strIn, 0, sizeof(char)*(MAX_STR_LEN + 1));
	char *p = strIn;
	int longestLen = 0;
	int firstPoint = 0;
	int LastPoint = 0;
	while (scanf_s("%s", strIn,sizeof(char)*(MAX_STR_LEN + 1)) != EOF) {
		char *strOut;
		strOut = longestPalindrome(strIn);
		// 输出最长回文字符串
		int outLen = strlen(strOut);
		for (int i = 0; i <= outLen-1; i++) {
			printf("%c", strOut[i]);
			if (i == outLen - 1) {
				printf("\n");
			}
		}
		free(strOut);
	}
}