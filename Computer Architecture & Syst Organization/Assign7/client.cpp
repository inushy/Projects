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

using namespace std;

/**
 * @note This Function Prints The Error Message And Pattern To Standard Error
 * And Terminates The Program In The Traditional Manner
 ********************************************************************************/

static void usage()
{
    cerr << "Usage: client [-s server-ip] server-port" << endl;
    cerr << "     -s server-ip: Specifies the server’s IPv4 number in dotted-quad format.(By default, use 127.0.0.1)" << endl;
    cerr << "     server-port: The server port number to which the client must connect." << endl;
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
 * Read Data From The Given Socket fd And Print it until we reach EOF
 * 
 * @param fd    Parameter Used As The File Descriptor For The Socket
 * 
 * @return -1   Let The Caller Know Badness Happened
 * @return 0    All Went Ok
 ********************************************************************************/

static int print_response(int fd)
{
    char buf[1024];
    int rval = 1;   //Prime The While Loop
    while(rval > 0)
    {
        if((rval = read(fd, buf, sizeof(buf) -1)) == -1)
        {
            perror("reading stream message from server");
            return -1;  //Let The Caller Know Badness Happened
        }
        else if(rval > 0)
        {
            buf[rval] = '\0';
            //cout << "---- read " << rval << " bytes --->>>" << buf << "<<<" << endl;
            cout << buf;
        }
    }
    return 0;   //All Went Ok
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
    int sock;      //FD For The Socket Connecting The Server
    struct sockaddr_in server;  //Socket Address For The Servef Connection
    char buf[2048]; //Read Raw Bytes Into A Character Array Buffer From Stdin
    ssize_t len = 1;
    int opt;  //Initializes The Option Variable
    bool serverCase = false;  //Boolean Of The Server Case When The Option Is Used

    while ((opt = getopt(argc, argv, "s:")) != -1)
    {
        switch (opt)
        {
            case 's':
            {
                serverCase = true;

                //IPv4 Address Is Parsed As Part To Build The sockaddr_in Of The Server
                if(inet_pton(AF_INET, optarg, &server.sin_addr) <= 0)
                {
                    cerr << optarg << ": Connection refused" << endl;
                    exit(2);
                }
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
    if(serverCase == false) //If The serverCase Is Equal To False (Or Not Selected),
    {
        //Use The Default Address
        if(inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) <= 0)
        {
            cerr << "127.0.0.1" << ": Connection refused" << endl;
            exit(2);
        }
    }

    //Gets The Port Number Which Was Entered
    server.sin_port = htons(atoi(argv[optind]));

    //Connects The fd To The Server
    if(connect(sock, (sockaddr*)&server, sizeof(server)) < 0)
    {
        perror("connecting stream socket");
        exit(1);
    }

    while(len != 0)
    {
        len = read(fileno(stdin), buf, sizeof(buf) -1);
        
        if(safe_write(sock, buf, len) < 0)
        {
            perror("writing on stream socket");
        }

    }

    //Lets The Server Know That The Request Phase Of The Transaction Has Completed.
    shutdown(sock, SHUT_WR);
    print_response(sock);   //Calling The Print Response Method
    close(sock);    //Closes The Socket
    return 0;
}