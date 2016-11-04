/*main*/

//        ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,struct sockaddr *src_addr, socklen_t *addrlen);

#include "header.h"
//#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <curses.h>
//#include <string.h>
#define BUF 512

void main (int argc, char *argv[]) {

	char buf[BUF];
	int socket_fd = bind_socket(argv[1], argv[2]);

	initscr();
	refresh();
	
	while ("1") {
		//memset (buf, 0, sizeof(buf));
		recvfrom(socket_fd, buf, sizeof(buf), MSG_TRUNC, NULL, NULL);
		clear ();
		printw(buf);
		refresh();
		int i;
		for (i=0; i<sizeof(buf); i++) {
			buf[i] = 0;
		}
	}
	endwin();
}
