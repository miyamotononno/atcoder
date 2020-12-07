#include <cmath>
#include <iostream>
#include <Eigen/Dense>
#define PI 3.141592653589793

using namespace std;
using Eigen::MatrixXd;
struct C{int x, y;};

template <typename T>
class Transform2d {
  private:
    MatrixXd Tr; // 平行移動
    MatrixXd S; // 拡大縮小
    MatrixXd Ro; // 回転
    MatrixXd Re; // 鏡写し
    MatrixXd Sk; // スキュー、剪断

    bool inputCheck(MatrixXd& O) {
      if (O.rows()==3 && O.cols()==1) {
        O(2,0)=1;
        return true;
      }
      return false;
    }
    enum axisEnum: char {
      x='x',y='y'
    };

  public:
    Transform2d(): Tr(3,3),S(3,3),Ro(3,3),Re(3,3),Sk(3,3) {
      for (int i=0; i<3; i++) {
        Tr(i, i) = (T)1;
        Sk(i, i) = (T)1;
      }
      S(2,2) = (T)1;
      Ro(2,2) = (T)1;
      Re(2,2) = (T)1;
    }

    double radian(double degree) {
      return PI*(degree/360.0);
    }

    MatrixXd translate(MatrixXd& I, T tx, T ty) {
      if (!inputCheck(I)) throw invalid_argument("invalid input shape");
      Tr(0,2) = tx;Tr(1,2) = ty;
      return Tr*I;
    }

    MatrixXd scale(MatrixXd& I, T sx, T sy, T cx=0, T cy=0) { // defaultは中心が原点
      if (!inputCheck(I)) throw invalid_argument("invalid input shape");
      S(0,0)=sx;
      S(1,1)=sy;
      if (cx==0 && cy==0) return S*I;
      return translate(cx, cy)*S*translate(-cx, -cy)*I;
    }

    MatrixXd rotate(MatrixXd& I, T theta, T cx=0, T cy=0) { // defaultは中心が原点
      double r = radian(theta);
      Ro(0,0) = cos(r);
      Ro(0,1) = -sin(r);
      Ro(1,0) = cos(r);
      Ro(1,1) = -sin(r);
      if (cx==0 && cy==0) return Ro*I;
      return translate(cx, cy)*Ro*translate(-cx, -cy)*I;
    }

    MatrixXd reflectionByAxis(MatrixXd& I, axisEnum axis=axisEnum::x) {
      if (axis == axisEnum::x) {
        Re(0,0)=1;Re(1,1)=-1;
      } else {
        Re(0,0)=-1;Re(1,1)=1;
      }
      return Re*I;
    }

    MatrixXd reflection(MatrixXd& I, T theta,  T ax=0, T ay=0) { // (ax, ay)を通り、角度がthetaの直線と鏡写し
      MatrixXd res = Ro(-theta)*T(-ax, -ay)*I;
      return T(ax, ay)*Ro(ax,ay)*reflectionByAxis(res);
    }

    MatrixXd skew(MatrixXd& I, T theta, axisEnum axis=axisEnum::x) {
      double r = radian(theta);
      if (axis == axisEnum::x) {
        Sk(0,1) = tan(r); 
      } else {
        Sk(1,0) = tan(r);
      }
      return Sk*I;
    }
};

int main() {
    Transform2d<double> tr;
    MatrixXd mat(3, 1);
    mat(0,0)=1;mat(1,0)=1;
}