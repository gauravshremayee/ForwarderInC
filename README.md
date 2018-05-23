# ForwarderInC
Message forwarding to Node using TCP/IP Sockets in C 
Execute initiatorNode.c on Node1 (it will act as client for Node2)
Execute forwarderNode.c on Node 2(acting as Server for Node1 and Client for Node 3)
Execute receiverNode.c on Node3 ( acting as Server for Node 2) 

Sequence

1) compile forwarderNode on Node2 and Execute Binary (Listening for Node 1)

2) compile initiatorNode on Node1 and Execute Binary 

3) compile recieverNode on Node 3 and Execute Binary (will be Listening for Node 2) 


