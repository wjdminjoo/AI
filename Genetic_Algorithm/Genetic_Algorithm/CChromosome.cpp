#include "CChromosome.h"
#include<iostream>


CChromosome::CChromosome()
{
	resetChromosome(5);
}


CChromosome::~CChromosome()
{
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
	_fitness = 0;
	for (int i = 0; i < _chromSize; i++)
		//_fitness += _genes[i];
		if (_genes[i] == 1) 
			_fitness += _genes[i];
}

void CChromosome::draw()
{
	for (int i = 0; i < _chromSize; i++)std::cout << _genes[i] << " ";
	std::cout << " >> fitness : " << _fitness;
	std::cout << " >> fitnessRate : " << _fitnessRate << " \n";
}
