USR=usr
LIB64=lib64
INCLUDE=include
DBUS_DIR=dbus-1.0
USR_INCLUDES=/$(USR)/$(INCLUDE)

INCLUDES=-I/$(USR)/$(LIB64)/$(DBUS_DIR)/$(INCLUDE) -I$(USR_INCLUDES)/$(DBUS_DIR)/ 
LD_FLAGS=-L/$(LIB64) -l$(DBUS_LIB)  
DEPS=

CC=gcc
CFLAGS=-c -Wall -fPIC
DBUS_LIB=dbus-1
SRC_FILES=reserve.c
OBJ_FILES:=$(patsubst %.c, %.o, $(SRC_FILES))

DBUS_BUILD=dbus

.PHONY: all test clean

all:$(DBUS_BUILD)
	
%.o:%.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ $(INCLUDES)

$(DBUS_BUILD): $(OBJ_FILES)
	$(CC) -o $@ $(OBJ_FILES) $(LD_FLAGS)  

clean:
	rm -f *.o $(DBUS_BUILD)
