#include "RubiksCube3dArray.h"
#include <iostream>
using namespace std;
//this function assigns color to each face (i ->face) getColorletter is the color assigned to each face there should be same color
//COLOR(i) uses enum B-0 and so one w=5
RubiksCube3dArray::RubiksCube3dArray() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cube[i][j][k] = RubiksCube::getColorLetter(RubiksCube::COLOR(i));
            }
        }
    }
}

RubiksCube::COLOR RubiksCube3dArray::getColor(RubiksCube::FACE face, unsigned row, unsigned col) const {
    char color = cube[int(face)][row][col];
    switch (color) {
        case 'B': return RubiksCube::COLOR::BLUE;
        case 'R': return RubiksCube::COLOR::RED;
        case 'G': return RubiksCube::COLOR::GREEN;
        case 'O': return RubiksCube::COLOR::ORANGE;
        case 'Y': return RubiksCube::COLOR::YELLOW;
        default:  return RubiksCube::COLOR::WHITE;
    }
}

//returns true if all i->face  has same color in all its cells i has already been assigned colorand for each j,k we check this color
bool RubiksCube3dArray::isSolved() const {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (cube[i][j][k] != RubiksCube::getColorLetter(RubiksCube::COLOR(i))) {
                    return false;
                }
            }
        }
    }
    return true;
}
// this print the cube each face .
// i is the face  and 3*3 cell and each will have some color
void RubiksCube3dArray::print() const {
     cout << "Rubik's Cube:\n\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::UP, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::LEFT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::FRONT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::RIGHT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::BACK, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


void RubiksCube3dArray::rotateFace(int faceIndex) {
    char temp[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            temp[j][2 - i] = cube[faceIndex][i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cube[faceIndex][i][j] = temp[i][j];
        }
    }
}

RubiksCube &RubiksCube3dArray::u() {
    this->rotateFace(int(FACE::UP));
    char temp_arr[3] = {};
    for (int i = 0; i < 3; i++) temp_arr[i] = cube[int(FACE::BACK)][0][2 - i];
    for (int i = 0; i < 3; i++) cube[int(FACE::BACK)][0][2 - i] = cube[int(FACE::LEFT)][0][2 - i];
    for (int i = 0; i < 3; i++) cube[int(FACE::LEFT)][0][2 - i] = cube[int(FACE::FRONT)][0][2 - i];
    for (int i = 0; i < 3; i++) cube[int(FACE::FRONT)][0][2 - i] = cube[int(FACE::RIGHT)][0][2 - i];
    for (int i = 0; i < 3; i++) cube[int(FACE::RIGHT)][0][2 - i] = temp_arr[i];
    return *this;
}

RubiksCube &RubiksCube3dArray::uPrime() {
    this->u();
    this->u();
    this->u();
    return *this;
}

RubiksCube &RubiksCube3dArray::u2() {
    this->u();
    this->u();
    return *this;
}

RubiksCube &RubiksCube3dArray::l() {
    this->rotateFace(int(FACE::LEFT));
    char temp_arr[3] = {};
    for (int i = 0; i < 3; i++) temp_arr[i] = cube[int(FACE::UP)][i][0];
    for (int i = 0; i < 3; i++) cube[int(FACE::UP)][i][0] = cube[int(FACE::BACK)][2 - i][2];
    for (int i = 0; i < 3; i++) cube[int(FACE::BACK)][2 - i][2] = cube[int(FACE::DOWN)][i][0];
    for (int i = 0; i < 3; i++) cube[int(FACE::DOWN)][i][0] = cube[int(FACE::FRONT)][i][0];
    for (int i = 0; i < 3; i++) cube[int(FACE::FRONT)][i][0] = temp_arr[i];
    return *this;
}

RubiksCube &RubiksCube3dArray::lPrime() {
    this->l();
    this->l();
    this->l();
    return *this;
}

RubiksCube &RubiksCube3dArray::l2() {
    this->l();
    this->l();
    return *this;
}

RubiksCube &RubiksCube3dArray::f() {
    this->rotateFace(int(FACE::FRONT));
    char temp_arr[3] = {};
    for (int i = 0; i < 3; i++) temp_arr[i] = cube[int(FACE::UP)][2][i];
    for (int i = 0; i < 3; i++) cube[int(FACE::UP)][2][i] = cube[int(FACE::LEFT)][2 - i][2];
    for (int i = 0; i < 3; i++) cube[int(FACE::LEFT)][2 - i][2] = cube[int(FACE::DOWN)][0][2 - i];
    for (int i = 0; i < 3; i++) cube[int(FACE::DOWN)][0][2 - i] = cube[int(FACE::RIGHT)][i][0];
    for (int i = 0; i < 3; i++) cube[int(FACE::RIGHT)][i][0] = temp_arr[i];
    return *this;
}

RubiksCube &RubiksCube3dArray::fPrime() {
    this->f();
    this->f();
    this->f();
    return *this;
}

RubiksCube &RubiksCube3dArray::f2() {
    this->f();
    this->f();
    return *this;
}

RubiksCube &RubiksCube3dArray::r() {
    this->rotateFace(int(FACE::RIGHT));
    char temp_arr[3] = {};
    for (int i = 0; i < 3; i++) temp_arr[i] = cube[int(FACE::UP)][2 - i][2];
    for (int i = 0; i < 3; i++) cube[int(FACE::UP)][2 - i][2] = cube[int(FACE::FRONT)][2 - i][2];
    for (int i = 0; i < 3; i++) cube[int(FACE::FRONT)][2 - i][2] = cube[int(FACE::DOWN)][2 - i][2];
    for (int i = 0; i < 3; i++) cube[int(FACE::DOWN)][2 - i][2] = cube[int(FACE::BACK)][i][0];
    for (int i = 0; i < 3; i++) cube[int(FACE::BACK)][i][0] = temp_arr[i];
    return *this;
}

RubiksCube &RubiksCube3dArray::rPrime() {
    this->r();
    this->r();
    this->r();
    return *this;
}

RubiksCube &RubiksCube3dArray::r2() {
    this->r();
    this->r();
    return *this;
}

RubiksCube &RubiksCube3dArray::b() {
    this->rotateFace(int(FACE::BACK));
    char temp_arr[3] = {};
    for (int i = 0; i < 3; i++) temp_arr[i] = cube[int(FACE::UP)][0][2 - i];
    for (int i = 0; i < 3; i++) cube[int(FACE::UP)][0][2 - i] = cube[int(FACE::RIGHT)][2 - i][2];
    for (int i = 0; i < 3; i++) cube[int(FACE::RIGHT)][2 - i][2] = cube[int(FACE::DOWN)][2][i];
    for (int i = 0; i < 3; i++) cube[int(FACE::DOWN)][2][i] = cube[int(FACE::LEFT)][i][0];
    for (int i = 0; i < 3; i++) cube[int(FACE::LEFT)][i][0] = temp_arr[i];
    return *this;
}

RubiksCube &RubiksCube3dArray::bPrime() {
    this->b();
    this->b();
    this->b();
    return *this;
}

RubiksCube &RubiksCube3dArray::b2() {
    this->b();
    this->b();
    return *this;
}

RubiksCube &RubiksCube3dArray::d() {
    this->rotateFace(int(FACE::DOWN));
    char temp_arr[3] = {};
    for (int i = 0; i < 3; i++) temp_arr[i] = cube[int(FACE::FRONT)][2][i];
    for (int i = 0; i < 3; i++) cube[int(FACE::FRONT)][2][i] = cube[int(FACE::LEFT)][2][i];
    for (int i = 0; i < 3; i++) cube[int(FACE::LEFT)][2][i] = cube[int(FACE::BACK)][2][i];
    for (int i = 0; i < 3; i++) cube[int(FACE::BACK)][2][i] = cube[int(FACE::RIGHT)][2][i];
    for (int i = 0; i < 3; i++) cube[int(FACE::RIGHT)][2][i] = temp_arr[i];
    return *this;
}

RubiksCube &RubiksCube3dArray::dPrime() {
    this->d();
    this->d();
    this->d();
    return *this;
}

RubiksCube &RubiksCube3dArray::d2() {
    this->d();
    this->d();
    return *this;
}

bool RubiksCube3dArray::operator==(const RubiksCube3dArray &r1) const {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (r1.cube[i][j][k] != cube[i][j][k]) return false;
            }
        }
    }
    return true;
}

RubiksCube3dArray &RubiksCube3dArray::operator=(const RubiksCube3dArray &r1) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cube[i][j][k] = r1.cube[i][j][k];
            }
        }
    }
    return *this;
}



  




