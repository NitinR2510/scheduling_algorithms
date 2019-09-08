//This program is to generate fcfs algorithm
//It is based on the premise that the order in which CPU receives programs is the order in which it records arrival time
//So, sorting is not actually needed in a fcfs algorithm
#include<stdio.h>
int main()
{
	int wait=0,turn=0,at[10], wt[10], tat[10], bt[10], temp=0, pos=0,i,j, num; 
	float awt = 0, atat = 0; 
	//or one can come up with dynamic allocation
	/*the arrival time of the processes are recorded by the cpu in the order they arrive*/
    printf("Enter the number of processes to be entered: ");
    scanf("%d",&num);
    for (i=0;i<num;i++)
    {
    	printf("\nEnter the arrival time of the processes %d: ",i+1);
    	scanf("%d",&at[i]);
    	printf("\nEnter the burst time of the process: ");
    	scanf("%d",&bt[i]);
	}
	wt[0] = 0;  //waiting time for the first process is zero.
	for(j=1;j<num;j++)
	{
		wt[j] = bt[j-1]+wt[j-1];
		wait +=wt[j]; 
	}
	for(i=0;i<num;i++)
	{
		tat[i] = wt[i] + bt[i];
		turn +=tat[i];
	}
	atat = (float)turn/num;
	awt = (float)wait/num;
	printf("The final table is hence: \n process\t arrival_time\t wait_time\t turn_around_time\n");
	for(i=0;i<num;i++)
	{
		printf("process %d\t\t %d\t\t %d\t\t %d\n",i+1,at[i],wt[i],tat[i]);
	}
	printf("The average turnaroundtime is: %f and the average wait time is: %f\n",atat,awt);
	return 0;
}
