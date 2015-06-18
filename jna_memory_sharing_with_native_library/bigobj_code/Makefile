
CLIB=clib

all:
	#javac -classpath .:jna.jar -g JnaTest.java BigData.java  #compile java
	javac -classpath .:jna-4.0.0.jar -g JnaTest.java BigData.java  #compile java
	gcc -shared -o $(CLIB)/libhello.so -fPIC $(CLIB)/helloworld.c -g -Wall

clean:
	rm -f *.class $(CLIB)/*.so 

