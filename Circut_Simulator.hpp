/*
 * lmao gotem 
 */

/* 
 * File:   Circut_Simulator.hpp
 * Author: Jason Tang, David Cormier, Thomas Van Issum
 *
 * Created on May 25, 2020, 12:16 PM
 */

#ifndef CIRCUT_SIMULATOR_HPP
#define CIRCUT_SIMULATOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <Eigen>
#include <bits/stdc++.h>
using namespace std;
using namespace Eigen;

struct Node
{
	int number;
	string label;
	int super;
	Node(){number = -1; label = "N/A"; super = -99;}
	Node(string l){number = -1; super = -1; label=l;}

        

};

struct Component
{
	char type;
	string name;
	Node A;
	Node B;
	float value;

	Component(char t,string n, string nA,string nB,float v){
		type = t;
		name = n;
		A.label = nA;
		B.label = nB;
		value = v;
	}
        
       
};

// *** Component Management Functions ***

vector<Component> readInput();
//reads a netlist from stdin and sorts them into a vec of components

vector<Node> findNodes(vector<Component> list);
// returns a list of node. Duplicates are not counted and 0 is set to ground if it exits

vector<Component> patchComponents(vector<Component> list);
// returns a new vector of components that have their number and super vaules updated. Has to be new, as functions take in a copy for the vector.


//  *** Matrix Functions ***
VectorXd matrixSolve(MatrixXd m,VectorXd v);
//takes in the vector of currents and conductance matrix, and spits out the node voltage vector. 


// *** Quality of Life functions ***
ostream& operator<<(ostream& os, const Component& c);
ostream& operator<<(ostream& os, const Node& c);
// allows you to cout both components and nodes.



// *** Functions used by functions. Only use if necessary ***
bool operator == (Node const &n1, Node const &n2);
//used in the node finder function.

vector<Component> patchSupernodes(vector<Component> list);
//used in patchNodes to correctly fill out the values of the supernodes after the inital numbering operation

bool isComponent(string x);
//returns true if a line from a string (probs from stdin) is a component or not


#endif