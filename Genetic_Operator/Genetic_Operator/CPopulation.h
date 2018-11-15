#pragma once
#include<vector>
#include"CChromosome.h"
class CPopulation
{
	std::vector<CChromosome> _population;
	std::vector<CChromosome> _oldPop;
	CChromosome _bestChromosome;
	
	//TEST
	std::vector<int> _position;

	int _popSize;
	int _chromSize;
	int _totalFitness; // ��ü chromosome�� �� ���Ѱ�.
	double _crossoverRate;
	double _mutationRate;

public:
	CPopulation(int pSize, int cSize, double cR, double mR);
	~CPopulation() {}

	CChromosome selection();
	void crossover(CChromosome &chrom1, CChromosome &chrom2);
	void mutation(CChromosome &chrom);
	void evaluation();
	
	void copyPopToParent(); // ������ population�� oldpop�� ����
	void pushChromToPop(int pos, CChromosome chrom);

	// getters
	CChromosome getBestChromosome() { return _bestChromosome; }
	int getWorstChromIndex();

	int getPopSizse() { return _popSize; }
	int getChromSize() { return _chromSize; }
	double getCrossoverRate() { return _crossoverRate; }
	double getMutationRate() { return _mutationRate; }

	void draw();
};

