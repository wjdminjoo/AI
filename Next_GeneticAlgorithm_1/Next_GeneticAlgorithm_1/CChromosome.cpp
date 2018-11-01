#include "CChromosome.h"
#include<iostream>


CChromosome::CChromosome()
{
	_chromeLength = 5;
	_fitness = 0;
	_fitnessRate = 0.0;
	_genes.resize(_chromeLength);
	initGenes();
}


CChromosome::~CChromosome()
{
}

void CChromosome::resetChromosome(int size)
{
	_chromeLength = size;
	_fitness = 0;
	_fitnessRate = 0.0;
	_genes.resize(size);
}

void CChromosome::initGenes()
{
	double random;
	for (int i = 0; i < _chromeLength; i++) {
		random = rand() / (double)RAND_MAX;
		_genes[i] = random > 0.8 ? 1 : 0;
	}
}

void CChromosome::setGenes(std::vector<int> genes)
{
	for (int i = 0; i < _chromeLength; i++) _genes[i] = genes[i];
	

}

void CChromosome::copyChromosome(CChromosome chrom)
{
	_chromeLength = chrom.getChromosomeLength();
	std::vector<int> srcGenes = chrom.getGenes();
	setGenes(srcGenes);
	_fitness = chrom.getFitness();
	_fitnessRate = chrom.getFitnessRate();
}

void CChromosome::calcFitness()
{
	_fitness = 0;
	for (int i = 0; i < _chromeLength; i++) _fitness += _genes[i];
}

void CChromosome::draw()
{
	for (int i = 0; i < _chromeLength; i++)
		std::cout << _genes[i] << "\n";
	
		std::cout <<" ===> " << _fitness << " : " << _fitnessRate << "\n";
	
}
