import socket

HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
PORT = 65431        # Port to listen on (non-privileged ports are > 1023)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(1)
# count = 0
while True:
    conn, addr = s.accept()
    # count += 1
    try:
        print('Connected by', addr)
        while True:
            data = conn.recv(1024)
            str_data = data.decode("utf8")
            if str_data == "quit":
                break
            """if not data:
                break
            """
            print("Client: " + str_data)

            # Server send input
            msg = input("Server: ")
            conn.sendall(bytes(msg, "utf8"))
    finally:
        # Clean up the connection
        conn.close()
        # if count == 2: 
        #     break
s.close()