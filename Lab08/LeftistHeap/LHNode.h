#ifndef L_H_NODE_H
#define L_H_NODE_H

#include <iostream>

class LHNode
{
     private:
          int element;
          int m_rank;
          LHNode* m_right;
          LHNode* m_left;

     public:
          LHNode();

          void setValue(int val);

		int getValue() const;

		void setLeft(LHNode* left);

		void setRight(LHNode* right);

		LHNode* getLeft() const;

		LHNode* getRight() const;

          void setRank(int rank);

          int getRank() const;
};

#endif
