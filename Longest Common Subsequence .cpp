class Solution {
public:
    int t[1001][1001];
    int lcs1(string &s1,string &s2,int n,int m){
        if(n==0 || m==0) return 0;
        if(t[n][m]!=-1) return t[n][m];
        if(s1[n-1]==s2[m-1]){
            return t[n][m]=1+lcs1(s1,s2,n-1,m-1);
        }
        else{
            return t[n][m]=max(lcs1(s1,s2,n-1,m),lcs1(s1,s2,n,m-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        memset(t,-1,sizeof(t));
        return lcs1(text1,text2,n,m);

    }
};
