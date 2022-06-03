#include <iostream>
#include <string>

#include "TcpListener.h"
#include "Qotd.h"

using namespace std;

void Listener_MessageReceived(CTcpListener* listener, int client, string msg);

// This is kinda bad because it's global.
CQotd quotes("wisdom.txt");

void main()
{
	CTcpListener server("127.0.0.1", 54010, Listener_MessageReceived);
	
	if (server.Init())
	{
		server.Run();
	}
}

void Listener_MessageReceived(CTcpListener* listener, int client, string msg)
{
	if (msg == "QUOTE")
	{
		listener->Send(client, quotes.GetRandomQuote());
	}
}
