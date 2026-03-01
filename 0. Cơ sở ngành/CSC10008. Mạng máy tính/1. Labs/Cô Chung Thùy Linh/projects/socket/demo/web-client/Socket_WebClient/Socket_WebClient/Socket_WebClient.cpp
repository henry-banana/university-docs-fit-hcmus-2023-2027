
// Socket_WebClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Socket_WebClient.h"

/* Khai bao thu vien */
#include "afxsock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


/* Declare function */
int create_tcp_socket();
char *get_ip(char *host);
char *build_get_query(char *host, char *page);
void usage();

#define HOST "www.fit.hcmus.edu.vn"
#define PAGE "/"
#define PORT 80
#define USERAGENT "HTMLGET 1.0"
// The one and only application object

CWinApp theApp;

using namespace std;

//Ref: http://stackoverflow.com/questions/19715144/how-to-convert-char-to-lpcwstr
wchar_t *convertCharArrayToLPCWSTR(const char* charArray)
{
	wchar_t* wString = new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
	return wString;
}

/* Ref code:http://coding.debuntu.org/c-linux-socket-programming-tcp-simple-http-client */
int main(int argc, char* argv[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: code your application's behavior here.
			/* Ref code:http://coding.debuntu.org/c-linux-socket-programming-tcp-simple-http-client */
			CSocket s_client;
			int tmpres;
			char *ip;
			char *get;
			char buf[BUFSIZ + 1];
			char *host;
			char *page;

			if(argc == 1)
			{
				usage();
				exit(2);
			}
			host = argv[1];
			if(argc > 2)
			{
				page = argv[2];
			}
			else
			{
				page = PAGE;
			}

			//Buoc 1: Khoi dong socket trong Window
			AfxSocketInit(NULL);
			//Buoc 2: Tao socket
			s_client.Create();
			//Buoc 3: Ket noi toi Server
			ip = get_ip(host);
			fprintf(stderr, "IP is %s\n", ip);
			if (s_client.Connect(convertCharArrayToLPCWSTR(ip), PORT) < 0)
			{
				perror("Could not connect");
				exit(1);
			}
			get = build_get_query(host, page);
			fprintf(stderr, "Query is:\n<<START>>\n%s<<END>>\n", get);

			//Send the query to the server
			int sent = 0;
			while (sent < strlen(get))
			{
				tmpres = s_client.Send(get + sent, strlen(get) - sent, 0);
				if (tmpres == -1){
					perror("Can't send query");
					exit(1);
				}
				sent += tmpres;
			}
			//now it is time to receive the page
			memset(buf, 0, sizeof(buf));
			/*int htmlstart = 0;
			char * htmlcontent;*/
			while ((tmpres = s_client.Receive(buf, BUFSIZ, 0)) > 0)
			{
				//if(htmlstart == 0)
				//{
				//	/* Under certain conditions this will not work.
				//	* If the \r\n\r\n part is splitted into two messages
				//	* it will fail to detect the beginning of HTML content
				//	*/
				//	htmlcontent = strstr(buf, "\r\n\r\n");
				//	if(htmlcontent != NULL)
				//	{
				//		htmlstart = 1;
				//		htmlcontent += 4;
				//	}
				//}
				//else
				//{
				//		htmlcontent = buf;
				//}
				if (buf){
					fprintf(stdout, buf);
				}
				memset(buf, 0, tmpres);
			}
			if (tmpres < 0)
			{
				perror("Error receiving data");
			}
			//free(get);
			//free(ip);
			s_client.Close();
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}

	return nRetCode;
}

void usage()
{
	fprintf(stderr, "USAGE: htmlget host [page]\n\
		\thost: the website hostname. ex: coding.debuntu.org\n\
		\tpage: the page to retrieve. ex: index.html, default: /\n");
}

/*
Get ip from domain name
*/
char *get_ip(char *host)
{
	struct hostent *hent;
	int iplen = 15; //XXX.XXX.XXX.XXX
	char *ip = (char *)malloc(iplen + 1);
	memset(ip, 0, iplen + 1);
	if ((hent = gethostbyname(host)) == NULL)
	{
		perror("Can't get IP");
		exit(1);
	}
	if (inet_ntop(AF_INET, (void *)hent->h_addr_list[0], ip, iplen) == NULL)
	{
		perror("Can't resolve host");
		exit(1);
	}
	return ip;
}


char *build_get_query(char *host, char *page)
{
	char *query;
	char *getpage = page;
	char *tpl = "GET /%s HTTP/1.0\r\nHost: %s\r\nUser-Agent: %s\r\n\r\n";
	if (getpage[0] == '/'){
		getpage = getpage + 1;
		fprintf(stderr, "Removing leading \"/\", converting %s to %s\n", page, getpage);
	}
	// -5 is to consider the %s %s %s in tpl and the ending \0
	query = (char *)malloc(strlen(host) + strlen(getpage) + strlen(USERAGENT) + strlen(tpl) - 5);
	sprintf_s(query, strlen(query)+1, tpl, getpage, host, USERAGENT);
	return query;
}
