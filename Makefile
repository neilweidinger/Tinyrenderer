TARGET = run
OBJS = raytracer.o geometry.o
CFLAGS = -std=c++11 -Wall

.PHONY: all
all: $(OBJS)
	g++ $(CFLAGS) -o $(TARGET) $(OBJS)

raytracer.o: raytracer.hpp raytracer.cpp geometry.hpp geometry.cpp
	g++ $(CFLAGS) -c raytracer.cpp
geometry.o: geometry.hpp
	g++ $(CFLAGS) -c geometry.cpp

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
