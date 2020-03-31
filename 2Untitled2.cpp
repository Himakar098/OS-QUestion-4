#include<stdio.h>
int main()
{
	printf("Enter the number of PROCESS  in the queue --- ");
	int n;
	scanf("%d",&n);
	int ts[n], p[n], at[n], bt[n], ct[n], wt[n],tat[n], i, k, temp;
	// ts - teacher_student, p - process, at - arrival_time, bt - burst_time
	// ct - completion_time, tat - turn_around_time, wt - waiting_time
	float wtavg, tatavg;
	for(i=1;i<n+1;i++)
	{
		p[i] = i;
		printf("Teacher/Student process (0/1) ?: ");
		scanf("%d",&ts[i]);
		printf("Arrival Time of process %d: ", i);
		scanf("%d",&at[i]);
		printf("Burst Time of process  %d:   ", i);
		scanf("%d",&bt[i]);
	}
	
	for(i=1;i<n+1;i++)
	{
		for(k=i+1;k<n+1;k++)
		{
			if((at[i]==at[k])&&(ts[i] > ts[k]))
			{
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
					
				temp=at[i];
				at[i]=at[k];
				at[k]=temp;
				
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
				
				temp=ts[i];
				ts[i]=ts[k];
				ts[k]=temp;
			}
			else if(at[i] > at[k])
			{
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
				
				temp=at[i];
				at[i]=at[k];
				at[k]=temp;
							
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
			
				temp=ts[i];
				ts[i]=ts[k];
				ts[k]=temp;			
			}
		}
	}
	ct[1] = bt[1] + at[1];
	tatavg = wtavg = wt[1] = 0;
	tat[1] = ct[1];
	for(i=1;i<n+1;i++)
	{
		if(ct[i] < at[i+1]) ct[i+1] = bt[i+1] + at[i+1];
		else ct[i+1] = ct[i] + bt[i+1];
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];
		wtavg = wtavg + wt[i];
		tatavg = tatavg + tat[i];
	}
	printf("\nPROCESS\t TEACH/STU PROCESS\t ARRIVAL TIME\t BURST TIME\t COMP_TIME\t TURNAROUND TIME\t WAITING TIME");
	
	for(i=1;i<n+1;i++)
	{
		printf("\n%d \t\t %d \t\t\t %d \t\t %d \t\t %d \t\t %d \t\t %d",p[i],ts[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("\nAverage Turnaround Time is --- %f",tatavg/n);
	printf("\nAverage Waiting Time is --- %f",wtavg/n);

	return 0;
}


