cc = clang

#code dir
NET_DIR = ../net
BASE_DIR = ../base
BASE_INCLUDE = ../base/include
BASE_SOURCE = ../base/source
THREAD_DIR = ../thread

#obj dir
OBJ_DIR = ./obj

#app dir
APP_DIR = ./app

# CFLAGS = -g -v -lstdc++
CFLAGS = -g -lstdc++

.PHONY:all
all: cinet
test: cinet_test

# net
cinet: base thread $(NET_DIR)/listen.cpp
	cc $(CFLAGS) -o $(OBJ_DIR)/cinet.o -c $(NET_DIR)/listen.cpp

cinet_test: base thread cinet $(NET_DIR)/listen_test.cpp
	cc $(CFLAGS) -o $(APP_DIR)/cinet_test.app $(NET_DIR)/listen_test.cpp $(OBJ_DIR)/cinet.o $(OBJ_DIR)/error.o $(OBJ_DIR)/thread.o

# thread
thread: base $(THREAD_DIR)/kthread.cpp $(THREAD_DIR)/exclusive.h
	cc $(CFLAGS) -o $(OBJ_DIR)/thread.o -c $(THREAD_DIR)/kthread.cpp

tbread_test: base $(THREAD_DIR)/kthread.cpp $(THREAD_DIR)/exclusive.h $(THREAD_DIR)/test.cpp
	cc $(CFLAGS) -o $(APP_DIR)/thread_test.app $(THREAD_DIR)/kthread.cpp $(THREAD_DIR)/test.cpp $(OBJ_DIR)/error.o

# base
base: $(BASE_SOURCE)/error.cpp
	cc $(CFLAGS) -o $(OBJ_DIR)/error.o -c $(BASE_SOURCE)/error.cpp 

base_test: $(BASE_SOURCE)/error.cpp $(BASE_SOURCE)/error_test.cpp
	cc $(CFLAGS) -o $(APP_DIR)/base_test.app $(BASE_SOURCE)/error.cpp $(BASE_SOURCE)/error_test.cpp 

.PHONY:clean
clean:
	-rm -f $(APP_DIR)/*.app
	-rm -f $(OBJ_DIR)/*.o
	-rm -rf *.dSYM
