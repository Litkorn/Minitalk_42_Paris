# Minitalk_42_Paris

Creation of communication program in the form of a client and a server.

The server is started first and print its PID.
Then the client is started with the server's PID and a string as arguments.

- The server should print the string fast.

- The server should be able to receive strings from several clients in a row without needing to restart it.

- The communication should be done with ONLY : SIGUSR1 and SIGUSR2.

As I am working on linux, I had to implement one of the bonuses to make it work:
The server acknowledges every message received by sending back a signal to the
client.
