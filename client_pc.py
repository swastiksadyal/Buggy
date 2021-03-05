from pynput import keyboard
from pynput.keyboard import Listener
import socket
import time
import keyboard as K
from os import system, name
from time import sleep 

def close_connection():
    print("disconnecting in 3...")
    sleep(1)
    print("disconnecting in 2...")
    sleep(1)
    print("disconnecting in 1...")
    sleep(1)
    client_socket.close()
    print("server dosconnected... Do the same on the mobile device... to run the program again start using python again!")
def clear():  
    if name == 'nt': 
        _ = system('cls')  
    else: 
        _ = system('clear')
HOST = input("enter the IP address of server: ")  # The server's hostname or IP address
PORT = input("PORT: ")  #65432        # The port used by the server
PORT = int(PORT)


client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((HOST, PORT))
def on_press(key):
    try:
        #print('alphanumeric key {0} pressed'.format(key.char))
        if key.char == 'w':
            data = b'W\n'
            client_socket.send(data)
        elif key.char == 's':
            data = b'S\n'
            client_socket.send(data)
        elif key.char == 'a':
            data = b'A\n'
            client_socket.send(data)
        elif key.char == 'd':
            data = b'D\n'
            client_socket.send(data)
        elif key.char == 'z':
            data = b'Z\n'
            client_socket.send(data)
        elif key.char == 'c':
            data = b'C\n'
            client_socket.send(data)
        elif key.char == 'q':
            data = b'L\n'
            client_socket.send(data)
        elif key.char == 'e':
            data = b'R\n'
            client_socket.send(data)
        else:
            data = b'unk\n'
            client_socket.send(data)
        sleep(0.1)


    except AttributeError:
        print('special key {0} pressed'.format(
            key))


def on_release(key):
    #print('{0} released'.format((key))
    if key == keyboard.Key.esc:
        # Stop listener
        close_connection()
        return False

# Collect events until released
with keyboard.Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()

# ...or, in a non-blocking fashion:
listener = keyboard.Listener(
    on_press=on_press,
    on_release=on_release)
listener.start()