#include"CChromosome.h"
#include"CPopulation.h"
#include<iostream>
#include<time.h>

int main() {
	
	srand((unsigned)time(NULL));

	// 5자리의 chromosome이 10개.
	// 70%의 크로스 오버, 0.01의 적합도
	CPopulation simpleGA(30, 20, 0.8, 0.01);
	CChromosome bestChrom = simpleGA.getBestChromosome();
	int bestFitness = bestChrom.getFitness();
	int popSize = simpleGA.getPopSizse();

	int generation = 0;
	int solution = simpleGA.getChromSize();

	double crossoverRate = simpleGA.getCrossoverRate();

	simpleGA.draw();


	// processing Genetic Algorithm

	while (1) {
		generation++;

		std::cout << "==================================\n";
		std::cout << "Generation : " << generation << "\n";
		simpleGA.draw();
		std::cout << "BEST : ";
		bestChrom.draw();

		if (bestFitness == solution) break;
		int chromSize = simpleGA.getChromSize();
		CChromosome select1(chromSize);
		CChromosome select2(chromSize);


		int i = 0;
		double rnd;
		do {
			rnd = rand() / (double)RAND_MAX;
			if (rnd < crossoverRate) {
				select1 = simpleGA.selection();
				select2 = simpleGA.selection();

				simpleGA.crossover(select1, select2);

				simpleGA.mutation(select1);
				simpleGA.mutation(select2);


				select1.calcFitness();
				select2.calcFitness();

				simpleGA.pushChromToPop(i, select1);
				simpleGA.pushChromToPop(i+1, select2);

				i += 2;

			}
		} while (i < popSize);

		int worstIndex = simpleGA.getWorstChromIndex();
		simpleGA.pushChromToPop(worstIndex, bestChrom);

		simpleGA.evaluation();
		simpleGA.copyPopToParent();

		bestChrom = simpleGA.getBestChromosome();
		bestFitness = bestChrom.getFitness();
	}

	system("pause");
	return 0;
}