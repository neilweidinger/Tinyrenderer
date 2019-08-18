TARGET = renderer
BUILDDIR = bin
SRCS = $(wildcard *.cpp)
OBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.cpp=.o))
CXX = clang++
CXXFLAGS = -std=c++11 -Wall

.PHONY: clean

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(BUILDDIR)/%.o: %.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR) $(TARGET)
