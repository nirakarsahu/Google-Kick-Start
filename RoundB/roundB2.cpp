#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
const int sumtime=10010;
struct Node{
	int time;
	int engine;
	int lose;
}lnode[128];
int dp[sumtime], dp1[sumtime];
bool cmp(struct Node &x, struct Node &y)
{
	return y.time*x.lose>x.time*y.lose;
}
int main()
{
	int a, n;
	cin >>a;
	for(int c=1; c<=a; c++){
		cin >> n;
		for(int i=0; i<n; i++) cin >> lnode[i].time >> lnode[i].engine >> lnode[i].lose;
		sort(lnode,lnode+n,cmp);
		
		memset(dp,0,sizeof dp);
		memset(dp1,0,sizeof dp1);
		int time=0;
		for(int i=0; i<n; i++){
			time+=lnode[i].time;
			for(int j=0; j<=time; j++) dp1[j]=dp[j];
			for(int j=lnode[i].time; j<=time; j++){
				int engine=lnode[i].engine-(j-lnode[i].time)*lnode[i].lose;
				if(engine<=0) continue;
				dp[j]=max(dp[j],dp1[j-lnode[i].time]+engine);
			}
		}
		int result=0;
		for(int i=0; i<=time; i++) result=max(result,dp[i]);
		cout << "Case #" << c << ": " << result << endl;
	}
	return 0;
}

/*
���D��� 
���]���@�ӳ̨θ�opt
�ӦY���Y�����Ǭ�s1,s2,......,sn
�䤤si,sj�Bi<j
vi=ei-t*li+ej-(t+ti)*lj
vj=ej-t*lj+ei-(t+tj)*li
�����S��ti*lj<tj*li 
�ҥH��ti*lj���p���۹ﶶ�Ǥ@�w����e��
�����ﶶ�Ǥ��T�w->�ϥ�0/1 Knapsack 
*/
