#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct process
{
	char name[5];
	int bt;
	int at;
	int prt;
	int wt,ta;
	int flag;
} processes;




void b_sort(processes temp[],int n)
{
	processes t;
	int i,j;
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
		{
			if(temp[j].at > temp[j+1].at)
			{
				t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
		}
}




void bt_sort(processes temp[],int n)
{
	processes t;
	int i,j;
	for(i=1;i<n;i++)
	for(j=0;j<n-i;j++)
	{
		if(temp[j].bt > temp[j+1].bt)
		{
			t = temp[j];
			temp[j] = temp[j+1];
			temp[j+1] = t;
		}
	}
}




int accept(processes P[])
{
	int i,n;
	printf("\n Enter total no. of processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n PROCESS [%d]",i+1);
		printf(" Enter process name : ");
		scanf("%s",&P[i].name);
		printf(" Enter burst time : ");
		scanf("%d",&P[i].bt);
		printf(" Enter arrival time : ");
		scanf("%d",&P[i].at);
		printf(" Enter priority : ");
		scanf("%d",&P[i].prt);
	}
	printf("\n PROC.\tB.T.\tA.T.\tPRIORITY");
	for(i=0;i<n;i++)
		printf("\n %s\t%d\t%d\t%d",P[i].name,P[i].bt,P[i].at,P[i].prt);
	return n;
}




