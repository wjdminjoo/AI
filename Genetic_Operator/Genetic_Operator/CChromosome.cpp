#include "CChromosome.h"
#include<iostream>


CChromosome::CChromosome()
{
	resetChromosome(20);
}


CChromosome::CChromosome(int size)
{
	resetChromosome(size);
}

void CChromosome::resetChromosome(int size)
{
	_chromSize = size;
	_fitness = 0;
	_fitnessRate = 0.0f;
	_genes.resize(size); // 사이즈만큼 할당.
	initChromosome();

}

void CChromosome::initChromosome()
{
	for (int i = 0; i < _chromSize; i++)
		_genes[i] = rand() / (double)RAND_MAX >= 0.5 ? 1 : 0; // 0.5보다 크거나 같으면 1 아니면 0
	calcFitness();
}

void CChromosome::calcFitness()
{
	_fitness = decoding();

	//for (int i = 0; i < _chromSize; i++)
	//	//_fitness += _genes[i];
	//	if (_genes[i] == 1) 
	//		_fitness += _genes[i];
}


int CChromosome::decoding()
{
	int* tmpA;
	int* tmpB;
	int* tmpC;
	int* tmpD;
	// 5할당.
	tmpA = new int[4];
	tmpB = new int[4];
	tmpC = new int[4];
	tmpD = new int[4];

	for (int i = 0; i < 5; i++)
	{
		tmpA[i] = 0;
		tmpB[i] = 0;
		tmpC[i] = 0;
		tmpD[i] = 0;
	}
	int a, b, c, d;
	for (int i = 0; i < 5; i++) {
		tmpA[i] = _genes[i];
		tmpB[i] = _genes[(i + 5)];
		tmpC[i] = _genes[(i + 10)];
		tmpD[i] = _genes[(i + 15)];
	}
	// 1개당 0과 1로 이루어진게 5개씩. 4개야. 뭐지?
	a = trans(tmpA);
	b = trans(tmpB);
	c = trans(tmpC);
	d = trans(tmpD);
	// a + 2b + 3c + 4d = 30
	return (a + (2 * b) + (3 * c) + (4 * d));
}

int CChromosome::trans(int * num)
{
	// 이진수. 1,2,4,8,16....

	int _val = 0;
	

	_val += num[4];  //1
	_val += num[3] * 2;  //2
	_val += num[2] * 4; // 4
	_val += num[1] * 8; // 8
	_val += num[0] * 16; // 16
	return _val;
}



void CChromosome::draw()
{
	for (int i = 0; i < _chromSize; i++) {
		std::cout << _genes[i] << " ";
		if (i == 4 || i == 9 || i == 14) std::cout << "  ";
	}
	std::cout << " >> fitness : " << _fitness;
	std::cout << " >> fitnessRate : " << _fitnessRate << " \n";
}

