#include<iostream>
using namespace std;
void LongestSubsequence(string a, string b){
	int n,m;
	n = a.size();
	m = b.size();
	int table[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0||j==0)
				table[i][j] = 0;
			else if(a[i-1] == b[j-1]){
				table[i][j] = table[i-1][j-1] + 1;
			}
			else{
				table[i][j] = max(table[i-1][j], table[i][j-1]);
			}
		}
	}
	cout<<table[n][m]<<endl;
	int len = table[n][m];
	char subsequence[len+1];
	subsequence[len] = '\0';
	int i=n, j=m;
	while(i>0 && j>0){
		if(a[i-1]==b[j-1]){
			subsequence[len-1] = a[i-1];
			i--;
			j--;
			len--;
		}
		else if(table[i-1][j]>=table[i][j-1])
			i--;
		else
			j--;
	}
	cout<<subsequence<<endl;
	
}
int main(){
	string a, b;
	cin>>a>>b;
	LongestSubsequence(a,b);
}
