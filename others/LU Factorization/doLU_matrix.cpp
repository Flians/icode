#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>

// print the matrix.
void print_matrix(std::vector< std::vector<double> > *input) {
    for (std::vector< std::vector<double> >::iterator row = input->begin(); row != input->end(); row++)
    {
        for (std::vector<double>::iterator cow = row->begin(); cow != row->end(); cow++)
        {
            std::cout << *cow << " ";
        }
        std::cout << std::endl;
    }
}

// input the matrix from the file line by line.
void input_matrix_byline(std::vector< std::vector<double> > *input) {
    std::string file_addr;
    std::vector<double> line;
    std::fstream infile;
    while(!infile.is_open()){
        std::cout << "please input the correct file path: " << std::endl;
        std::getline(std::cin, file_addr);
        infile.open(file_addr.c_str(), std::ifstream::in);
    }
    std::string temp;
    double item;
    while(!infile.eof()){
        std::getline(infile, temp);
        std::stringstream ss(temp);
        while(ss >> item)
            line.push_back(item);
        // filter the empty line.
        if(!line.empty())
            input->push_back(line);
        line.clear();
    }
    infile.close();
}

// input the matrix from the file char by char.
void input_matrix_bychar(std::vector< std::vector<double> > *input) {
    std::string file_addr;
    std::vector<double> line;
    std::fstream infile;
    // allow >> to read space or table etc.
    infile >> std::noskipws;
    while(!infile.is_open()){
        std::cout << "please input the correct file path: " << std::endl;
        std::getline(std::cin, file_addr);
        infile.open(file_addr.c_str(), std::ifstream::in);
    }
    double temp = 0;
    char space;
    while (!infile.eof())
    {
        if(infile.peek() == '\n' && !line.empty())
        {
            input->push_back(line);
            line.clear();
        }
        else if((infile.peek() <= '9' && infile.peek() >= '0') || infile.peek()=='-' || infile.peek()=='+')
        {
            infile >> temp;
            line.push_back(temp);
        }
        else
        {
            // process the space and table in the end of each line.
            infile >> space;
        }
    }
    // process the institution that there is no '\n' in last line.
    if(!line.empty())
    {
        input->push_back(line);
        line.clear();
    }
    infile.close();
}

// process the matrix using the LU method.
void doLU(std::vector< std::vector<double> > *input, std::vector< std::vector<double> > *L)
{
    int n = input->size();
    // traverse the pivots
    for(int i = 0; i < n-1; i++)
    {
        // row echelon
        for(int j=i+1; j < n; j++)
        {
            // the pivots are not equal to 0.
            if(input->at(i).at(i) == 0)
            {
                std::cout << "this matrix cant be processed using LU method!" << std::endl;
                return;
            }
            L->at(j).at(i) = input->at(j).at(i)/input->at(i).at(i);
            for(int k = i+1; k < n; k++)
                input->at(j).at(k) -= input->at(i).at(k)*L->at(j).at(i);
            input->at(j).at(i) = 0;
            L->at(i).at(i) = 1;
        }
    }
    L->at(n-1).at(n-1) = 1;
}

int main()
{
    std::vector< std::vector<double> > input;
    // input the matrix from file.
    //input_matrix_bychar(&input);
    input_matrix_byline(&input);

    // print the input
    std::cout << "A=" << std::endl;
    print_matrix(&input);
    for (std::vector< std::vector<double> >::iterator iter = input.begin(); iter != input.end(); iter++)
    {
        if(iter->size() != input.size())
        {
            std::cout << "It's not a n*n matrix!" << std::endl;
            return 0;
        }
    }

    std::vector< std::vector<double> > L(input.size(), std::vector<double>(input.size()));
    // process LU decomposition.
    doLU(&input, &L);
    // print the matrix L and U.
    std::cout << "L=" << std::endl;
    print_matrix(&L);
    std::cout << "U=" << std::endl;
    print_matrix(&input);
    getchar();
    return 0;
}
