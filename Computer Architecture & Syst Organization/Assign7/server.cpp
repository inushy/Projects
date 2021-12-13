//******************************************************************
//
// CSCI 463 Assignment 7
//
// Author: Anushka Verma (Z1911937)
//
// Client and Server applications that use a TCP socket to execute 
// a transaction by sending data from the client to the server for 
// processing and return a result that the client will display.
//
//******************************************************************

#include <iostream>
#include <iomanip>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>    
#include <stdio.h>    
#include <stdlib.h>    
#include <sys/socket.h>    
#include <sys/stat.h>    
#include <sys/types.h>    
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <signal.h>

using namespace std;

/**
 * @note This Function Prints The Error Message And Pattern To Standard Error
 * And Terminates The Program In The Traditional Manner
 ********************************************************************************/

static void usage()
{
    cerr << "Usage: server [-l listener-port]" << endl;
    cerr << "     listener-port: The port number to which the server must listen." << endl;
    exit(1);
}

/**
 * Same As Write() But Includes Loop To Complete Any Partial Data
 * 
 * @param fd    Parameter Used As The File Descriptor For The Socket
 * @param buf   Parameter Used As The Buffer We Want To Write In
 * @param len   Parameter Used As The Length Of The Buffer
 * 
 * @return -1   Write Returned An Unrecoverable Error, Errno Will Be Set
 * @return len  If We Get Here Then We Sent The Full Requested Length!
 ********************************************************************************/

static ssize_t safe_write(int fd, const char *buf, size_t len)
{
    while(len > 0)
    {
        ssize_t wlen = write(fd, buf, len);
        if(wlen == -1)
        {
            return -1;  //Write Returned An Unrecoverable Error, Errno Will Be Set
        }
        //cout << "sent " << wlen << " bytes" << endl;
        len -= wlen;    //Reduce The Remaning Number Of Bytes To Send
        buf += wlen;    //Advance The Buffer Pointer Past The Written Data
    }
    return len; //If We Get Here Then We Sent The Full Requested Length!
}

/**
 * This function helps to accept the command-line parameters
 * 
 * @param argc Argument Count
 * @param argv Argument Vector
 * 
 * @return 0
 ********************************************************************************/

int main(int argc, char *argv[])
{
    signal(SIGPIPE, SIG_IGN);   //Ignores All Possible Broken Pipes
    int sock;      //FD For The Socket Connecting The Server
    struct sockaddr_in server;  //Socket Address For The Servef Connection
    socklen_t length;   //The Length Of The Server
    int msgsock;
    char buf[1024]; //Read Raw Bytes Into A Character Array Buffer From Stdin
    int opt;  //Initializes The Option Variable
    bool listenerCase = false;  //Boolean Of The Server Case When The Option Is Used

    while ((opt = getopt(argc, argv, "l:")) != -1)
    {
        switch (opt)
        {
            case 'l':
            {
                listenerCase = true;

                //The Listener Port Gets Set To What Get's Entered By The User
                server.sin_port = htons(atoi(optarg));
            }
            break;
            default:
            {
                usage();   //Display's Usage Errors
            }
        }
    }


    //Creates Socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)   //If The Sock Is Less Than 0,
    {
        perror("opening stream socket"); //Then Display Error Message
        exit(1); //And Close The Program
    }

    //Connects The Socket Using Name Specified By Command Line
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    if(listenerCase == false) //If The listenerCase Is Equal To False (Or Not Selected),
    {
        //Then The Listener Port Gets Set To What Get's Entered By The User
        server.sin_port = 0;
    }
    if(bind(sock, (sockaddr*)&server, sizeof(server)))
    {
        perror("binding stream socket");
        exit(1);
    }

    // Find Out Assigned Port Number And Print It Out 
    length = sizeof(server);
    if(getsockname(sock, (sockaddr*)&server, &length))
    {
        perror("getting socket name");
        exit(1);
    }

    //Display's The Port Number
    cout << "Socket has port #" << ntohs(server.sin_port);
    cout << endl;

    //Start Accepting Connections
    listen(sock, 5);
    do
    {
        struct sockaddr_in of;  //Used To Display The Address Of The Connection Peer
        socklen_t of_len = sizeof(of);
        msgsock = accept(sock, (struct sockaddr*)&of, &of_len); //Get The Socket Address Of The Connection Peer

        if(msgsock == -1)
        {
            perror("accept");
        }
        else 
        {
            uint32_t tLength = 0;
            uint16_t checkSum = 0;
            ssize_t len = 1;

            inet_ntop(of.sin_family, &of.sin_addr, buf, sizeof(buf));
            cout << "Accepted connection from '" << buf << "', port " << ntohs(of.sin_port);
            cout << endl;

            //Accepts Connections
            while(len != 0)
            {
                //Reads The Data From The Client
                if((len = read(msgsock, buf, sizeof(buf) -1)) < 0)
                {
                    perror("reading stream message");
                }

                if(len == 0)
                {
                    cerr << "Ending connection \n";
                }
                else
                {
                    for(int i = 0; i < len; i++)
                    {
                        checkSum += (uint8_t)buf[i];
                    }
                    tLength = tLength + len;
                }
            }

            //Format A Printable String And Then Extract A C String
            ostringstream os;
            os << "Sum: " << checkSum << " Len: " << tLength << endl;
            string str = os.str();
            const char *ch = str.c_str();

            if(safe_write(msgsock, ch, str.length()) < 0)
            {
                perror("writing on stream socket");
            }
            close(msgsock);
        }
    } while(true);
    /*
    * Since this program has an infinite loop, the socket "sock" is
    * never explicitly closed.  However, all sockets will be closed
    * automatically when a process is killed or terminates normally.
    */
}