CFLAGS=-Wall -pedantic
CXXFLAGS += -O2 -static -std=gnu++17 -Wno-unused-result

linked_list: linked_list.c
	gcc $(CFLAGS) -o linked_list linked_list.c
all: a.out

trie: trie.cpp
	$(CXX) $(CXXFLAGS) $? -o $@
analysis: trie.cpp
	clang++ -Werror -Weverything -Wno-c++98-compat-pedantic $(CXXFLAGS) $? -o /dev/null
trie.gprof: trie.cpp
	$(CXX) -pg $(CXXFLAGS) $? -o $@
trie.debug: trie.cpp
	$(CXX) $(CXXFLAGS) -g -O0 $? -o $@

.PHONY: analysis
