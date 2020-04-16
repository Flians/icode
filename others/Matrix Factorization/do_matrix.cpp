/**
 * Process the matrix using LU, Gram-Schmidt, Householder, Givens Factorization
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

#define EPS 1e-07

// print the matrix, and set precision 7
void print_matrix(const std::vector< std::vector<double> >& input) {
    for (std::vector< std::vector<double> >::const_iterator row = input.begin(); row != input.end(); row++)
    {
        for (std::vector<double>::const_iterator cow = row->begin(); cow != row->end(); cow++)
        {
            std::cout << std::fixed << std::setprecision(7) << std::setw(14) << (std::fabs(*cow)<EPS?0:*cow) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// input the matrix from the control element by element
void input_matrix(std::vector< std::vector<double> > *input)
{
    int m=0, n=0, i=0, j=0;
    double temp;
    std::vector<double> line;
    while(m <= 0 || n <= 0)
    {
        std::cout << "please input integer m and n (m>0, n>0): ";
        std::cin >> m >> n;
    }
    std::cout << "please the m*n matrix A: " << std::endl;
    for(; i<m; i++)
    {
        line.clear();
        for(j=0; j<n; j++)
        {
            std::cin >> temp;
            line.push_back(temp);
        }
        input->push_back(line);
    }
    line.clear();
}

// construct the identity matrix
bool construct_IM(std::vector< std::vector<double> > *P){
    if(P->size() != P->at(0).size())
    {
        std::cout << "Failed: It's not a square matrix in construct_IM!" << std::endl;
        return false;
    }
    // make all elements of P 0
    P->assign(P->size(), std::vector<double>(P->at(0).size(), 0));
    unsigned i=0;
    for(; i<P->size(); i++)
    {
        P->at(i).at(i)=1;
    }
    return true;
}

// calculate (1/a)*vector
void calculate_vector_nm(std::vector< std::vector<double> >& vector, int index, double a){
    unsigned i=0, j=0;
    for(; i<vector.at(0).size(); i++)
    {
        // (1/a) * each cow of all the matrix
        if((unsigned)index==vector.at(0).size())
        {
            for(j=0; j<vector.size(); j++)
            {
                vector.at(j).at(i) /= a;
            }
        // (1/a) * the index cow of all the matrix
        }else{
            for(j=0; j<vector.size(); j++)
            {
                vector.at(j).at(index) /= a;
            }
            break;
        }
    }
}

// calculate the product (vector1)T*vector2 (row vector * cow vector)
double calculate_vector_product(std::vector< std::vector<double> > vector1, int index1, \
                                std::vector< std::vector<double> > vector2, int index2, \
                                int row_begin=0){
    if(vector1.size() != vector2.size())
    {
        std::cout << "Failed: the size of vector1 is not equal to the size of vector2 in calculate_vector_product!" << std::endl;
        return __DBL_MIN__;
    }
    // row_begin represents the starting position of line index1(2) of text vecto1(2)
    unsigned i=row_begin;
    double normal=0.0;
    for(; i<vector1.size(); i++)
        normal += vector1.at(i).at(index1)*vector2.at(i).at(index2);
    return normal;
}

// calculate the mul vector1*(vector2)T (cow vector * row vector)
bool calculate_vector_mul(std::vector< std::vector<double> > vector1, int index1, \
                            std::vector< std::vector<double> > vector2, int index2, \
                            std::vector< std::vector<double> >& result, \
                            int row_begin=0){
    if(vector1.size() != result.size() || vector2.size() != result.at(0).size())
    {
        std::cout << "Failed: vector1.size() * vector2.size() is not equal to the size of result in calculate_vector_mul!" << std::endl;
        return false;
    }
    // row_begin represents the starting position of line index1(2) of text vecto1(2)
    unsigned i=row_begin, j=0;
    for(; i<vector1.size(); i++)
    {
        for(j=row_begin; j<vector2.size(); j++)
        {
            result.at(i).at(j) = vector1.at(i).at(index1)*vector1.at(j).at(index1);
        }
    }
    return true;
}

// calculate the mul matrix1*matrix2
bool calculate_matrix_mul(std::vector< std::vector<double> > matrix1, \
                            std::vector< std::vector<double> > matrix2, \
                            std::vector< std::vector<double> >& result){
    if(matrix1.at(0).size() != matrix2.size())
    {
        std::cout << "Failed: the size of matrix1 is not equal to the size of matrix2 in calculate_matrix_mul!" << std::endl;
        return false;
    }
    unsigned i=0, j=0, k=0;
    for(; i<matrix1.size(); i++)
    {
        for(j=0; j<matrix2.at(0).size(); j++)
        {
            double normal=0.0;
            for(k=0; k<matrix1.at(0).size(); k++)
                normal += matrix1.at(i).at(k)*matrix2.at(k).at(j);
            result.at(i).at(j) = normal;
        }
    }
    return true;
}

// get (A)T
void transpose(std::vector< std::vector<double> > matrix, std::vector< std::vector<double> >& matrixT){
    unsigned i=0, j=0;
    for(; i<matrixT.size(); i++)
    {
        for(j=0; j<matrixT.at(0).size(); j++)
        {
            matrixT.at(i).at(j) = matrix.at(j).at(i);
        }
    }
}

// calculate the subtraction result = vector1 - a*vector2
bool calculate_vector_subtraction(std::vector< std::vector<double> > vector1, int index1, \
                                  std::vector< std::vector<double> > vector2, int index2, \
                                  double a, \
                                  std::vector< std::vector<double> > &result, int index,\
                                  int row_begin=0){
    if(vector1.size() != vector2.size() || result.size() != vector1.size())
    {
        std::cout << "Failed: the size of vector1 is not equal to the size of vector2 or result in calculate_vector_subtraction!" << std::endl;
        return false;
    }
    unsigned i=row_begin,j=0;
    for(; i<vector1.at(0).size(); i++)
    {
        // (1/a) * each cow of all the matrix
        if(index1==index2 && (unsigned)index1==vector1.at(0).size() && (unsigned)index2==vector2.at(0).size())
        {
            for(j=row_begin; j<vector1.size(); j++)
                result.at(j).at(i) = vector1.at(j).at(i) - a*vector2.at(j).at(i);
        // (1/a) * the index cow of all the matrix
        }else{
            for(j=row_begin; j<vector1.size(); j++)
                result.at(j).at(index) = vector1.at(j).at(index1) - a*vector2.at(j).at(index2);
            break;
        }
    }
    return true;
}

// process the matrix using the LU Factorization
// for type=0, A=LU
// for type=1, PA=LU, using partial pivoting
bool doLU(int type, std::vector< std::vector<double> > input, std::vector< std::vector<double> > *P, std::vector< std::vector<double> > *L, std::vector< std::vector<double> > *U)
{
    int n = input.size(), i=0, j=0, temp;
    if((unsigned)n!=input.at(0).size())
    {
        std::cout << "Failed: It's not a n*n matrix, and can't be processed by the LU Factorization!" << std::endl;
        return false;
    }
    // traverse the pivots
    for(i = 0; i < n-1; i++)
    {
        if(type){
            temp = i;
            // swap the input[i] with the input[j] whose input[j][i] is max
            for(j=i+1; j<n; j++)
            {
                if(std::fabs(input.at(temp).at(i)) < std::fabs(input.at(j).at(i))){
                    temp = j;
                }
            }
            std::swap(input.at(i), input.at(temp));
            std::swap(L->at(i), L->at(temp));
            std::swap(P->at(i), P->at(temp));
        }
        // row echelon
        for(j=i+1; j<n; j++)
        {
            // the pivots are not equal to 0.
            if(input.at(i).at(i) == 0)
            {
                std::cout << "Failed: Because there exists a zero pivot, this matrix can't be processed using LU Factorization!" << std::endl;
                return false;
            }
            L->at(j).at(i) = input.at(j).at(i)/input.at(i).at(i);
            for(int k = i+1; k < n; k++)
                input.at(j).at(k) = input.at(j).at(k) - input.at(i).at(k)*L->at(j).at(i);
            input.at(j).at(i) = 0;
            L->at(i).at(i) = 1;
        }
    }
    L->at(n-1).at(n-1) = 1;
    U->assign(input.begin(), input.end());
    return true;
}

// process the matrix using the QR(Gram-Schmidt)
bool doQR(std::vector< std::vector<double> > input, std::vector< std::vector<double> > *Q, std::vector< std::vector<double> > *R)
{
    unsigned i=0, j=0;
    for(; i<input.at(0).size(); i++)
    {
        for(j=0; j<i; j++)
        {
            R->at(j).at(i)=calculate_vector_product(input, j, input, i);
            if(R->at(j).at(i) == __DBL_MIN__)
            {
                std::cout << "Failed: it happened in doQR!" << std::endl;
                return false;
            }
        }
        for(j=0; j<i; j++)
        {
            if(!calculate_vector_subtraction(input, i, input, j, R->at(j).at(i), input, i)){
                std::cout << "Failed: it happened in doQR!" << std::endl;
                return false;
            }
        }
        R->at(i).at(i) = std::sqrt(calculate_vector_product(input, i, input, i));
        calculate_vector_nm(input, i, R->at(i).at(i));
    }
    Q->assign(input.begin(), input.end());
    R->assign(R->begin(), R->begin() + (input.size()>input.at(0).size()?input.at(0).size():input.size()));
    return true;
}

// process the matrix using the Householder reduction
bool doHouseholder(std::vector< std::vector<double> > input, std::vector< std::vector<double> > *P, std::vector< std::vector<double> > *Q, std::vector< std::vector<double> > *R)
{
    unsigned num = input.size()>input.at(0).size()?input.at(0).size():input.size()-1;
    unsigned i=0, j=0;
    double temp=0.0, normal_A1=0.0;
    std::vector< std::vector<double> > temp_Ri(P->size(), std::vector<double>(P->at(0).size(), 0));
    std::vector< std::vector<double> > IM(P->size(), std::vector<double>(P->size(), 0));
    if(!construct_IM(&IM)){
        std::cout << "Failed: it happened in doHouseholder!" << std::endl;
        return false;
    }
    for(; i<num; i++)
    {
        // construct the Rk={(I,0)T,(0,rk)T}
        if(i!=0){
            temp_Ri.at(i-1).at(i-1)=1;
            for(j=i; j<temp_Ri.size(); j++)
            {
                temp_Ri.at(j).at(i-1)=0;
            }
            for(j=i; j<temp_Ri.at(0).size(); j++)
            {
                temp_Ri.at(i-1).at(j)=0;
            }
        }
        normal_A1=std::sqrt(calculate_vector_product(input, i, input, i, i));
        input.at(i).at(i) -= normal_A1;
        calculate_vector_mul(input, i, input, i, temp_Ri, i);
        temp = 2.0/calculate_vector_product(input, i, input, i, i);
        if(!calculate_vector_subtraction(IM, IM.size(), temp_Ri, temp_Ri.size(), temp, temp_Ri, temp_Ri.size(), i)){
            std::cout << "Failed: it happened in doHouseholder!" << std::endl;
            return false;
        }
        // recover the matrix input
        input.at(i).at(i) += normal_A1;
        // calculate ...*P23*P13*P12
        calculate_matrix_mul(temp_Ri, *P, *P);
        // calculate ...*P23*P13*P12*A
        calculate_matrix_mul(temp_Ri, input, input);
        for(j=i+1; j<input.size(); j++)
        {
            input.at(j).at(i)=0;
        }
    }
    transpose(*P,*Q);
    R->assign(input.begin(), input.begin() + (input.size()>input.at(0).size()?input.at(0).size():input.size()));
    return true;
}

// process the matrix using the Givens reduction
bool doGivens(std::vector< std::vector<double> > input, std::vector< std::vector<double> > *P, std::vector< std::vector<double> > *Q, std::vector< std::vector<double> > *R)
{
    
    unsigned num = input.size()>input.at(0).size()?input.at(0).size():input.size();
    unsigned i=0, j=0;
    double temp=0.0;
    std::vector< std::vector<double> > temp_Ri(P->size(), std::vector<double>(P->at(0).size(), 0));
    std::vector< std::vector<double> > IM(P->size(), std::vector<double>(P->size(), 0));
    
    for(; i<num; i++)
    {
        for(j=i+1; j<input.size(); j++)
        {
            if(!construct_IM(&IM)){
                std::cout << "Failed: it happened in doGivens!" << std::endl;
                return false;
            }
            // construct orthogonal matrix P
            temp = std::sqrt(input.at(i).at(i)*input.at(i).at(i) + input.at(j).at(i)*input.at(j).at(i));
            IM.at(i).at(i) = input.at(i).at(i) / temp;
            IM.at(j).at(j) = input.at(i).at(i) / temp;
            IM.at(j).at(i) = -1*input.at(j).at(i) / temp;
            IM.at(i).at(j) = input.at(j).at(i) / temp;

            // calculate ...*P23*P13*P12
            calculate_matrix_mul(IM, *P, *P);
            // calculate ...*P23*P13*P12*A
            calculate_matrix_mul(IM, input, input);
        }
    }

    transpose(*P,*Q);
    R->assign(input.begin(), input.begin() + (input.size()>input.at(0).size()?input.at(0).size():input.size()));
    return true;
}

int main(int argc, char const *argv[])
{
    int op=0;
    std::vector< std::vector<double> > input;
    input_matrix(&input);
    std::vector< std::vector<double> > P(input.size(), std::vector<double>(input.size(), 0)), \
                                       Q(input.size(), std::vector<double>(input.size(), 0)), \
                                       R(input.at(0).size(), std::vector<double>(input.at(0).size(), 0));
    while((std::cout << "please input the operation: \n" \
                     << "\t0.print the matrix\n" \
                     << "\t1.LU Factorization(A=LU)\n" \
                     << "\t2.LU Factorization(PA=LU)\n" \
                     << "\t3.QR(Gram-Schmidt) Factorization\n" \
                     << "\t4.Householder reduction\n" \
                     << "\t5.Givens reduction\n" \
                     << "\tOther.exit\n>>> ") and (std::cin >> op))
    {
        // set P identity matrix
        P.assign(input.size(), std::vector<double>(input.size(), 0));
        if(!construct_IM(&P)){
            std::cout << "Failed: it happened in main!" << std::endl;
            return 0;
        }
        // set all elements of P, Q and R zero
        Q.assign(input.size(), std::vector<double>(input.size(), 0));
        R.assign(input.at(0).size(), std::vector<double>(input.at(0).size(), 0));
        switch(op) {
            // print the matrix
            case 0:
                std::cout << ">>> A: " << std::endl;
                print_matrix(input);
                break;
            // LU Factorization(A=LU)
            case 1:
                if(doLU(0,input, &P, &Q, &R)){
                    std::cout << ">>> The result of A=UL: " << std::endl;
                    std::cout << ">>> L: " << std::endl;
                    print_matrix(Q);
                    std::cout << ">>> U: " << std::endl;
                    print_matrix(R);
                }
                break;
            // LU Factorization(PA=LU)
            case 2:
                if(doLU(1,input, &P, &Q, &R)){
                    std::cout << ">>> The result of PA=UL: " << std::endl;
                    std::cout << ">>> P: " << std::endl;
                    print_matrix(P);
                    std::cout << ">>> L: " << std::endl;
                    print_matrix(Q);
                    std::cout << ">>> U: " << std::endl;
                    print_matrix(R);
                }
                break;
            // QR(Gram-Schmidt)
            case 3:
                if(doQR(input, &Q, &R)){
                    std::cout << ">>> The result of A=QR: " << std::endl;
                    std::cout << ">>> Q: " << std::endl;
                    print_matrix(Q);
                    std::cout << ">>> R: " << std::endl;
                    print_matrix(R);
                }
                break;
            // Householder reduction
            case 4:
                if(doHouseholder(input, &P, &Q, &R)){
                    std::cout << ">>> The result of A=QR: " << std::endl;
                    std::cout << ">>> Q: " << std::endl;
                    print_matrix(Q);
                    std::cout << ">>> R: " << std::endl;
                    print_matrix(R);
                }
                break;
            // Givens reduction
            case 5:
                if(doGivens(input, &P, &Q, &R)){
                    std::cout << ">>> The result of A=QR: " << std::endl;
                    std::cout << ">>> Q: " << std::endl;
                    print_matrix(Q);
                    std::cout << ">>> R: " << std::endl;
                    print_matrix(R);
                }
                break;
            // exit
            default:
                P.clear();
                Q.clear();
                R.clear();
                return 0;
        }
    }
    return 0;
}