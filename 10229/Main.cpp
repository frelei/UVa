/// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1170

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int mod;

struct Matrix
{
  long long val[2][2];
}aux;

// multiply m1 and m2 and store in m
void mult(Matrix &m, Matrix &m1, Matrix &m2)
{
    m.val[0][0] = 0;
    m.val[0][1] = 0;
    m.val[1][0] = 0;
    m.val[1][1] = 0;

    for(int i = 0; i < 2; i++)
    {
      for(int j = 0; j < 2; j++)
      {
          for(int k = 0; k < 2; k++)
          {
              m.val[i][k] = (m.val[i][k] + m1.val[i][j] * m2.val[j][k]) % mod;
          }
       }
    }
}


Matrix pow(Matrix &M, int n)
{
	Matrix ret;
  ret.val[0][0] = 1;
  ret.val[1][1] = 1;
  ret.val[1][0] = 0;
  ret.val[0][1] = 0;

	if(n == 0) return ret;
	if(n == 1) return M;

	Matrix P = M;

	while(n != 0)
  {
	    if(n & 1)
      {
	        aux = ret;
	        mult(ret,aux,P);
	    }
      n = n / 2;
	    aux = P;
	    mult(P,aux,aux);
	}
    return ret;
}


int main()
{
  int n,m;

  Matrix M;
  M.val[0][0] = 1;
  M.val[0][1] = 1;
  M.val[1][0] = 1;
  M.val[1][1] = 0;

  while(cin >> n >> m)
  {
    mod = pow(2, m);
    cout << pow(M,n).val[0][1] << endl;
  }

  return 0;
}
