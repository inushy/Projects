/*
    Anushka Verma <Z1911937>
    Prof. Lehuta
    CSCI 330 Section - 1
    assign08 - practice programming TCP/IP programs using sockets.
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;

void sendFile(char*, int);
void chomp(char*);
bool inExsist(const char*);
bool isFile(const char*);


int main( int argc, char **argv )
{

   //check for all arguments, if not show usage
   if ( argc != 3 )
   {
      cerr << "Invalid command!\nUsage: portnumber directory\n";
      exit( 1 );
   }
   
   
   DIR * gdir;

   int succh;
   int newsockfd;
   char buffer[ 256 ];
   socklen_t serverlen = sizeof(  sockaddr_in  );
   socklen_t clientlen = sizeof(  sockaddr_in  );
   ssize_t received;
   char * comansp[ 2 ];
   char * webDir = argv[ 2 ];
   
   
   //create a new socket and check to see if it failed
   int sockfd = socket( AF_INET, SOCK_STREAM, 0 );
   if ( sockfd < 0 )
   {
      cerr << "Failed to create socket";
      exit( 1 );
   }
   
   struct sockaddr_in server;
   struct sockaddr_in client;
   
   //set default values for the server
   memset( &server, 0, sizeof( server ) );
   server.sin_family = AF_INET;
   server.sin_addr.s_addr = INADDR_ANY;
   server.sin_port = htons( atoi( argv[ 1 ] ) );
   
   serverlen = sizeof( server );
   
   //bind the socket and check if the bind failed
   succh = bind( sockfd, ( struct sockaddr* ) &server, serverlen );
   if ( succh < 0 )
   {
      cerr << "binding failed!\n";
      exit( 1 );
   }
   
   //listen on a socket, and check if the listen failed
   succh = listen( sockfd, 128 );
   if ( succh < 0 )
   {
      cerr << "listen failed!\n";
      exit( 1 );
   }
   
   
   clientlen = sizeof( client );
   
   //run until it breaks
   while ( true )
   {
      //except new oncomming connections
      newsockfd = accept( sockfd, ( struct sockaddr* ) &client, &clientlen );
      
      //check to see if the connection failed
      if ( newsockfd < 0 )
      {
          cerr << "Accept Failed!";
      exit( 1 );
      }
      
      
      //Split connections to allow parent to accept new requests
      //Child will handle the requests
      if ( fork(  ) ) //we are parent
      {
      
         close( newsockfd );
     
      } else //we are child
      {
         //read what was read and check to see if the read failed
         received = read( newsockfd, buffer, 256 );
         if ( received < 0 )
         {
            cerr << "failed to get message!\n";
        exit( 1 );
         }
     
     cout << buffer;
         //check to see if "GET" was recived as a command
         comansp[ 0 ] = strtok( buffer, " " );
         if ( strcmp( comansp[ 0 ], "GET" ) == 0 )
         {
            comansp[ 1 ] = strtok( NULL, " \n" );
        
        //check to see if msg began with a '/'
        if ( comansp[ 1 ][ 0 ] != '/' )
        {
           char errorMsg[  ] = "GET Request must begin with an '/'!\n";
           write( newsockfd, errorMsg, strlen( errorMsg ) );
           exit( 1 );
        }
        
        //check to see if msg contained '..'
        if ( strstr( comansp[ 1 ], ".." ) != NULL )
        {
           char errorMsg[  ] = "GET Request cannot contain \"..\"\n";
           write( newsockfd, errorMsg, strlen( errorMsg ) );
           exit ( 1 );
        }
        
        
        chomp( comansp[ 1 ] );
        strcat( webDir, comansp[ 1 ] );
        
        //check if the last character in the path is a '/'
        if ( webDir[ strlen( webDir )-1 ] != '/' )
        {
           //double check to see if the path is a file
           if ( isFile( webDir ) )
           {
              sendFile( webDir, newsockfd );
              close( newsockfd );
              exit( 1 );
           }
        } else //path refers to a directory
        {
           char indexPath[ 128 ];
           char indexName[  ] = "index.html";
           strcpy( indexPath, webDir );
           strcat( indexPath, indexName );
           chomp( indexPath );
           
           //check to see if the directory contains 'index.html'
           if ( inExsist( indexPath ) )
           {
              sendFile( indexPath, newsockfd );
          sleep( 10 );
              close( newsockfd );
              exit( 1 );
           }
        }
        
        //attempt to open requested directory
        gdir = opendir( ( const char* ) webDir );
        if ( gdir == NULL )
        {
           char errorMsg[  ] = "File or directory doesn't exsist!\n";
           write( newsockfd, errorMsg, strlen( errorMsg ) );
           exit( 1 );
        }
        
            struct dirent* thedir;
        
        //redirect everything that would be outputted on to cout
        //and output it to the client
            if ( dup2( newsockfd, 1 ) < 0 )
        {
           cerr << "Socket dup2 failed!";
           exit( 1 );
        }
        
        //read the contents of a directory and print the name
        //of each file/directory
        while ( ( thedir = readdir( gdir ) ) != NULL )
        {
           if ( thedir->d_name[ 0 ] != '.' )
           {
              cout << thedir->d_name << endl;
           }
        }
     
     } else //request didn't start with 'GET'
     {
        char errorMsg[  ] = "Any request must start with 'GET'!\n";
        write( newsockfd, errorMsg, strlen( errorMsg ) );
     }
     
         close( newsockfd );
     exit( 1 );
      }
      
      //Null out the buffer so strlen doesn't misinterpet how
      //full it is
      memset( buffer, 0, sizeof( buffer ) );
   }
   
   
  close( sockfd );
   return 0;
}

void sendFile(char* pName, int fdSock)
{
   int openFd;
   char buffer[256];
   ssize_t bytesr;
   char errmsg[] = "File Doesn't exsist!\n";
   
   openFd = open(pName, O_RDWR);
   
   if (openFd < 0)
   {
      write(fdSock, errmsg, strlen(errmsg));
      exit(1);
   }
   
   bytesr = read(openFd, (char*) buffer, 256);
   write(fdSock, buffer, (size_t) bytesr);
   while ((int) bytesr >= 256)
   {
      bytesr = read(openFd, (char*) buffer, 256);
      write(fdSock, buffer, (size_t) bytesr);
   }
}

/*
Function: inExsist
Use: checks if the file with the requested name exsists
parameters: name: the reqested name
Returns: true if the file exsists, false otherwise
*/

bool inExsist(const char* name)
{
   struct stat buffer;
   return (stat(name, &buffer) == 0);
}

/*
Function: isFile
Use: will check to see if the reqested name is the name of a file
     or a directory
     
Parameters: name: the name of a file or directory
Returns: True if it is a file, false otherwise
*/

bool isFile(const char* name)
{
   bool rv = false;
   struct stat buffer;
   stat(name, &buffer);
   if ((buffer.st_mode & S_IFMT) == S_IFREG)
      rv = true;
      
   return rv;
}

/*
Function: chomp
Use: removes leading returns and newlines and replaces them
     with null characters
Parameters: s: a pointer to a string to be manipulated
Returns: nothing
*/

void chomp(char *s) {
for (char *p = s + strlen(s)-1; *p == '\r' || *p == '\n'; p--)
   *p = '\0';
}
