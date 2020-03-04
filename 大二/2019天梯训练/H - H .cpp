#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct nod{
	double tim,opt;
}a[10010];
int cmp(nod a,nod b) {
	return a.tim<b.tim;
}
int main(){
	int t,n,i,j,cas=0;
	scanf("%d",&t);
	while(t--){
		cas++;
		scanf("%d",&n);
		for(i=0;i<n;++i){
			scanf("%lf%lf",&a[i].tim,&a[i].opt);
		}
		sort(a,a+n,cmp);
		double maxn=0,u;
		for(i=1;i<n;++i){
			maxn = max(maxn,fabs((a[i].opt-a[i-1].opt)/(a[i].tim-a[i-1].tim))) ;
		}
		printf("Case #%d: %.2lf\n",cas,maxn);
	}
	return 0;
}
