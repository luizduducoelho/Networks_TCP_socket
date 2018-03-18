#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
	
	// Create socket
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0); // 0 is default, TCP
	
	// Get address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002); // Port number
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	// Connet
	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));	
	if (connection_status == -1){
		printf("Error in connection \n");
	}
	
	// Receive
	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response), 0);
	
	// Print server response
	printf("Data received: %s \n", server_response);

	//Close the connection
	close(network_socket);
	
	return 0;
}
