import threading
import os

def thread1():
	print("Task 1 assigned to thread: {}".format(threading.current_thread().name)) 
	print("Process id of the first thread is {}".format(os.getpid()))
	
def thread2(): 
	print("Task 2 assigned to thread: {}".format(threading.current_thread().name))
	print("Process id of the second thread is {}".format(os.getpid()))
	
if __name__ == "__main__": 
  
    print("ID of process running main program: {}".format(os.getpid())) 
  
    print("Main thread name: {}".format(threading.main_thread().name)) 
  
     
    t1 = threading.Thread(target=thread1, name='t1') 
    t2 = threading.Thread(target=thread2, name='t2')   
  
     
    t1.start() 
    t2.start() 
  
    
    t1.join() 
    t2.join() 

