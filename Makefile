TARGET = renderer
BUILDDIR = bin
OBJS = $(addprefix $(BUILDDIR)/, $(patsubst %.cpp, %.o, $(wildcard *.cpp)))
CXX = clang++
CXXFLAGS = -std=c++11 -Wall

.PHONY: all clean

all: dir $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

dir:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILDDIR) $(TARGET)
