#include <iostream>
#include <C:\Users\HP\Documents\Obj_arham\eigen\Eigen\Dense>
#include <chrono>
#include <numeric>
#include <fstream>
#include <string>

using namespace std::chrono;
using namespace::Eigen;
using namespace::std;

int testEigen(int loopVal)
{
	int time[20]= {0};
	std::ofstream myfile;
	myfile.open ("SolveResults.csv");
	//testing eigen part 1 of Q1
	//looping over till we achieve a 10000x10000 matrix
	for (int i=50;i<loopVal;i=i+50){
	
		MatrixXd A(i,i);
		VectorXd b(i);
		A.setRandom();
		b.setRandom();
		
		// Get starting timepoint
		auto start = high_resolution_clock::now();
		cout << A.colPivHouseholderQr().solve(b) << endl;
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		time[i/50] = duration.count();
		myfile << i << 'x' << i << ','<< time[i/50]<<endl;

	}
	myfile.close();
	return 0;
}