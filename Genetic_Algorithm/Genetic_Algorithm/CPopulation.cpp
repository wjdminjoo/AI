#include "CPopulation.h"
#include<iostream>


CPopulation::CPopulation(int pSize, int cSize, double cR, double mR) :
	_popSize(pSize), _chromSize(cSize), _crossoverRate(cR), _mutationRate(mR), _totalFitness(0)
{

	_population.resize(pSize);
	_oldPop.resize(pSize);
	for (int i = 0; i < pSize; i++) _population[i].resetChromosome(cSize);

	evaluation();
	copyPopToParent();
}

CPopulation::~CPopulation()
{
}

// rouleette wheel method
CChromosome CPopulation::selection()
{

	int selectIndex = 0;
	double rnd = rand() / (double)RAND_MAX;
	double selRate = 0.0;
	for (int i = 0; i < _popSize; i++) {
		selRate += _oldPop[i].getFitnessRate();
		if (selRate > rnd) {
			selectIndex = i;
			break;
		}
	}


	return _oldPop[selectIndex];
}


// 1 point crossover
void CPopulation::crossover(CChromosome & chrom1, CChromosome & chrom2)
{
	int crossPoint = rand() % _chromSize;
	std::vector<int> genes1 = chrom1.getChromosome();
	std::vector<int> genes2 = chrom2.getChromosome();

	for (int i = 0; i < crossPoint; i++) {
		int t = genes1[i];
		genes1[i] = genes2[i];
		genes2[i] = t;
	}
	chrom1.setChromosome(genes1);
	chrom2.setChromosome(genes2);

}

void CPopulation::mutation(CChromosome & chrom)
{
	int mutaitePoint = rand() % _chromSize;
	double rnd = rand() / (double)RAND_MAX;
	if (rnd > _mutationRate)return;

	std::vector<int> genes = chrom.getChromosome();
	genes[mutaitePoint] = 1 - genes[mutaitePoint];
	chrom.setChromosome(genes);

}

void CPopulation::evaluation()
{
	_totalFitness = 0;
	int bestFit = 0;
	int bestChromosomIndex = 0;


	for (int i = 0; i < _popSize; i++) {
		_population[i].calcFitness(); // calc ith chromosome in the pop
		int curFit = _population[i].getFitness();
		if (curFit > bestFit) {
			bestFit = curFit;
			bestChromosomIndex = i;
		}
		_totalFitness += curFit;
	}
	// set fitness rate
	for (int i = 0; i < _popSize; i++) {
		double curFitRate = _population[i].getFitness() / (double)_totalFitness;
		_population[i].setFitnessRate(curFitRate);

	}
	_bestChromosome = _population[bestChromosomIndex];

}

void CPopulation::copyPopToParent()
{
	for (int i = 0; i < _popSize; i++) _oldPop[i] = _population[i];
}

void CPopulation::pushChromToPop(int pos, CChromosome chrom)
{
	_population[pos] = chrom;
}

// return the worst Chromosome`s index in the population
int CPopulation::getWorstChromIndex()
{
	int worstFit = _population[0].getFitness();
	int worstIndex = 0;
	for (int i = 1; i < _popSize; i++) {
		int curFit = _population[i].getFitness();
		if (curFit < worstFit) { // 현재의 fitness가 열성이되어버린 상황.
			worstFit = curFit;
			worstIndex = i;
		}
	}


	return worstIndex;
}

void CPopulation::draw()
{

	for (int i = 0; i < _popSize; i++) _population[i].draw();
}
