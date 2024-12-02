# Targetting to build and run tests on all data structure implementations
mytests: mytests.o HashMapTree.o RBTreeNode.o RBTree.o HashMap.o HashFunction.o # Set.o - include that here and line 3
	g++ -o mytests mytests.o HashMapTree.o RBTreeNode.o HashMap.o HashFunction.o
	./mytests

mytests.o: mytests.cpp HashMapTree.hpp RBTreeNode.hpp RBTree.hpp HashMap.hpp HashFunction.hpp customexceptions.hpp # Set.hpp ADD THESE WHEN THEY'RE IMPLEMENTED
	g++ -c mytests.cpp -o mytests.o

HashMapTree.o: HashMapTree.cpp HashMapTree.hpp customexceptions.hpp
	g++ -c HashMapTree.cpp -o HashMapTree.o

RBTreeNode.o: RBTreeNode.cpp RBTreeNode.hpp customexceptions.hpp
	g++ -c RBTreeNode.cpp -o RBTreeNode.o

RBTree.o: RBTree.cpp RBTree.hpp customexceptions.hpp
	g++ -c RBTree.cpp -o RBTree.o

HashMap.o: HashMap.cpp HashMap.hpp customexceptions.hpp
	g++ -c HashMap.cpp -o HashMap.o

HashFunction.o: HashFunction.cpp HashFunction.hpp customexceptions.hpp
	g++ -c HashFunction.cpp -o HashFunction.o

#Set.o: Set.cpp Set.hpp customexceptions.hpp
#	g++ -c Set.cpp -o Set.o

# clean all object files and executable for re-make or data deallocation
clean:
	rm -f *.o mytests