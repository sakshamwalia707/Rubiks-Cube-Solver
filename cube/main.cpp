#include <iostream>
#include<bits/stdc++.h>
#include "RubiksCube3dArray.h"
#include "BFSSolver.h"

using namespace std;
int main() {
    RubiksCube3dArray cube;
    cube.print();
    if(cube.isSolved())
    {
		cout<<"solved"<<endl;
	}
	else
	{
		cout<<"NOT"<<endl;
	}

      //cube.u();
      //cube.print();
  

    //cube.l();

      //cube.print();

     //cube.f();
     //cube.print();

     // cube.r();
      //cube.print();

      //cube.b();
      //cube.print();


      //cube.d();
     //cube.print();

      //if (cube.isSolved()) cout << "SOLVED\n\n";
     //else cout << "NOT SOLVED\n\n";


      //cube.dPrime();
      //cube.print();
      
     //cube.bPrime();
     //cube.print();

     //cube.rPrime();
     //cube.print();

     //cube.fPrime();

     //cube.print(); 
     //cube.lPrime();

     //cube.print();

     //cube.uPrime();

     //cube.print();
     //vector<RubiksCube::MOVE>v = cube.randomShuffleCube(5);
     //for(int i=0;i<v.size();i++)
     //{
	//	 cout<<cube.getMove(v[i])<<" ";
	// }
	 //cout<<endl;
	 //cube.print();
    //if (cube.isSolved()) cout << "SOLVED\n\n";
   //  else cout << "NOT SOLVED\n\n";
   
   
   //RubiksCube3dArray cube1;
  // RubiksCube3dArray cube2;
       //if(cube1 == cube2) cout << "Is equal\n";
     //else cout << "Not Equal\n";

    //cube1.randomShuffleCube(1);

    //if(cube1 == cube2) cout << "Is equal\n";
    // else cout << "Not Equal\n";

     //cube2 = cube1;

    //if(cube1 == cube2) cout << "Is equal\n";
    //  else cout << "Not Equal\n";
    
    //RubiksCube3dArray cube1;
    //RubiksCube3dArray cube2;
    //unordered_map<RubiksCube3dArray, bool,RubiksCube3dArray::Hash3d> mp1;
    //mp1[cube1] = true;
    //cube2.randomShuffleCube(8);
    //if (mp1[cube1]) cout << "Cube1 is present\n";
     //else cout << "Cube1 is not present\n";

    // if (mp1[cube2]) cout << "Cube2 is present\n";
  //    else cout << "Cube2 is not present\n";
  


  vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);

    for(auto move: shuffle_moves) {
        cout << cube.getMove(move) << " ";
    }
    cout << "\n";

    cube.print();

    BFSSolver3d bfsSolver(cube);
    vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();

    for(auto move: solve_moves) {
        cout << cube.getMove(move) << " ";
    }
    cout << "\n";

    bfsSolver.rubiksCube.print();

    return 0;
}


