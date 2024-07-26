#ifndef RUBIKSCUBE3DARRAY_H
#define RUBIKSCUBE3DARRAY_H

#include "RubiksCube.h"

class RubiksCube3dArray : public RubiksCube {
public:
    RubiksCube3dArray();
    COLOR getColor(FACE face, unsigned row, unsigned col) const override;
    bool isSolved() const override;
    void print() const;

    RubiksCube &f() override;
    RubiksCube &fPrime() override;
    RubiksCube &f2() override;
    RubiksCube &u() override;
    RubiksCube &uPrime() override;
    RubiksCube &u2() override;
    RubiksCube &l() override;
    RubiksCube &lPrime() override;
    RubiksCube &l2() override;
    RubiksCube &r() override;
    RubiksCube &rPrime() override;
    RubiksCube &r2() override;
    RubiksCube &d() override;
    RubiksCube &dPrime() override;
    RubiksCube &d2() override;
    RubiksCube &b() override;
    RubiksCube &bPrime() override;
    RubiksCube &b2() override;
    
    bool operator==(const RubiksCube3dArray &r1) const;
    RubiksCube3dArray &operator=(const RubiksCube3dArray &r1);
    
      struct Hash3d {
        size_t operator()(const RubiksCube3dArray &r1) const {
            std::string str = "";
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        str += r1.cube[i][j][k];
                    }
                }
            }
            return hash<std::string>()(str);
        }
    };
    
private:
    char cube[6][3][3];
    void rotateFace(int faceIndex);
};

#endif // RUBIKSCUBE3DARRAY_H


