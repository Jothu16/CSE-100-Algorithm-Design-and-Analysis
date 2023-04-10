	#include <iostream>
	#include <vector>
	#include <queue>
	#include <list>
	#include <limits>

	using namespace std;
	//Minimum Spanning Tree using Prim's Algorithm0
	//Example/Tutorial: https://www.programiz.com/dsa/prim-algorithm
	//Priority Queue Tutorial/Example: https://www.programiz.com/dsa/priority-queue 
	/*https://www.geeksforgeeks.org/stack-push-and-pop-in-c-stl/
	how to use push and pop correctly (myStack and Q)
	*/

	typedef pair<int, int> key;
	struct MinSpanTree {

		int j;
		list<key> *vw;
		MinSpanTree(int v);

		void push_key(int u, int v, int w);

		void prims_algo();
	};

	MinSpanTree::MinSpanTree(int v) {
		j = v;
		vw = new list<key>[v];
	}

	void MinSpanTree::push_key(int u, int v, int w) {
		vw[u].push_back(make_pair(v, w));
		vw[v].push_back(make_pair(u, w));
	}

	void MinSpanTree::prims_algo() {
		//priority queue
		priority_queue<key, vector<key>, greater<key>>myStack;

		vector<int> k, P, insert;
		int R =0;

		for(int i = 0; i < j; i++) {
			k.push_back(std::numeric_limits<int>::max());
			P.push_back(0);
			insert.push_back(-1);
		}
		myStack.push(make_pair(0, R));
		k[R] = 0;

		while(!myStack.empty()) {
		//u = Extract - Min(Q)
			int U = myStack.top().second;
			myStack.pop();
			insert[U] = 1;

			list<key>::iterator iter;

			for(iter = vw[U].begin(); iter != vw[U].end(); iter++) {
				int V = (*iter).first;
				int W = (*iter).second;

				if(insert[V] == -1 && k[V] > W) {
					k[V] = W;
					myStack.push(make_pair(k[V], V));
					P[V] = U;
				}
			}
		}
		for(int i = 1; i < j; i++) {
			cout<< P[i] <<endl;
		}
	}

	int main(int argc, const char* argv[]) {

		int vs = 0, es = 0;
		cin>>vs;
		cin>>es;

		MinSpanTree mst(vs);
		int w[es], v[es], u[es];

		for(int i = 0; i < es; i++) {
			cin >> w[i];
			cin >> v[i];
			cin >> u[i];
			mst.push_key(w[i], v[i], u[i]);
		}
		mst.prims_algo();
		return 0;
	}