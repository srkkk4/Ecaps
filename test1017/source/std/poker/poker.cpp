#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x;char c;bool f=false;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=true;
	x=c^48;
	while((c=getchar())>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48);
	if(f)return -x;
	return x;
}
struct Card{
	int Dt,Cl;
	Card(){Dt=Cl=-1;}
	Card(int val){
		Dt=val%13+2;
		Cl=val/13+1;
	}
	Card(int _Dt,char _Cl){
		Dt=_Dt;
		switch(_Cl){
			case 'S':Cl=1;break;
			case 'H':Cl=2;break;
			case 'C':Cl=3;break;
			case 'D':Cl=4;break;
		}
	}
	bool operator<(Card x)const{
		return Dt<x.Dt;
	}
};
struct Point{int Val,cd[5];};
int Comp(const Point &x,const Point &y){
	if(x.Val<y.Val)return -1;
	if(x.Val>y.Val)return 1;
	for(int i=0;i<5;i++){
		if(x.cd[i]<y.cd[i])return -1;
		if(x.cd[i]>y.cd[i])return 1;
	}
	return 0;
}
Point Score(Card *vr){
	int col[5],pot[15],ts[9],ds[5]={9,4,2,1,0},tt;
	Point ans;
	for(int i=1;i<=4;i++)col[i]=0;
	for(int i=2;i<=14;i++)pot[i]=0;
	for(int i=0;i<7;i++){
		col[vr[i].Cl]++;
		pot[vr[i].Dt]++;
	}
	for(int i=0;i<9;i++)
		ts[i]=-1;
	for(int i=14;i>1;i--){
		tt=ds[pot[i]];
		while(tt<9&&ts[tt]!=-1)tt++;
		if(tt<9)ts[tt]=i,ds[pot[i]]=tt+1;
		else ds[pot[i]]=9;
	}
	for(int i=1;i<=4;i++)
		if(col[i]>=5){
			for(int j=2;j<=14;j++)
				pot[j]=0;
			for(int j=0;j<7;j++)
				if(vr[j].Cl==i)
					pot[vr[j].Dt]=1;
			pot[1]=pot[14];
			for(int j=10;j>0;j--)
				if(pot[j]==1&&pot[j+1]==1&&pot[j+2]==1&&pot[j+3]==1&&pot[j+4]==1){
					ans.Val=8;
					for(int k=0;k<5;k++)
						ans.cd[k]=j+4-k;
					return ans;
				}
			tt=0;ans.Val=5;
			for(int j=14;tt<5;j--)
				if(pot[j]==1){
					ans.cd[tt]=j;
					tt++;
				}
			return ans;
		}
	if(ts[0]!=-1){
		ans.Val=7;
		for(int i=0;i<4;i++)
			ans.cd[i]=ts[0];
		ans.cd[4]=max(ts[4],max(ts[1],ts[2]));
		return ans;
	}
	if(ts[1]!=-1&&ts[2]!=-1){
		ans.Val=6;
		for(int i=0;i<3;i++)
			ans.cd[i]=ts[1];
		for(int i=3;i<5;i++)
			ans.cd[i]=ts[2];
		return ans;
	}
	for(int i=2;i<=14;i++)
		pot[i]=0;
	for(int i=0;i<7;i++)
		pot[vr[i].Dt]=1;
	pot[1]=pot[14];
	for(int i=10;i>0;i--)
		if(pot[i]==1&&pot[i+1]==1&&pot[i+2]==1&&pot[i+3]==1&&pot[i+4]==1){
			ans.Val=4;
			for(int j=0;j<5;j++)
				ans.cd[j]=i+4-j;
			return ans;
		}
	if(ts[1]!=-1){
		ans.Val=3;
		for(int i=0;i<3;i++)
			ans.cd[i]=ts[1];
		for(int i=3;i<5;i++)
			ans.cd[i]=ts[i+1];
		return ans;
	}
	if(ts[3]!=-1){
		ans.Val=2;
		ans.cd[0]=ans.cd[1]=ts[2];
		ans.cd[2]=ans.cd[3]=ts[3];
		ans.cd[4]=ts[4];
		return ans;
	}
	if(ts[2]!=-1){
		ans.Val=1;
		ans.cd[0]=ans.cd[1]=ts[3];
		for(int i=2;i<5;i++)
			ans.cd[i]=ts[i+2];
		return ans;
	}
	ans.Val=0;
	for(int i=0;i<5;i++)
		ans.cd[i]=ts[i+4];
	return ans;
}
Card readcard(){
	char c,d;
	while((c=getchar())<=32||c>=127);
	while((d=getchar())<=32||d>=127);
	if(c=='A')return Card(14,d);
	if(c=='K')return Card(13,d);
	if(c=='Q')return Card(12,d);
	if(c=='J')return Card(11,d);
	if(c=='T')return Card(10,d);
	return Card(c-48,d);
}
int number(Card x){
	return x.Cl*13+x.Dt-15;
}

const int maxn=22;
const int tmst[4]={0,3,4,5};
int n,tim;double d1,d2,ds;
Card A[maxn],B[maxn];bool vr[52];
double pre[maxn],last[maxn],pot[maxn],dc[maxn];
int ls,lv;bool fold[maxn];
int id[maxn];Point rs[maxn];double lapt[maxn];

Card x[7];Point as,ad;int mxd[maxn],mxi,wn[maxn],tot;

