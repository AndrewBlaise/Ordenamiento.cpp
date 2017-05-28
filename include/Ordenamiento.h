#include <iostream>
#include <vector>

class Ordenamiento
{
public:
//	std::vector<int> l;

	Ordenamiento();
	
	std::vector<int> Bubblesort(std::vector<int> l);
	int Menor(std::vector<int> l, int i);
	int Mayor(std::vector<int> l, int i);
	std::vector<int> SeleccionMenor(std::vector<int> l);
	std::vector<int> SeleccionMayor(std::vector<int> l);
	std::vector<int> Insercion(std::vector<int> l);
	void Split(std::vector<int> l,int t,std::vector<int> l1,std::vector<int> l2);
	std::vector<int> Merge(std::vector<int> lI,std::vector<int> lD);
	std::vector<int> MergeSort(std::vector<int> l);
};