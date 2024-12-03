# Targetting to build and run tests on all data structure implementations
mytests: mytests.o HashMapTree.o RBTreeNode.o RBTree.o HashMap.o MyHashFunction.o  Set.o 
	g++ -o mytests mytests.o HashMapTree.o RBTreeNode.o RBTree.o HashMap.o MyHashFunction.o Set.o
	./mytests

mytests.o: mytests.cpp HashMapTree.hpp RBTreeNode.hpp RBTree.hpp HashMap.hpp MyHashFunction.hpp customexceptions.hpp Set.hpp 
	g++ -c mytests.cpp -o mytests.o

HashMapTree.o: HashMapTree.cpp HashMapTree.hpp customexceptions.hpp
	g++ -c HashMapTree.cpp -o HashMapTree.o

RBTreeNode.o: RBTreeNode.cpp RBTreeNode.hpp
	g++ -c RBTreeNode.cpp -o RBTreeNode.o

RBTree.o: RBTree.cpp RBTree.hpp RBTreeNode.hpp customexceptions.hpp
	g++ -c RBTree.cpp -o RBTree.o

HashMap.o: HashMap.cpp HashMap.hpp customexceptions.hpp
	g++ -c HashMap.cpp -o HashMap.o

MyHashFunction.o: MyHashFunction.cpp MyHashFunction.hpp customexceptions.hpp
	g++ -c MyHashFunction.cpp -o MyHashFunction.o

Set.o: Set.cpp Set.hpp customexceptions.hpp
	g++ -c Set.cpp -o Set.o

# clean all object files and executable for re-make or data deallocation
clean:
	rm -f *.o mytests