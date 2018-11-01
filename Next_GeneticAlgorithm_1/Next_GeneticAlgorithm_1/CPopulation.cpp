#include "CChromosome.h"
#include "CPopulation.h"
#include<iostream>





CPopulation::CPopulation(int popSize, int geneSize, double cRate, double mRate) :
	_populationSize(popSize), _geneSize(geneSize), _crossoverRate(cRate), _mutationRate(mRate), _totalFitness(0)
{
	_Population.resize(popSize);
	_oldPopulation.resize(popSize);

	// make a pool of chromosomes 
	for (int i = 0; i < popSize; i++) {
		_Population[i].resetChromosome(geneSize);
		_oldPopulation[i].resetChromosome(geneSize);
	}
	evaluate();
	copyPopulationParent();
}

CPopulation::~CPopulation()
{
}



CChromosome CPopulation::selection()
{
	CChromosome selectChrom;
	selectChrom.resetChromosome(_geneSize);
	int selectIndex = 0;

	double random = rand() / (double)RAND_MAX;
	double selectRate = 0.0;
	for (int i = 0; i < _populationSize; i++) {
		selectRate += _oldPopulation[i].getFitnessRate();
		if (selectRate > random) {
			selectIndex = 1;
			break;
		}
	}
	return _oldPopulation[selectIndex];
}

void CPopulation::crossover(CChromosome &chrom1, CChromosome &chrom2)
{
	int crossPoint = rand() % _geneSize;
	std::vector<int> gene1 = chrom1.getGenes();
	std::vector<int> gene2 = chrom2.getGenes();

	for (int i = 0; i < crossPoint; i++) {
		int t = gene1[i];
		gene2[i] = gene1[i];
		gene2[i] = t;
	}
	chrom1.setGenes(gene1);
	chrom2.setGenes(gene2);
}

void CPopulation::mutation(CChromosome & chrom)
{
	double random = rand() / (double)RAND_MAX;
	if (random > _mutationRate)return;

	int mutationPoint = rand() % _geneSize;
	std::vector<int> genes = chrom.getGenes();
	int g = genes[mutationPoint] == 0 ? 1 : 0;
	genes[mutationPoint] = g;
	chrom.setGenes(genes);
}

void CPopulation::evaluate()
{
	_totalFitness = 0;
	for (int i = 0; i < _populationSize; i++) {
		_Population[i].calcFitness();
		_totalFitness += _Population[i].getFitness();
	}
	// set fitness rate for each chromosome

	for (int i = 0; i < _populationSize; i++) {
		double fr = _Population[i].getFitness() / (double)_totalFitness;
		_Population[i].setFitnessRate(fr);
	}
}

void CPopulation::copyPopulationParent()
{
	for (int i = 0; i < _populationSize; i++) //_oldPopulation[i].copyChromosome(_Population[i]);
		_oldPopulation[i] = _Population[i];
}

void CPopulation::setChromosome(int pos, CChromosome src)
{
	//_Population[pos] = src;
	_Population[pos].copyChromosome(src);
}

CChromosome CPopulation::getBestChromosome(std::vector<CChromosome> pop)
{
	CChromosome best;
	best.resetChromosome(_geneSize);
	best = pop[0];
	int fitness = pop[0].getFitness();
	for (int i = 1; i < _populationSize; i++) {
		int curFit = pop[i].getFitness();
		if (fitness < curFit) {
			fitness = curFit;
			best = pop[i];
		}
	}
	return best;
}

int CPopulation::getWorstChromIndex(std::vector<CChromosome> pop)
{
	int worstFIt = pop[0].getFitness();
	int wIndex = 0;
	for (int i = 0; i < _populationSize; i++) {
		if (worstFIt > pop[i].getFitness()) {
			worstFIt = pop[i].getFitness();
			wIndex = 1;
		}
	}

	return wIndex;
}

void CPopulation::draw(std::vector<CChromosome> pop)
{
	for (int i = 0; i < _populationSize; i++)
		pop[i].draw();
	
}
