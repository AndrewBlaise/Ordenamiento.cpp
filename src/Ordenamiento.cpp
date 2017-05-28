#include "Ordenamiento.h"

std::vector<int> Ordenamiento::Bubblesort(std::vector<int> l){
	for (int i = 1; i < l.size()-1; ++i)
		for (int j = 1; j <l.size()-1-i ; ++j)
			if (l[j]>l[j+1])
			{
				int aux=l[j];
				l[j]=l[j+1];
				l[j+1]=aux;
			}		
		return l;
}


int Ordenamiento::Menor(std::vector<int> l, int i){
	int aux=l[i];
	int index=i;
	for(int j=i+1;j<l.size();++j)
		if (aux>l[j])
		{
			aux=l[j];
			index=j;
		}
	return index;
}


std::vector<int> Ordenamiento::SeleccionMenor(std::vector<int> l){
	int aux;
	for (int i = 0; i < l.size(); ++i)
	{
		int idx_men=Menor(l,i);
		if(idx_men!=i){
			aux=l[i];
			l[i]=l[idx_men];
			l[idx_men]=aux;
		}
	}
	return l;
}


int Ordenamiento::Mayor(std::vector<int> l, int i){
	int aux=l[i];
	int index=i;
	for(int j = i+1; j < l.size() ; ++j)
		if (aux<l[j])
		{
			aux=l[j];
			index=j;
		}
	return index;
}


std::vector<int> Ordenamiento::SeleccionMayor(std::vector<int> l){
	int aux;
	for (int i = 0; i < l.size(); ++i)
	{
		int idx_may=Mayor(l,i);
		if(idx_may!=i){
			aux=l[i];
			l[i]=l[idx_may];
			l[idx_may]=aux;
		}
	}
	return l;
}


std::vector<int>  Ordenamiento::Insercion(std::vector<int> l){
	int aux;
	for (int i = 1; i < l.size() ; ++i)
	{
		aux=l[i];
		int j=i-1;
		while(j>=0 && aux < l[j]){
			l[j+1]=l[j];
			--j;
		}
		l[j+1]=aux;
	}
	return l;
}


void Ordenamiento::Split(std::vector<int> l,int t,std::vector<int> l1,std::vector<int> l2){
	int aux1=0,aux2=0;
	for (int i = 0; i < l.size(); ++i)
		if (i<t){
			l1[aux1]=l[i];
			++aux1;
		}else{
			l2[aux2]=l[i];
			++aux2;
		}
}


std::vector<int> Ordenamiento::Merge(std::vector<int> lI,std::vector<int> lD){
	int i=0,j=0,aux=0;
	std::vector<int> l;
	while(i<lI.size() && j<lD.size()){
		if (lI[i]>l[j])
		{
			l[aux]=lD[j];
			++j;
		}else{
			l[aux]=lI[i];
			++i;
		}
		++aux;
	}

	aux=0;
	if (i==lI.size())
		for (int k = j; k < lD.size(); ++k){
			l[aux]=lD[k];
			++aux;
		}
	else
		for (int k = 0; k < lI.size(); ++k)
		{
			l[aux]=lI[k];
			++aux;
		}
	return l;
}


std::vector<int> Ordenamiento::MergeSort(std::vector<int> l){
	std::vector<int> lD,lI;
	int t=l.size()/2;
	Split(l,t,lI,lD);
	if (lD.size()!=1)
		lD=MergeSort(lD);

	if (lI.size()!=1)
		lI=MergeSort(lI);

	return Merge(lI,lD);
}