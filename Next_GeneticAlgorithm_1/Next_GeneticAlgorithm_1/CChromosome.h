#pragma once
#include<vector>

class CChromosome
{
	std::vector<int> _genes; // individual
	int _chromeLength; // 길이
	int _fitness; //  적합도
	double _fitnessRate; // selection에서 사용될 확률 값. (0.0 ~ 0.1)
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
	void calcFitness(); // 적합도 계산.
	void draw();

};

