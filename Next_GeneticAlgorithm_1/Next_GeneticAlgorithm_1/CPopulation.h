#pragma once
#include <vector>

class CChromosome;
class CPopulation
{

	std::vector<CChromosome> _Population;
	std::vector<CChromosome> _oldPopulation;


	int _populationSize;
	int _geneSize;

	double _crossoverRate;
	double _mutationRate;

	int _totalFitness;
public:



	CPopulation(int popSize, int geneSize, double cRate, double mRate);
	~CPopulation();

	inline int getPopSize() { return _populationSize; }
	inline double getCrossoverRate() { return _crossoverRate; }
	inline double getMutationRate() { return _mutationRate; }

	inline std::vector<CChromosome> getOldPop() { return _oldPopulation; }
	inline std::vector<CChromosome> getPopulation() { return _Population; }
	inline void setPopulation(std::vector<CChromosome> chrom) { _Population = chrom; }


	// Genetic operators
	CChromosome selection();
	void crossover(CChromosome &genes1, CChromosome & genes2);
	void mutation(CChromosome &genes);
	void evaluate();

	void copyPopulationParent();
	void setChromosome(int pos, CChromosome src);

	// fitness가 가장 좋은 chrom 선별
	CChromosome getBestChromosome(std::vector<CChromosome> pop);
	// fitness가 가장 나쁜 chrom의 위치
	int getWorstChromIndex(std::vector<CChromosome> pop);

	
	
	void draw(std::vector<CChromosome> pop);
};

