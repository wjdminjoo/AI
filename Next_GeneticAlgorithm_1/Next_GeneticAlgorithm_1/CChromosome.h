#pragma once
#include<vector>

class CChromosome
{
	std::vector<int> _genes; // individual
	int _chromeLength; // ����
	int _fitness; //  ���յ�
	double _fitnessRate; // selection���� ���� Ȯ�� ��. (0.0 ~ 0.1)
public:
	CChromosome();
	~CChromosome();


	void resetChromosome(int size);
	void initGenes();
	
	int getChromosomeLength() { return _chromeLength; }
	int getFitness() { return _fitness; }
	double getFitnessRate() { return _fitnessRate; }
	void setFitnessRate(double random) { _fitnessRate = random; }

	std::vector<int> getGenes() { return _genes; }
	void setGenes(std::vector<int> genes);

	void copyChromosome(CChromosome chrom);
	void calcFitness(); // ���յ� ���.
	void draw();

};

