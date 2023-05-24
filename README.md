# Minitalk
### Unix Signals
> In Unix operating systems, a signal is a system message to a running process.

![minitalk](https://github.com/Christwelve/minitalk/assets/39922270/89875dbf-6160-47ba-8246-8bab8ba98e74)


## Topic
The objective is to design a server-client communication protocol utilizing only SIGUSR1 and SIGUSR2 signals. 
The server should continuously run without interruption, receiving information from the client on a bit level. 
Once the server has received the complete message, it should print the translated message. On the client side, the task involves converting an input string into binary representation and sending it to the server using SIGUSR1 and SIGUSR2 signals.

## Visualization 
The server outputs the transmitted message in the terminal after receiving it. 

## How to use
```
 git clone
 cd minitalk
 make
 ./server 
 open new terminal
 ./client <pid> <str>
```
