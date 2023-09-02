//Ð¡À¶ÓëÔ¿³×
/*#include<stdio.h>
long long Factorial(long long x)
{
	long long sum=1;
	while(x)
	{
		sum*=x;
		x--;
	}
	return sum;
}
long long cnm(long long n,long long m){
    if(n==1) return m;
    return m*cnm(n-1, m-1)/n;
}
long long cuopai(int n)
{
	if(n%2==0)

	
	return (cuopai(n)+cuopai(n-1));
}
int main()
{
	long long m=14,i,j=1,k,sum=Factorial(14);
	k=cnm(28,14);
	for(i=1;i<=m;i++)
	{
		if(j%2==0)
			sum+=Factorial(14)/Factorial(j);
		else
			sum-=Factorial(14)/Factorial(j);
		j++;
	}
	printf("%lld",k);
	return 0;
}*/
#include <stdio.h>

const int N = 16;
long long dp[N];
int main() {
    long long ans = 1;
    int ct = 2;
    for (int i = 15; i <= 28; i++) {
        ans = ans * i;
        while (ans % ct == 0 && ct <= 14)
            ans /= ct, ct++;
    }
    dp[2] = 1, dp[3] = 2;
    for (int i = 3; i <= 14; i++)
        dp[i] = 1ll * (i - 1) * (dp[i - 1] + dp[i - 2]);
   printf("%lld", ans * dp[14]); 
    return 0;
}
