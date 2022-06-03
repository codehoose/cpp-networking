#pragma once

#include <string>
#include <WS2tcpip.h>						// Header file for Winsock functions
#pragma comment(lib, "ws2_32.lib")			// Winsock library file

#define MAX_BUFFER_SIZE (49152)

// Forward declaration of class
class CTcpListener;

// Callback to data received
typedef void(*MessageRecievedHandler)(CTcpListener* listener, int socketId, std::string msg);

class CTcpListener
{

public:

	// Constructor
	CTcpListener(std::string ipAddress, int port, MessageRecievedHandler handler);

	// Destructor
	~CTcpListener();
	
	// Send a message to the specified client
	void Send(int clientSocket, std::string msg);

	// Initialize winsock
	bool Init();

	// The main processing loop
	void Run();

	// Clean up after using the service
	void Cleanup();

private:

	// Create a socket
	SOCKET CreateSocket();

	// Wait for a connection
	SOCKET WaitForConnection(SOCKET listening);

	// Address of the server
	std::string				m_ipAddress;

	// Listening port
	int						m_port;

	// Message received event handler
	MessageRecievedHandler	MessageReceived;
};