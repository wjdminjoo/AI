#pragma once
#include<vector>
static struct _position{
	int _x;
	int _y;
};



class CChromosome
{
	std::vector<int> _genes; // 하나의 크로모섬
	std::vector<_position> _pos;
	int _chromSize;
	int _fitness;
	double _fitnessRate;

public:
	CChromosome();
	~CChromosome() {}
	CChromosome(int size);

	void resetChromosome(int size);
	void initChromosome();

	void calcFitness();
	
	int getChromsSize() { return _chromSize; }
	int getFitness() { return _fitness; }
	double getFitnessRate() { return _fitnessRate; }
	void setFitnessRate(double from) { _fitnessRate = from; }

	std::vector<int> getChromosome() { return _genes; }
	void setChromosome(std::vector<int> genes) { _genes = genes; }

	int decoding();

	int trans(int* num);

	void draw();
};

