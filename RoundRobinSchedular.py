
def findWaitingTime(n,bt,wt,quantum):
  rem_bt=[]
  for  i in range(int (n)):
      rem_bt.append(0)
  
  for  i in range(int (n)):
    rem_bt[i] =  int(bt[i])
  t = 0
 
   
  while (1):
    
    done = 1
 
        
    for i in range (int(n)):
        
      if (int(rem_bt[i]) > 0):
            
        #done = false
 
        if (int(rem_bt[i]) > int(quantum)):
          t += quantum
          rem_bt[i] -= quantum
        else:
          t = t + rem_bt[i]
          wt[i] = t - int(bt[i])
          rem_bt[i] = 0
                
            
        
 
        
    if (done == 1):
      break
    
  return;
 
def findTurnAroundTime( n,bt,  wt,  tat):
  i=0
  for i in range(int(n)):
    tat[i] = int(bt[i]) + int(wt[i])
  return;
 

def findavgTime(n,bt,quantum):

  wt=[]
  for  i in range(int (n)):
    wt.append(0)
  tat=[] 
  total_wt = 0 
  total_tat = 0
  i=0
   
  findWaitingTime(n, bt, wt,quantum)
 
   
  findTurnAroundTime( n, bt, wt, tat)
 
    
  print( "Processes\t  Burst time\t  Waiting time\t Turn around time")
 
    
  for i in range(int (n)):
    
    total_wt = total_wt + wt[i]
    total_tat = total_tat + tat[i]
    print( " " ,(i+1), "\t\t" ,bt[i] ,"\t ", wt[i] ,"\t\t " ,tat[i],"\n")
    
  a=int(total_wt)/int(n)
  b=int(total_tat)/int(n)
  print( "Average waiting time = ",a)
  print("\nAverage turn around time = ",b)
  return;
 


processes=[1,2,3]

n=3
    
burst_time = [16,3,3]
 
  
quantum = 4

findavgTime(n,burst_time, quantum)
   