bool CMP1(int x,int y){
	int res=Comp(rs[x],rs[y]);
	if(res==0)return x>y;
	return (res==1);
}
void result(){
	int in=0;
	for(int i=1;i<=n;i++)
		if(!fold[i])id[++in]=i;
	if(in==1){
		for(int i=1;i<=n;i++)
			last[id[1]]+=pot[i];
		last[id[1]]+=ds;
	}
	else{
		for(int i=tmst[tim];i<5;i++)
			x[i]=readcard();
		for(int i=1;i<=n;i++)
			if(!fold[i]){
				x[5]=A[i];x[6]=B[i];
				rs[i]=Score(x);
			}
		sort(id+1,id+in+1,CMP1);
		for(int i=1;i<=in;i++)
			lapt[i]=pot[id[i]];
		for(int i=2;i<=in;i++)
			lapt[i]=max(lapt[i],lapt[i-1]);
		double lt=0,dd,pp;
		for(int i=1,ln=1;i<=in;i++,ln++)
			if(i==in||Comp(rs[id[i]],rs[id[i+1]])!=0){
				if(lapt[i]==lt)continue;
				dd=lapt[i]-lt;pp=0;lt=lapt[i];
				for(int j=1;j<=n;j++)
					if(pot[j]>dd){
						pp+=dd;
						pot[j]-=dd;
					}
					else{
						pp+=pot[j];
						pot[j]=0;
					}
				pp+=ds;ds=0;dd=pp/ln;
				for(int j=i-ln+1;j<=i;j++)
					last[id[j]]+=dd;
				ln=0;
			}
	}
	for(int i=1;i<=n;i++){
		if(pre[i]==last[i])
			printf("0.00");
		else if(pre[i]<last[i])
			printf("+%.2lf",last[i]-pre[i]);
		else
			printf("-%.2lf",pre[i]-last[i]);
		if(i==n)
			printf("\n");
		else
			printf(" ");
	}
	exit(0);
}
int Pre(int x){
	do{
		x--;
		if(x==0)x=n;
	}while(fold[x]||last[x]==0);
	return x;
}
int Next(int x){
	do{
		x++;
		if(x==n+1)x=1;
	}while(fold[x]||last[x]==0);
	return x;
}
void Bet(bool MZ){
	if(ls<2)return;
	for(int i=1;i<=n;i++)
		dc[i]=0;
	int now,la;double pss,dl=0;
	now=Next(0);
	if(MZ){
		dc[now]+=d1;pot[now]+=d1;last[now]-=d1;
		now=Next(now);
		dc[now]+=d2;pot[now]+=d2;last[now]-=d2;
		now=Next(now);
	}
	la=Pre(now);
	while(1){
		pss=read();
		if(pss==-1){
			fold[now]=true;
			ls--;lv--;
		}
		else{
			last[now]-=pss;
			pot[now]+=pss;
			dc[now]+=pss;
			if(dl<dc[now])dl=dc[now],la=Pre(now);
			if(last[now]==0)ls--;
		}
		if(lv==1)result();
		if(now==la)break;
		now=Next(now);
	}
}
void Print(){
	for(int i=1;i<=n;i++)
		if(fold[i])printf("-----%c",i==n?10:32);
		else printf("%.1lf%%%c",100.0*wn[i]/tot,i==n?10:32);
}
void Check(){
	int res;
	for(mxd[1]=1;fold[mxd[1]];mxd[1]++);
	mxi=1;x[5]=A[mxd[1]];x[6]=B[mxd[1]];as=Score(x);tot++;
	for(int r=mxd[1]+1;r<=n;r++)
		if(!fold[r]){
			x[5]=A[r];x[6]=B[r];
			ad=Score(x);res=Comp(ad,as);
			if(res==1){mxi=1;mxd[1]=r;as=ad;}
			else if(res==0)mxd[++mxi]=r;
		}
	for(int r=1;r<=mxi;r++)
		wn[mxd[r]]++;
}

void Perflop(){
	tim=0;tot=0;
	for(int i=1;i<=n;i++)
		wn[i]=0;
	for(int i=  0;i<52;i++)if(vr[i]){x[0]=Card(i);
	for(int j=i+1;j<52;j++)if(vr[j]){x[1]=Card(j);
	for(int k=j+1;k<52;k++)if(vr[k]){x[2]=Card(k);
	for(int l=k+1;l<52;l++)if(vr[l]){x[3]=Card(l);
	for(int s=l+1;s<52;s++)if(vr[s]){x[4]=Card(s);
		Check();}}}}}
	Print();Bet(true);
}
void Flop(){
	tim=1;tot=0;
	for(int i=0;i<3;i++){
		x[i]=readcard();
		vr[number(x[i])]=false;
	}
	for(int i=1;i<=n;i++)
		wn[i]=0;
	for(int i=  0;i<52;i++)if(vr[i]){x[3]=Card(i);
	for(int j=i+1;j<52;j++)if(vr[j]){x[4]=Card(j);
		Check();}}
	Print();Bet(false);
}
void Turn(){
	tim=2;tot=0;
	x[3]=readcard();
	vr[number(x[3])]=false;
	for(int i=1;i<=n;i++)
		wn[i]=0;
	for(int i=  0;i<52;i++)if(vr[i]){x[4]=Card(i);
		Check();}
	Print();Bet(false);
}
void River(){
	tim=3;tot=0;
	x[4]=readcard();
	vr[number(x[4])]=false;
	for(int i=1;i<=n;i++)
		wn[i]=0;
	Check();
	Print();Bet(false);
}

int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
	n=lv=ls=read();d1=read();d2=read();ds=read();
	for(int i=0;i<52;i++)
		vr[i]=true;
	for(int i=1;i<=n;i++){
		pre[i]=last[i]=read();pot[i]=0;
		fold[i]=false;
		A[i]=readcard();vr[number(A[i])]=false;
		B[i]=readcard();vr[number(B[i])]=false;
	}
	last[2]-=ds;
	Perflop();
	Flop();
	Turn();
	River();
	result();
}
