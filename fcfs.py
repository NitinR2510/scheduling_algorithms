# -*- coding: utf-8 -*-
"""
Created on Mon Sep  2 03:07:39 2019

@author: Nitin
"""
#first come first serve scheduler
'''
To a CPU, the processes shall come in the order of their arrival time by default. 
Sorting is not necessary
'''

at = []
wt = []
tat = []
bt = []

num = int(input("Enter the number of processes: "))
for i in range(num):
    print("\nEnter the arrival time of process",i+1,":")
    p = eval(input())
    at.append(p)


for i in range(num):
    print("\nEnter burst time of process",i+1,":" )
    m = eval(input())
    bt.append(m)
    
#however, if sorting is to be done,
'''for i in range(num):
    pos = i
    for j in range(i+1,num):
        if (at[i]<at[j]):
            pos=j
        else:
            temp = at[i]
            at[i]=at[pos]
            at[pos] = temp
            
            temp = bt[i]
            bt[i]=bt[pos]
            bt[pos] = temp
            
            temp = pt[i]     //process name
            pt[i]=pt[pos]
            pt[pos] = temp
'''
     
        
wt.append(0)
for i in range(1,num):
    w = bt[i-1]+wt[i-1]
    wt.append(w)
for i in range(num):
    t = bt[i]+wt[i]
    tat.append(t)
awt=sum(wt)/num
atat = sum(at)/num  
print("process\t arrival-time\t wait-time\tturnaroundtime\n")
for i in range(num):
    print("process",i+1,"\t",at[i],"\t\t ",wt[i],"\t\t", tat[i])
print("average wait time is: ",awt)
print("\naverage turnaroundtime is: ",atat)
print("\n")
