#include "LHNode.h"

LHNode::LHNode()
{
     element = 0;
     m_rank = 1;
     m_right = nullptr;
     m_left = nullptr;
}

void LHNode::setValue(int val)
{
     element = val;
}

int LHNode::getValue() const
{
     return element;
}

void LHNode::setLeft(LHNode* left)
{
     m_left = left;
}

void LHNode::setRight(LHNode* right)
{
     m_right = right;
}

LHNode* LHNode::getLeft() const
{
     return m_left;
}

LHNode* LHNode::getRight() const
{
     return m_right;
}

void LHNode::setRank(int rank)
{
     m_rank = rank;
}

int LHNode::getRank() const
{
     return m_rank;
}
