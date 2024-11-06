#include "OurCPSC3120Tree.h"
#include <iostream>
#include <cmath>
using namespace std;

/*
class OurCPSC3120Tree{
 public:
  OurCPSC3120Tree(void);
  OurCPSC3120Tree(OurCPSC3120Tree&);
  ~OurCPSC3120Tree(void);
  OurCPSC3120Tree* getParent(void);
  OurCPSC3120Tree* getLeft(void);
  OurCPSC3120Tree* getRight(void);
  int getValue(void);
  void setParent(OurCPSC3120Tree&);
  void setLeft(OurCPSC3120Tree&);
  void setRight(OurCPSC3120Tree&);
  void setValue(int);
  void insert(int);
  void printPreorder(void);
  void printInorder(void);
  void printPostorder(void);
  void rotateLeft(void);
  void rotateRight(void);
  void rotateLeftRight(void);
  void rotateRightLeft(void);
  void deleteNode(int);
    
 private:
  int value;
  OurCPSC3120Tree *parent;
  OurCPSC3120Tree *left;
  OurCPSC3120Tree *right;
  int getHeight();
  void balanceTree();
  void printInfo();
};
 */

OurCPSC3120Tree::OurCPSC3120Tree(){
  value = 0;
  parent = NULL;
  left = NULL;
  right = NULL;
}

OurCPSC3120Tree::OurCPSC3120Tree( OurCPSC3120Tree &t ){
  setParent( *t.getParent() );
  setLeft( *t.getLeft() );
  setRight( *t.getRight() );
  setValue( t.getValue() );
}

OurCPSC3120Tree::~OurCPSC3120Tree(){
}

int OurCPSC3120Tree::getValue(){
  return value;
}

OurCPSC3120Tree* OurCPSC3120Tree::getLeft(){
  return left;
}

OurCPSC3120Tree* OurCPSC3120Tree::getRight(){
  return right;
}

OurCPSC3120Tree* OurCPSC3120Tree::getParent(){
  return parent;
}

void OurCPSC3120Tree::setValue( int v ){
  value = v;
  return;
}

void OurCPSC3120Tree::setParent( OurCPSC3120Tree &newParent ){
  parent = &newParent;
}

void OurCPSC3120Tree::setLeft( OurCPSC3120Tree &newLeft ){
  left = &newLeft;
  return;
}

void OurCPSC3120Tree::setRight( OurCPSC3120Tree &newRight ){
  right = &newRight;
  return;
}

void OurCPSC3120Tree::printInfo(){
  cerr << this << endl;
  cerr << "---------------" << endl;
  cerr << "Value : " << getValue() << endl;
  cerr << "Parent: " << getParent() << endl;
  cerr << "Left  : " << getLeft() << endl;
  cerr << "Right : " << getRight() << endl;
  cerr << "Height: " << getHeight() << endl;
  cerr << "===============" << endl;
  if( getLeft() ){
    getLeft()->printInfo();
  }
  if( getRight() ){
    getRight()->printInfo();
  }
}

void OurCPSC3120Tree::printPreorder(){
  cout << getValue();
  if( getLeft() && getLeft()->getValue() ){
    cout << ",";
    getLeft()->printPreorder();
  }
  if( getRight() && getRight()->getValue() ){
    cout << ",";
    getRight()->printPreorder();
  }

  return;
}

void OurCPSC3120Tree::printInorder(){
  if( getLeft() && getLeft()->getValue() ){
    getLeft()->printInorder();
    cout << ",";
  }
  cout << getValue();
  if( getRight() && getRight()->getValue() ){
    cout << ",";
    getRight()->printInorder();
  }

  return;
}

void OurCPSC3120Tree::printPostorder(){
  if( getLeft() && getLeft()->getValue() ){
    getLeft()->printPostorder();
    cout << ",";
  }
  if( getRight() && getRight()->getValue() ){
    getRight()->printPostorder();
    cout << ",";
  }
  cout << getValue();
  return;
}

void OurCPSC3120Tree::insert( int val ){
  if( !getValue() ){
    setValue( val );
  }
  else if( val < getValue() && !getLeft() ){
    left = new OurCPSC3120Tree();
    getLeft()->setParent( *this );
    getLeft()->insert( val );
  }
  else if( val > getValue() && !getRight() ){
    right = new OurCPSC3120Tree();
    getRight()->setParent( *this );
    getRight()->insert( val );
  }
  else if( val < getValue() ){
    getLeft()->insert( val );
  }
  else{
    getRight()->insert( val );
  }

  balanceTree();
  
  return;
}

int OurCPSC3120Tree::getHeight(){
  if( !getValue() ){
    return 0;
  }
  if( !getLeft() && !getRight() ){
    return 1;
  }
  if( getLeft() && !getRight() ){
    return getLeft()->getHeight() + 1;
  }
  if( !getLeft() && getRight() ){
    return getRight()->getHeight() + 1;
  }
  
  return fmax( getLeft()->getHeight() , getRight()->getHeight() ) + 1;
}

