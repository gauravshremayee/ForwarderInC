# ForwarderInC
Message forwarding to Node using TCP/IP Sockets in C 
Execute initiatorNode.c on Node1 (it will act as client for Node2)
Execute forwarderNode.c on Node 2(acting as Server for Node1 and Client for Node 3)
Execute receiverNode.c on Node3 ( acting as Server for Node 2) 

Sequence

1) compile forwarderNode on Node2 and Execute Binary (Listening for Node 1)

2) compile initiatorNode on Node1 and Execute Binary 

3) compile recieverNode on Node 3 and Execute Binary (will be Listening for Node 2) 




on VM2

gaurav@ubuntu:~$ gcc forwarderNode.c -o f

In Parent process acting as client  to whom request will be forwarded
gaurav@ubuntu:~$ In child Process serving as Server for one of the client


On VM1

gaurav@ubuntu:~$ gcc initiatorNode.c -o i
gaurav@ubuntu:~$ ./i
Hello


on VM3 

gaurav@ubuntu:~$ gcc recieverNode.c -o r
gaurav@ubuntu:~$ ./r 
Heyy






