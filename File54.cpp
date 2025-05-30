#include "pt4.h"
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

void Solve()
{
    Task("File54");
    string filein,fileout;
    pt>>fileout>>filein;
    ifstream fin(filein,ios::binary);

    ofstream fout(fileout);
    fout << fixed << setprecision(2);

    int num_file,sum,num;
    double average;

    fin.read((char*)&num_file,sizeof(int));
    int  size_of_file_arr[num_file];

    for(int i=0;i<num_file;i++)
    {
        fin.read((char*)&size_of_file_arr[i],sizeof(int));
    }
    
    for(int  j=0;j<num_file;j++)
    {
        int size_of_file=size_of_file_arr[j];
        sum=0;
        for(int i=0;i<size_of_file;i++)
        {
            fin.read((char*)&num,sizeof(int));
            sum+=num;
        }

        average=(sum*1.0)/size_of_file;
        //fout<<average;
        fout.write((char*)&average,sizeof(double));
        ShowD(average);
    }

    fin.close();
    fout.close();

}