void OurCPSC3120Tree::balanceTree(){
  if( !getRight() && getLeft() && !getLeft()->getLeft() && getLeft()->getHeight() >= 2 ){
    rotateLeftRight();
    return;
  }
  if( !getRight() && getLeft() && getLeft()->getLeft() && getLeft()->getRight() && getLeft()->getRight()->getHeight() > getLeft()->getLeft()->getHeight() ){
    rotateLeftRight();
    return;
  }
  if( !getLeft() && getRight() && !getRight()->getRight() && getRight()->getHeight() >= 2 ){
    rotateRightLeft();
    return;
  }
  if( !getLeft() && getRight() && getRight()->getRight() && getRight()->getLeft() && getRight()->getLeft()->getHeight() > getRight()->getRight()->getHeight() ){
    rotateRightLeft();
    return;
  }
  if( !getLeft() && getRight() && getRight()->getHeight() >= 2 ){
    rotateLeft();
    return;
  }
  if( getLeft() && getRight() && getRight()->getHeight() >= ( getLeft()->getHeight() + 2 ) ){
    rotateLeft();
    return;
  }
  if( !getRight() && getLeft() && getLeft()->getHeight() >= 2 ){
    rotateRight();
    return;
  }
  if( getRight() && getLeft() && getLeft()->getHeight() >= ( getRight()->getHeight() + 2 ) ){
    rotateRight();
    return;
  }
}

void OurCPSC3120Tree::rotateLeftRight(){
  getLeft()->rotateLeft();
  rotateRight();
  return;
}

void OurCPSC3120Tree::rotateRightLeft(){
  getRight()->rotateRight();
  rotateLeft();
  return;
}

void OurCPSC3120Tree::rotateLeft(){
    OurCPSC3120Tree *newNode = new OurCPSC3120Tree();
    
    newNode->setValue(this->getValue());

    OurCPSC3120Tree *rightChild = getRight();

    this->setValue(rightChild->getValue());

    //set left node of og root to be linked to newNode
    if (this->getLeft())
    {
      newNode->setLeft(*getLeft());
      newNode->getLeft()->setParent(*newNode);
    }
      
    //set newNode to be the left value of og root
    this->setLeft(*newNode);
    newNode->setParent(*this);

    //set right child of newNode to C and parent of C to newNode
    if (this->getRight()->getLeft())
    {
      newNode->setRight(*this->getRight()->getLeft());
      this->getRight()->getLeft()->setParent(*newNode);
    }

    //set right child of og root to E and parent of E to og root
    if (this->getRight()->getRight())
    {
      this->getRight()->getRight()->setParent(*this);
      this->setRight(*this->getRight()->getRight());
    }

    return;
}

void OurCPSC3120Tree::rotateRight(){
  //inverse of rotateLeft
  OurCPSC3120Tree *newNode = new OurCPSC3120Tree();
    
    newNode->setValue(this->getValue());

    OurCPSC3120Tree *leftChild = getLeft();

    this->setValue(leftChild->getValue());

    if (this->getRight())
    {
      newNode->setRight(*getRight());
      newNode->getRight()->setParent(*newNode);
    }
      
    this->setRight(*newNode);
    newNode->setParent(*this);

    if (this->getLeft()->getRight())
    {
      newNode->setLeft(*this->getLeft()->getRight());
      this->getLeft()->getRight()->setParent(*newNode);
    }

    if (this->getLeft()->getLeft())
    {
      this->getLeft()->getLeft()->setParent(*this);
      this->setLeft(*this->getLeft()->getLeft());
    }

  return;
}

void OurCPSC3120Tree::deleteNode(int val) {
    //OurCPSC3120Tree *temp = new OurCPSC3120Tree();

    if (val < this->getValue()) 
    {
        if (this->getLeft()) 
        {
            this->getLeft()->deleteNode(val);
        }
    } 
    else if (val > this->getValue()) 
    {
        if (this->getRight()) 
        {
            this->getRight()->deleteNode(val);
        }
    } 
    else 
    {
        //No children
        if (this->getLeft() == nullptr && this->getRight() == nullptr) {
            delete this;
            return;
        }

        //Only right child exists
        if (this->getLeft() == nullptr) 
        {
            this->setValue(this->getRight()->getValue());
            this->getRight()->setParent(*this->getParent());
            if (this->getParent()->getRight() == this)
              this->getParent()->setRight(*this->getRight());
            else if (this->getParent()->getLeft() == this)
              this->getParent()->setLeft(*this->getRight());
            delete this->getRight();
            return;
        }

        //Only left child exists
        if (this->getRight() == nullptr) 
        {
            this->setValue(this->getLeft()->getValue());
            this->getLeft()->setParent(*this->getParent());
            if (this->getParent()->getRight() == this)
              this->getParent()->setRight(*this->getLeft());
            else if (this->getParent()->getLeft() == this)
              this->getParent()->setLeft(*this->getLeft());
            delete this->getRight();
            return;
        }

        //Two children
        if (this->getLeft() && this->getRight()) 
        {
            OurCPSC3120Tree *minRight = this->getRight();
            while (minRight->getLeft())
                minRight = minRight->getLeft();

            this->setValue(minRight->getValue());
            this->getRight()->deleteNode(minRight->getValue());
            return;
        }

        while (this->getValue() == val) 
        {
            deleteNode(val);
        }
    }
}



  