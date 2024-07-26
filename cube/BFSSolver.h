#ifndef RUBIKS_CUBE_SOLVER_BFSSOLVER3D_H
#define RUBIKS_CUBE_SOLVER_BFSSOLVER3D_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>
#include "RubiksCube3dArray.h"

using namespace std;

class BFSSolver3d {
private:
    vector<RubiksCube::MOVE> moves;
    unordered_map<RubiksCube3dArray, bool, RubiksCube3dArray::Hash3d> visited;
    unordered_map<RubiksCube3dArray, RubiksCube::MOVE, RubiksCube3dArray::Hash3d> move_done;

    RubiksCube3dArray bfs() {
        queue<RubiksCube3dArray> q;
        q.push(rubiksCube);
        visited[rubiksCube] = true;

        while (!q.empty()) {
            RubiksCube3dArray node = q.front();
            q.pop();
            if (node.isSolved()) {
                return node;
            }
            for (int i = 0; i < 18; i++) {
                auto curr_move = RubiksCube::MOVE(i);
                node.move(curr_move);
                if (!visited[node]) {
                    visited[node] = true;
                    move_done[node] = curr_move;
                    q.push(node);
                }
                node.invert(curr_move);
            }
        }
        return rubiksCube;
    }

public:
    RubiksCube3dArray rubiksCube;

    BFSSolver3d(RubiksCube3dArray _rubiksCube) : rubiksCube(_rubiksCube) {}

    vector<RubiksCube::MOVE> solve() {
        RubiksCube3dArray solved_cube = bfs();
        assert(solved_cube.isSolved());
        RubiksCube3dArray curr_cube = solved_cube;
        while (!(curr_cube == rubiksCube)) {
            RubiksCube::MOVE curr_move = move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }
        rubiksCube = solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }
};

#endif // RUBIKS_CUBE_SOLVER_BFSSOLVER3D_H

