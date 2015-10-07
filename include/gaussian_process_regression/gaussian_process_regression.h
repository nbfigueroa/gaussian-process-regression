#ifndef GPR_H
#define GPR_H


# include <eigen3/Eigen/Dense>
# include <iostream>

//#ifdef USE_DOUBLE_PRECISION
//typedef double REALTYPE;
//#else
//typedef float REALTYPE;
//#endif



template<typename REALTYPE>
class GaussianProcessRegression{

  typedef Eigen::Matrix<REALTYPE,Eigen::Dynamic,Eigen::Dynamic> MatrixXr;
  typedef Eigen::Matrix<REALTYPE,Eigen::Dynamic,1> VectorXr;

  MatrixXr input_data_;
  MatrixXr output_data_;
  MatrixXr KXX;
  MatrixXr KXX_;
  MatrixXr KXx;
  MatrixXr KxX;

  int n_data_;
  bool b_need_prepare_;

  double l_scale_;
  double sigma_f_;
  double sigma_n_;

  VectorXr dist;

  VectorXr regressors;
  
public:
  GaussianProcessRegression(){}
  GaussianProcessRegression(int inputDim, int outputDim);

  void SetHyperParams(double l, double f, double n){l_scale_ = l; sigma_f_ = f; sigma_n_ = n;};
  void AddTrainingData(VectorXr newInput, VectorXr newOutputs);

  REALTYPE SQEcovFuncD(VectorXr x1,VectorXr x2);
  void Debug();


  MatrixXr SQEcovFunc(MatrixXr x1);
  VectorXr SQEcovFunc(MatrixXr x1, VectorXr x2);

  void PrepareRegression(bool force_prepare = false);
  VectorXr DoRegression(const VectorXr & inp,bool prepare = false);
  int get_n_data(){return n_data_;};
  void ClearTrainingData();
};

#include "gaussian_process_regression.hxx"
#endif //GPR_H
