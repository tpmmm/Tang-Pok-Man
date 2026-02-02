from socket import *

clientSocket = socket(AF_INET, SOCK_STREAM)

serverName = input("Server IP: ").strip()
serverPort = int(input("Server Port: ").strip())

print(f"connecting to {serverName} port {serverPort}")
clientSocket.connect((serverName, serverPort))

def recv_line():
    line = b""
    while True:
        chunk = clientSocket.recv(1)
        if not chunk:
            raise ConnectionError("Server closed connection")
        line += chunk
        if chunk == b"\n":
            break
    return line.decode('utf-8').rstrip('\n')

while True:
    sentence = input('Input command(ADD/LIST/REMOVE/MARK/QUIT): ').strip()
    if not sentence:
        continue

    command = sentence.upper()
    clientSocket.sendall((command + '\n').encode('utf-8'))

    if command in ('ADD', 'REMOVE', 'MARK'):
        print("Enter task (a line of '#' to end):")
        while True:
            line = input()
            clientSocket.sendall((line + '\n').encode('utf-8'))
            if line.strip() == '#':
                break

    if command == 'LIST':
        while True:
            line = recv_line()
            if line == '#':
                break
            print(line)
    else:
        response = recv_line()
        print(response)

        if command == 'QUIT' and response == 'OK':
            clientSocket.shutdown(SHUT_RDWR)
            clientSocket.close()
            print("closing socket")
            exit(0)
