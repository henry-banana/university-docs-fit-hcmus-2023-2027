import socket

HOST = "127.0.0.1"  # IP adress server
PORT = 65432        # port is used by the server

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = (HOST, PORT)
print("Client connect to server with port: " + str(PORT))
client.connect(server_address)

try:
    while True:
        msg = input('Client: ')
        client.sendall(bytes(msg, "utf8"))
    # client.sendall(b"This is the message from client")
except KeyboardInterrupt:
    client.close()
finally:
    client.close()

