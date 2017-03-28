#include "SHNode.h"

SHNode::SHNode()
{
     element = 0;
     m_right = nullptr;
     m_left = nullptr;
}

void SHNode::setValue(int val)
{
     element = val;
}

int SHNode::getValue() const
{
     return element;
}

void SHNode::setLeft(SHNode* left)
{
     m_left = left;
}

void SHNode::setRight(SHNode* right)
{
     m_right = right;
}

SHNode* SHNode::getLeft() const
{
     return m_left;
}

SHNode* SHNode::getRight() const
{
     return m_right;
}
