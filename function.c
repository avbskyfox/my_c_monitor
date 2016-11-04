#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

/*            struct sockaddr_in {
//               sa_family_t    sin_family; /* address family: AF_INET */
//               in_port_t      sin_port;   /* port in network byte order */
//               struct in_addr sin_addr;   /* internet address */
//           };
//
//           /* Internet address. */
//           struct in_addr {
//               uint32_t       s_addr;     /* address in network byte order */
//           }; 
//        int inet_aton(const char *cp, struct in_addr *inp);

//       int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);


typedef struct host_stat {
	short unsigned int str_numb;
	char arm_name[10];
	char ip_addr[15];
	short signed int soa;
	short signed int soa_maintenance;
	short signed int drweb;
	short signed int syslog;
	short signed int ntp;
	struct host_stat * next_string;
};

			
void host_stat_init {
	FILE file = fopen("host_list", r);
	char buf[30] arm_name[10] ip_addr[15];
	while(!feof(file)) {
		fgets(buf, sizeof(buf), file);
		int i=0;
		for(buf[i]!=NULL, i++) {
			while(buf[i]!="/t") {
				arm_name[i] = buf[i];
			}
			while(buf[i]!=NULL) {
				ip_addr[i] = buf[i];
			}
		}
	}
	


int bind_socket(char * ip_addr, char * port_number) {

	struct sockaddr_in my_addr;
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(atoi(port_number));
	my_addr.sin_addr.s_addr = inet_addr(ip_addr);

	int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
	bind(socket_fd, (struct sockaddr *)&my_addr, sizeof(my_addr));
	return socket_fd;

}



