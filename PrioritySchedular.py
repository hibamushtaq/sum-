

print("Enter the number of processess: ")
n=input()
processes=[]
for i in range(int(n)):
 processes.insert(i,i+1)


print("\nEnter the burst time of the processes:(seperated by space) \n")
b_time=list(map(int, input().split()))


print("\nEnter the priority of the processes:(seperated by space) \n")
priority=list(map(int, input().split()))
t_time=[]
w_time=[]

i=0
j=0
for i in range(len(priority)-1):
 for j in range(len(priority)-i-1):
  if(priority[j]>priority[j+1]):
   swap=priority[j]
   priority[j]=priority[j+1]
   priority[j+1]=swap

   swap=b_time[j]
   b_time[j]=b_time[j+1]
   b_time[j+1]=swap

   swap=processes[j]
   processes[j]=processes[j+1]
   processes[j+1]=swap

w_time.insert(0,0)
t_time.insert(0,b_time[0])

i=1
for i in range(len(processes)):
  w_time.insert(i,w_time[i-1]+b_time[i-1])
  t_time.insert(i,w_time[i]+b_time[i])


avgtat=0
avgwt=0
i=0
for i in range(len(processes)):
 avgwt=avgwt+w_time[i]
 avgtat=avgtat+t_time[i]
avgwt=float(avgwt)/int(n)
avgwt=float(avgtat)/int(n)
print("\n")
print("Process\t  Burst Time\t  Waiting Time\t  Turn Around Time")
i=0
for i in range(int(n)):
  print(processes[i],'\t\t',b_time[i],'\t\t',w_time[i],'\t\t',t_time[i],'\n')
  

print("Average Waiting time is: ",avgwt)
print("Average Turn Around Time is: ",avgtat)
 