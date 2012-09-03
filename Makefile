CXX = clang++
CXXFLAGS = -g -Wall 
SRCS = CSSAST.cpp CSSColor.cpp CSSFont.cpp CSSImage.cpp CSSLexer.cpp CSSParser.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(OBJS)

CSSAST.o: CSSAST.cpp CSSAST.hpp
CSSColor.o: CSSColor.cpp CSSColor.hpp
CSSFont.o: CSSFont.cpp CSSFont.hpp
CSSImage.o: CSSImage.cpp CSSImage.hpp
CSSLexer.o: CSSLexer.cpp CSSLexer.hpp
CSSParser.o: CSSParser.cpp CSSParser.hpp

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@	

clean:
	rm -rf $(OBJS) _Inline

