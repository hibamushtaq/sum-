
x=input("enter no of processes:")


y=0


sum=0


i=0

b_time=[]


a_time=[]




for y in range (int(x)):
  
	
	i=input("enter burst time: ")
  
	
	b_time.append(i)




for y in range (int(x)):
  
	
	i=input("enter arival time: ")
  
	
	a_time.append(i)





f_time=[]


t_time=[]

w_time=[]



for y in range (int(x)):
  
	t_time.append(0)
  
	f_time.append(0)
  
	w_time.append(0)

print("burst time\t arival time\t waiting time\t turnaround time")

for y in range (int(x)):
  
	w_time[y]=sum-int(a_time[y])
  
	sum=sum+int(b_time[y])
  
	f_time[y]=sum
  
	t_time[y]=f_time[y]-int(a_time[y])
  
	print(b_time[y],'\t\t',a_time[y],'\t\t',w_time[y],'\t\t',t_time[y],'\n')



sum=0 



sum2=0

for y in range(int(x)):
   
	sum=sum+int(t_time[y])
   
	sum2=sum2+int(w_time[y])



avg=sum/int(x)

avg2=sum2/int(x)


print("average turnaround time",avg)

print("average waiting time",avg2)






