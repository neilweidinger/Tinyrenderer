TARGET = run
OBJS = raytracer.o vector.o ray.o
CXX = clang++
CXXFLAGS = -std=c++11 -Wall

.PHONY: all
all: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
