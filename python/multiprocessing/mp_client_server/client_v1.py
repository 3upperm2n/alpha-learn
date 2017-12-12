#!/usr/bin/env python
import socket
import time
import sys


def main(argv):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect(("localhost", 9000))


    print time.time()
    data = "1" 
    print "send : ", data
    sock.sendall(data)

    #result = sock.recv(1024)
    #print result

    time.sleep(1)

    print "\n"
    print time.time()
    data = "2"
    print "send : ", data
    sock.sendall(data)

    time.sleep(1)

    print "\n"
    print time.time()
    data = "3"
    print "send : ", data
    sock.sendall(data)

    time.sleep(1)

    print "\n"
    print time.time()
    data = "4"
    print "send : ", data
    sock.sendall(data)

    time.sleep(1)

    print "\n"
    print time.time()
    data = "5"
    print "send : ", data
    sock.sendall(data)


    #
    # finish all the client work
    #
    sock.close()




if __name__ == "__main__":
    main(sys.argv[1:])
