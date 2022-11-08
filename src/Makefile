#--------------------------------------#
#                                      #
#        bennamrouche elmehdi          #
#                                      #
#                 2022-11-8            #
#                                      #
#                                      #
#--------------------------------------#

all :color.h
	cc client.c color.c -o client
	cc server.c color.c -o server
server:
	./server
client:
	./client

clean:
	rm  client server
.PHONY:all server client

