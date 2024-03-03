APP_NAME = mysearchapp
LIB_NAME = libsearchfile.a

all: $(APP_NAME)

$(APP_NAME): main.cpp $(LIB_NAME)
	g++ -o $(APP_NAME) main.cpp -L. -lsearchfile

$(LIB_NAME): searchfile.cpp searchfile.h
	g++ -c searchfile.cpp -o searchfile.o
	ar rcs $(LIB_NAME) searchfile.o

clean:
	rm -f $(APP_NAME) $(LIB_NAME) searchfile.o
