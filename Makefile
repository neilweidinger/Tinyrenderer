TARGET = renderer
BUILDDIR = bin
SRCS = $(wildcard *.cpp)
OBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)
CXX = clang++
CXXFLAGS = -std=c++11 -Wall

.PHONY: clean

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# include dependency files, make will automatically create them with rule below
-include $(DEPS)

$(BUILDDIR)/%.d: %.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -MM -MT $(@:.d=.o) $< > $@

$(BUILDDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR) $(TARGET)