// FCFS
void FCFS(processes P[],int n)
{
	printf("\n\t\t\t\t\tFCFS ALGORITHM\n");
	processes temp[10];
	int sumw=0,sumt=0;
	int x = 0;
	float avgwt=0.0,avgta=0.0;
	int i,j;
	for(i=0;i<n;i++)
		temp[i]=P[i];
	b_sort(temp,n);
	printf("\n\n PROC.\tB.T.\tA.T.");
	for(i=0;i<n;i++)
		printf("\n %s\t%d\t%d",temp[i].name,temp[i].bt,temp[i].at);
	sumw = temp[0].wt = 0;
	sumt = temp[0].ta = temp[0].bt - temp[0].at;
	for(i=1;i<n;i++)
	{
		temp[i].wt = (temp[i-1].bt + temp[i-1].at + temp[i-1].wt) - temp[i].at;;
		temp[i].ta = (temp[i].wt + temp[i].bt);
		sumw+=temp[i].wt;
		sumt+=temp[i].ta;
	}
	avgwt = (float)sumw/n;
	avgta = (float)sumt/n;
	printf("\n\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
	for(i=0;i<n;i++)
		printf("\n %s\t%d\t%d\t%d\t%d",temp[i].name,temp[i].bt,temp[i].at,temp[i].wt,temp[i].ta);
	printf("\n\n GANTT CHART\n ");
	for(i=0;i<n;i++)
		printf(" %s ",temp[i].name);
	printf("\n ");
	printf("0\t");
	for(i=1;i<=n;i++)
	{
		x+=temp[i-1].bt;
		printf("%d ",x);
	}
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}



//SJF NON PRE-EMPTIVE
void SJF_NP(processes P[],int n)
{
	printf("\n\t\t\t\t\tSJF Non Pre-emptive\n");
	processes temp[10];
	processes t;
	int sumw=0,sumt=0;
	int x = 0;
	float avgwt=0.0,avgta=0.0;
	int i,j;
	for(i=0;i<n;i++)
		temp[i]=P[i];
	b_sort(temp,n);
	for(i=2;i<n;i++)
		for(j=1;j<n-i+1;j++)
		{
			if(temp[j].bt > temp[j+1].bt)
			{
				t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
		}
	printf("\n\n PROC.\tB.T.\tA.T.");
	for(i=0;i<n;i++)
		printf("\n %s\t%d\t%d",temp[i].name,temp[i].bt,temp[i].at);
	sumw = temp[0].wt = 0;
	sumt = temp[0].ta = temp[0].bt - temp[0].at;
	for(i=1;i<n;i++)
	{
		temp[i].wt = (temp[i-1].bt + temp[i-1].at + temp[i-1].wt) - temp[i].at;;
		temp[i].ta = (temp[i].wt + temp[i].bt);
		sumw+=temp[i].wt;
		sumt+=temp[i].ta;
	}
	avgwt = (float)sumw/n;
	avgta = (float)sumt/n;
	printf("\n\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
	for(i=0;i<n;i++)
		printf("\n %s\t%d\t%d\t%d\t%d",temp[i].name,temp[i].bt,temp[i].at,temp[i].wt,temp[i].ta);
	printf("\n\n GANTT CHART\n ");
	for(i=0;i<n;i++)
		printf(" %s ",temp[i].name);
	printf("\n ");
	printf("0\t");
	for(i=1;i<=n;i++)
	{
		x+=temp[i-1].bt;
		printf("%d ",x);
	}
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}




//PRIORITY NON PRE-EMPTIVE
void PRT_NP(processes P[],int n)
{
	printf("\n\t\t\t\t\tPRIORITY Non Pre-emptive\n");
	processes temp[10];

	processes t;
	int sumw=0,sumt=0;
	float avgwt=0.0,avgta=0.0;
	int i,j;
	int x = 0;
	for(i=0;i<n;i++)
		temp[i]=P[i];
	b_sort(temp,n);
	for(i=2;i<n;i++)
		for(j=1;j<n-i+1;j++)
		{
			if(temp[j].prt > temp[j+1].prt)
			{
				t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
		}
	printf("\n\n PROC.\tB.T.\tA.T.");
	for(i=0;i<n;i++)
		printf("\n %s\t%d\t%d",temp[i].name,temp[i].bt,temp[i].at);
	sumw = temp[0].wt = 0;
	sumt = temp[0].ta = temp[0].bt - temp[0].at;
	for(i=1;i<n;i++)
	{
		temp[i].wt = (temp[i-1].bt + temp[i-1].at + temp[i-1].wt) - temp[i].at;;
		temp[i].ta = (temp[i].wt + temp[i].bt);
		sumw+=temp[i].wt;
		sumt+=temp[i].ta;
	}
	avgwt = (float)sumw/n;
	avgta = (float)sumt/n;
	printf("\n\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
	for(i=0;i<n;i++)
		printf("\n %s\t%d\t%d\t%d\t%d",temp[i].name,temp[i].bt,temp[i].at,temp[i].wt,temp[i].ta);
	printf("\n\n GANTT CHART\n ");
	for(i=0;i<n;i++)
		printf(" %s ",temp[i].name);
	printf("\n ");
	printf("0\t");

	for(i=1;i<=n;i++)
	{
		x+=temp[i-1].bt;
		printf("%d ",x);
	}
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}






//ROUND ROBIN SCHEDULING
void RR(processes P[],int n)
{
	printf("\n\t\t\t\t\tROUND ROBIN\n");
	int pflag=0,t,tcurr=0,k,i,Q=0;
	int sumw=0,sumt=0;
	float avgwt=0.0,avgta=0.0;
	processes temp1[10],temp2[10];
	for(i=0;i<n;i++)
		temp1[i]=P[i];
	b_sort(temp1,n);
	for(i=0;i<n;i++)
		temp2[i]=temp1[i];
	printf("\n Enter quantum time : ");
	scanf("%d",&Q);
	for(k=0;;k++)
	{
		if(k>n-1)
		k=0;
		if(temp1[k].bt>0)
			printf(" %d %s",tcurr,temp1[k].name);
		t=0;
		while(t<Q && temp1[k].bt > 0)
		{
			t++;
			tcurr++;
			temp1[k].bt--;
		}
		if(temp1[k].bt <= 0 && temp1[k].flag != 1)
		{
			temp1[k].wt = tcurr - temp2[k].bt - temp1[k].at;
			temp1[k].ta = tcurr - temp1[k].at;
			pflag++;
			temp1[k].flag = 1;
			sumw+=temp1[k].wt;
			sumt+=temp1[k].ta;
		}

		if(pflag == n)
			break;
	}
	printf(" %d",tcurr);
	avgwt = (float)sumw/n;
	avgta = (float)sumt/n;
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}





//COMPARING PROCESS 1
void CP1(processes P[],int n)
{
	printf("\n\t\t\t\t\tCOMPARING PROCESS 1\n");
	int pflag=0,t,tcurr=0,k,i,Q=0;
	int sumw=0,sumt=0;
	float avgwt=0.0,avgta=0.0;
	processes temp1[10],temp2[10];
	for(i=0;i<n;i++)
		temp1[i]=P[i];
	b_sort(temp1,n);
	for(i=0;i<n;i++)
		temp2[i]=temp1[i];
	printf("\n Enter quantum time : ");
	scanf("%d",&Q);
	for(k=0;;k++)
	{
		Q = Q*2;
		if(k>n-1)
			k=0;
		if(temp1[k].bt>0)
			printf(" %d %s",tcurr,temp1[k].name);
		t=0;
		while(t<Q && temp1[k].bt > 0)
		{
			t++;
			tcurr++;
			temp1[k].bt--;
		}
		if(temp1[k].bt <= 0 && temp1[k].flag != 1)
		{
			temp1[k].wt = tcurr - temp2[k].bt - temp1[k].at;
			temp1[k].ta = tcurr - temp1[k].at;
			pflag++;
			temp1[k].flag = 1;
	
			sumw+=temp1[k].wt;
			sumt+=temp1[k].ta;
		}
		if(pflag == n)
			break;
	}
	
	printf(" %d",tcurr);
	avgwt = (float)sumw/n;
	avgta = (float)sumt/n;
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}





//COMPARING PROCESS 2 (RR WITH SJF)
void CP2(processes P[],int n)
{
	printf("\n\t\t\t\t\tCOMPARING PROCESS 2\n");
	int pflag=0,t,tcurr=0,k,i,Q=0;
	int sumw=0,sumt=0;
	float avgwt=0.0,avgta=0.0;
	processes temp1[10],temp2[10];
	for(i=0;i<n;i++)
		temp1[i]=P[i];
	b_sort(temp1,n);
	for(i=0;i<n;i++)
		temp2[i]=temp1[i];
	printf("\n Enter quantum time : ");
	scanf("%d",&Q);
	for(k=0;;k++)
	{
		if(k==1)
		{
			if(k>n-1)
				k=0;
			if(temp1[k].bt>0)
				printf(" %d %s",tcurr,temp1[k].name);
			t=0;
			while(t<Q && temp1[k].bt > 0)
			{
				t++;
				tcurr++;
				temp1[k].bt--;
			}
			if(temp1[k].bt <= 0 && temp1[k].flag != 1)
			{
				temp1[k].wt = tcurr - temp2[k].bt - temp1[k].at;
				temp1[k].ta = tcurr - temp1[k].at;
				pflag++;
				temp1[k].flag = 1;
				sumw+=temp1[k].wt;
				sumt+=temp1[k].ta;
			}
			if(pflag == n)
				break;
		}
		else
		{
			bt_sort(temp1,n);
			if(k>n-1)
				k=0;
			if(temp1[k].bt>0)
				printf(" %d %s",tcurr,temp1[k].name);
			t=0;
			while(t<Q && temp1[k].bt > 0)
			{
				t++;
				tcurr++;
				temp1[k].bt--;
			}
			if(temp1[k].bt <= 0 && temp1[k].flag != 1)
			{
				temp1[k].wt = tcurr - temp2[k].bt - temp1[k].at;
				temp1[k].ta = tcurr - temp1[k].at;
				pflag++;
				temp1[k].flag = 1;
				sumw+=temp1[k].wt;
				sumt+=temp1[k].ta;
			}
			if(pflag == n)
				break;
		}
	}
	printf(" %d",tcurr);
	avgwt = (float)sumw/n;
	avgta = (float)sumt/n;
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}




//SHORTEST JOB FIRST - PRE-EMPTIVE
void SJF_P(processes P[],int n)
{
	printf("\n\t\t\t\t\tShortest Job First - Pre-emptive\n");
	int i,t_total=0,tcurr,b[10],min_at,j,x,min_bt;
	int sumw=0,sumt=0;
	float avgwt=0.0,avgta=0.0;
	processes temp[10],t;
	for(i=0;i<n;i++)
	{
		temp[i]=P[i];
		t_total+=P[i].bt;
	}
	b_sort(temp,n);
	for(i=0;i<n;i++)
		b[i] = temp[i].bt;
	i=j=0;
	printf("\n GANTT CHART\n\n %d %s",i,temp[i].name);
	for(tcurr=0;tcurr<t_total;tcurr++)
	{
		if(b[i] > 0 && temp[i].at <= tcurr)
		b[i]--;
		if(i!=j)
			printf(" %d %s",tcurr,temp[i].name);
		if(b[i]<=0 && temp[i].flag != 1)
		{
			temp[i].flag = 1;
			temp[i].wt = (tcurr+1) - temp[i].bt - temp[i].at;
			temp[i].ta = (tcurr+1) - temp[i].at;
			sumw+=temp[i].wt;
			sumt+=temp[i].ta;
		}
		j=i; min_bt = 999;
		for(x=0;x<n;x++)
		{
			if(temp[x].at <= (tcurr+1) && temp[x].flag != 1)
			{
				if(min_bt != b[x] && min_bt > b[x])
				{
					min_bt = b[x];
					i=x;
				}
			}
		}
	}
	printf(" %d",tcurr);
	avgwt = (float)sumw/n; avgta = (float)sumt/n;
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}





// PRIORITY - Pre-emptive
void PRT_P(processes P[],int n)
{
	printf("\n\t\t\t\t\tPRIORITY - Pre-emptive\n");
	int i,t_total=0,tcurr,b[10],j,x,min_pr;
	int sumw=0,sumt=0;
	float avgwt=0.0,avgta=0.0;
	processes temp[10],t;
	for(i=0;i<n;i++)
	{
		temp[i]=P[i];
		t_total+=P[i].bt;
	}
	b_sort(temp,n);
	for(i=0;i<n;i++)
		b[i] = temp[i].bt;
	i=j=0;
	printf("\n GANTT CHART\n\n %d %s",i,temp[i].name);
	for(tcurr=0;tcurr<t_total;tcurr++)
	{
		if(b[i] > 0 && temp[i].at <= tcurr)
		b[i]--;
		if(i!=j)
			printf(" %d %s",tcurr,temp[i].name);
		if(b[i]<=0 && temp[i].flag != 1)
		{
			temp[i].flag = 1;
			temp[i].wt = (tcurr+1) - temp[i].bt - temp[i].at;
			temp[i].ta = (tcurr+1) - temp[i].at;
			sumw+=temp[i].wt;
			sumt+=temp[i].ta;
		}
		j=i;

		min_pr = 999;
		for(x=0;x<n;x++)
		{
			if(temp[x].at <= (tcurr+1) && temp[x].flag != 1)
			{
				if(min_pr != temp[x].prt && min_pr > temp[x].prt)
				{
					min_pr = temp[x].prt;
					i=x;
				}
			}
		}
	}
	printf(" %d",tcurr);
	avgwt = (float)sumw/n;
	avgta = (float)sumt/n;
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}




// OUR PROPOSED METHOD..... -->ROUND ROBIN USING PRIORITY AND // SJF
void RR_P(processes P[],int n)
{
	printf("\n\t\t\t\t\tOUR PROPOSED METHOD\n");
	processes temp[10];
	int bt[n],p[n],s[n],wt[n],tat[n],ts,its[n],tq[n][n],rbt[n],ord[n];
	for(int i=0; i<n; i++)
	{
		wt[i]=tat[i]=0;
		s[i]=1;
		for(int j=0; j<n; j++)
			tq[i][j]=0;
	}
	for(int i=0;i<n;i++)
		temp[i]=P[i];
	b_sort(temp,n);
	printf("\nEnter the initial time slice: ");
	scanf("%d",&ts);
	for(int i=0; i<n; i++)
	{
		ord[i]=i+1;
		bt[i]=temp[i].bt;
		p[i] = temp[i].prt;
	}

	int flag=0,j=0;
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-1; j++)
			if(bt[j]>bt[j-1])
			{
				int t=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=t;
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
				t=ord[j];
				ord[j]=ord[j+1];
				ord[j+1]=t;
			}
	for(int i=0; i<n; i++)
		p[i]+=i;
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-1; j++)
			if(p[j]>p[j+1])
			{
				int t=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=t;
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
				t=ord[j];
				ord[j]=ord[j+1];
				ord[j+1]=t;
			}
	for(int i=0; i<n; i++)
		rbt[i]=bt[i];
	while(!flag)
	{
		for(int i=0; i<n; i++)
		{
			if(p[i]>0.67*n) p[i]=0;
			else if(p[i]>0.33*n) p[i]=1;
			else p[i]=2;
			if(i!=0)
			if((bt[i]-bt[i-1])>0)
				s[i]=0;
			its[i]=ts+bt[i]+s[i]+p[i];
			if(j==0)
			{
				if(s[i]==1)
					tq[j][i]=its[i];
				else
					tq[j][i]=ceil(0.5*(float)its[i]);
				if(rbt[i]<tq[j][i])
					tq[j][i]=rbt[i];
				rbt[i]=rbt[i]-tq[j][i];
			}
			else
			{
				if(rbt[i]<=0)
					tq[j][i]=0;
				else if(s[i]==1)
					tq[j][i]=2*tq[j-1][i];
				else
					tq[j][i]=1.5*tq[j-1][i];
				if(rbt[i]<tq[j][i])
					tq[j][i]=rbt[i];
				rbt[i]=rbt[i]-tq[j][i];
			}
		}
		j++;
		flag=-1;
		for(int i=0; i<n; i++)
			if(rbt[i]>0)
				flag=0;
	}
	for(int x=0; x<n; x++)
	{
		flag=-1;
		for(int y=0; y<j; y++)
		{
			for(int z=0; z<n; z++)
			{
				if(z!=x)
					wt[x]+=tq[y][z];
				else if(z==x&&tq[y+1][z]==0)
				{
					flag=0;
					break;
				}
			}
			tat[x]+=tq[y][x];
			if(flag==0)
				break;
		}
		tat[x]+=wt[x];
	}
			
			
	printf("\n\nProcess no.:\tBurst Times\tIntelligent Time Slices\t\tWaiting Time\tTurnaround Time\n");
	for(int i=0; i<n; i++)
		printf("%5d\t\t%5d\t\t%5d\t\t\t\t%5d\t\t%5d\n",ord[i],bt[i],its[i],wt[i],tat[i]);
	printf("\n\nDynamic Time Quantums for the processes:\n");
	for(int x=0; x<j; x++)
	{
		printf("Round %d",x+1,": \n");
		for(int y=0; y<n; y++)
			printf("%5d",tq[x][y]);
			printf("\n");
	}
	float avwt=0,avtat=0;
	for(int i=0; i<n; i++)
	{
		avwt+=wt[i];
		avtat+=tat[i];
	}
	avwt/=n;
	avtat/=n;
	printf("\n\nAverage waiting time: %5f",avwt);
	printf("\nAverage turnaround time: %5f",avtat);
}







int main()
{ // MAIN
	processes P[10];
	int ch,n;
	printf("\n\n\t\t\t\t----------------------------------------------------------");
	printf("\n\t\t\t\t\tSIMULATION OF CPU SCHEDULING ALGORITHMS\n");
	printf("\t\t\t\t----------------------------------------------------------");
	do
	{
		printf("\n\n\n\t\t\t\t Options:");
		printf("\n\t\t\t\t 0. Enter process data.");
		printf("\n\t\t\t\t 1. FCFS");
		printf("\n\t\t\t\t 2. SJF (Pre-emptive)");
		printf("\n\t\t\t\t 3. SJF (Non Pre-emptive)");
		printf("\n\t\t\t\t 4. Priority Scheduling (Pre-emptive)");
		printf("\n\t\t\t\t 5. Priority Scheduling (Non Pre-emptive)");
		printf("\n\t\t\t\t 6. Round Robin");
		printf("\n\t\t\t\t 7. Comparison Method 1");
		printf("\n\t\t\t\t 8. Comparison Method 2");
		printf("\n\t\t\t\t 9. Our Proposed Method");
		printf("\n\t\t\t\t 10. Exit\n Select : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 0:
			n=accept(P);
			break;
			case 1:
			FCFS(P,n);
			break;
			case 2:
			SJF_P(P,n);
			break;
			case 3:
			SJF_NP(P,n);
			break;
			case 4:
			PRT_P(P,n);
			break;
			case 5:
			PRT_NP(P,n);
			break;
			case 6:
			RR(P,n);
			break;
			case 7:
			CP1(P,n);
			break;
			case 8:
			CP2(P,n);
			break;
			case 9:
			RR_P(P,n);
			break;
			case 10:exit(0);
		}
	}
	while(ch != 10);
	getch();
	return 0;
}





