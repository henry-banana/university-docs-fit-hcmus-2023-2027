import socket

HOST = '127.0.0.1'  # The server's hostname or IP address
PORT = 65431        # The port used by the server
# Create a TCP/IP socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = (HOST, PORT)
print('connecting to %s port ' + str(server_address))
s.connect(server_address)


try:
    while True:
        msg = input('Client: ')
        s.sendall(bytes(msg, "utf8"))

        if msg == "quit":
            break

        data = s.recv(1024)
        print('Server: ', data.decode("utf8"))
finally:
    print('closing socket')
    s.close()
