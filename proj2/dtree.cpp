/**
 * CMSC 341 - Spring 2021
 * Project 2 - Binary Trees
 * DiscriminatorTree.cpp
 * Implementation for the DTree class.
 */

#include "dtree.h"

/**
 * Destructor, deletes all dynamic memory.
 */
DTree::~DTree() {
   
   clear();
   
   
}
/**
 * Helper for the destructor to clear dynamic memory.
 */
void DTree::clear() {
    //cout<<"clear function riught herew"<<endl;
    deleteTree(this->_root,true);

    //this->_root = nullptr;
    
}
void DTree::deleteTree(DNode* node,bool deleteNode){
    
    if(node){
        
        deleteTree(node->_left,deleteNode);
        deleteTree(node->_right,deleteNode);
        if(deleteNode){
            delete node;
        }
        
       
        
    }
     
    
    
    
    
}
void DTree::recursiveCopy(DNode* srcNode, DNode*& copyNode){
    if(srcNode == nullptr){
        return;
    }
    else{
        //insert(node->getAccount());
        copyNode = new DNode(srcNode->getAccount());
        copyNode->_size = srcNode->_size;
        copyNode->_numVacant = srcNode->_numVacant;
        copyNode->_vacant = srcNode->_vacant;
        recursiveCopy(srcNode->_left,copyNode->_left);
        recursiveCopy(srcNode->_right,copyNode->_right);
    }
}
/**
 * Overloaded assignment operator, makes a deep copy of a DTree.
 * @param rhs Source DTree to copy
 * @return Deep copy of rhs
 */
DTree& DTree::operator=(const DTree& rhs) {
    //cout<<"Overloaded assignment operator, makes a deep copy of a DTree."<<endl;
    
    if(this != &rhs){
        //cout<<"entered condition"<<endl;
        this->clear();
        recursiveCopy(rhs._root, this->_root);
    }
    return *this;
}

/**
 * Dynamically allocates a new DNode in the tree. 
 * Should also update heights and detect imbalances in the traversal path
 * an insertion.
 * @param newAcct Account object to be contained within the new DNode
 * @return true if the account was inserted, false otherwise
 */
bool DTree::insert(Account newAcct) {
    //cout << "Insert new : " << newAcct.getDiscriminator()<<endl;
    return recursiveInsert(this->_root, newAcct,false);
}

bool DTree::recursiveInsert(DNode*& localRoot, Account acct, bool isCreated){
    if(localRoot == nullptr){
        localRoot = new DNode (acct);
        isCreated = true;
        updateSize(localRoot, this->_root, -1);
        //updateNumVacant(localRoot);
    }
    else if(localRoot->isVacant()){
        cout<<"found vacant node"<<endl;
        if(retrieve(acct.getDiscriminator()) == nullptr){
            if(localRoot->_left->getDiscriminator() < acct.getDiscriminator() && localRoot->_right->getDiscriminator() > acct.getDiscriminator()){
                //localRoot = new DNode(acct);
                localRoot->_vacant = false;
                localRoot->_numVacant -= 1;
                localRoot->_account._disc = acct.getDiscriminator();
                return true;
            }
        }
    }
    else if(acct.getDiscriminator() < localRoot -> getDiscriminator()){
        isCreated = recursiveInsert(localRoot->_left, acct, isCreated);
    }
    else if(acct.getDiscriminator() > localRoot->getDiscriminator()){
        isCreated = recursiveInsert(localRoot->_right, acct, isCreated);
    }
    else{
        isCreated = false;
    } 
    if(checkImbalance(localRoot)){
        //this->dump();
        //cout << endl;
        cout<<"DTREE SIZE "<<localRoot->getSize()<<"(Imbalance at localRoot " <<localRoot->getDiscriminator()<<"), "<<endl;
        //cout<<&localRoot<<endl;
        rebalance(localRoot);
        //cout<<&localRoot<<endl;
       
    }
    return isCreated;  
}

DNode* DTree::recursiveRemove(DNode* node, int disc){
    if(node != nullptr){
        if(node->getDiscriminator() == disc){
            node->_vacant = true;
            return node;
        }
        else{
            DNode* temp = recursiveRemove(node->_left, disc);
            if(temp == nullptr){
                temp = recursiveRemove(node->_right, disc);
            }
            return temp;
        }
    }
    else{
        return nullptr;
    }
    updateNumVacant(node);
   
    

}
/**
 * Removes the specified DNode from the tree.
 * @param disc discriminator to match
 * @param removed DNode object to hold removed account
 * @return true if an account was removed, false otherwise
 */
bool DTree::remove(int disc, DNode*& removed) {
    removed = recursiveRemove(this->_root, disc);
    if(removed){
        
        return removed->isVacant();
    }
    
    return false;

    
}
DNode* DTree::recursiveSearch(DNode* node, int disc){
    if(node != nullptr){
        if(node->getDiscriminator() == disc){
            node->_numVacant++;
            return node;
        }
        else{
            DNode* temp = recursiveSearch(node->_left, disc);
            if(temp == nullptr){
                temp = recursiveSearch(node->_right, disc);
            }
            return temp;
        }
    }
    else{
        return nullptr;
    }
}
/**
 * Retrieves the specified Account within a DNode.
 * @param disc discriminator int to search for
 * @return DNode with a matching discriminator, nullptr otherwise
 */
DNode* DTree::retrieve(int disc) {

    return recursiveSearch(this->_root, disc);
    
}



/**
 * Prints all accounts' details within the DTree.
 */
void DTree::printAccounts() const {

    cout<<"prints all accounts details within DTree"<<endl;
}

/**
 * Dump the DTree in the '()' notation.
 */
void DTree::dump(DNode* node) const {
    if(node == nullptr) return;
    cout << "(";
    dump(node->_left);
    cout << node->getAccount().getDiscriminator()<< ":" << node->getSize() << ":" << node->getNumVacant();
    dump(node->_right);
    cout << ")";
}

/**
 * Returns the number of valid users in the tree.
 * @return number of non-vacant nodes
 */
int DTree::getNumUsers() const {
    return 0;
}

/**
 * Updates the size of a node based on the imedaite children's sizes
 * @param node DNode object in which the size will be updated
 */
void DTree::updateSize(DNode* node, DNode* rootNode, int prevRootDiscriminator){

    //cout << "Called Update size : "<<  rootNode<< " - " << rootNode->getDiscriminator() << " - " <<node << "(" << node->getDiscriminator() << ")"  << "-" << prevRootDiscriminator << endl;
    
    DNode* temp = rootNode;
    //out <<node << " ROOT -  " << temp << endl;
    if (temp == node && temp->getDiscriminator() != prevRootDiscriminator) {
        //cout << "Setting to 1" << endl;
        node->_size = 1;
    }
    
    while(temp != node){
        //cout << "IN" << endl;
        if(node->getDiscriminator() < temp->getDiscriminator()){
            //cout << "LEFT : " << temp << " - " << temp->getDiscriminator() <<endl;
            temp->_size++;
            temp = temp->_left;
        }
        else{
            //cout << "RIGHT : " << temp << " - " << temp->getDiscriminator() <<endl;
            temp->_size++;
            temp = temp ->_right;
            
        }

    }
    //cout<<"Updates size of a node based on the imediate childrens sizes"<<endl;
    
}



/**
 * Updates the number of vacant nodes in a node's subtree based on the immediate children
 * @param node DNode object in which the number of vacant nodes in the subtree will be updated
 */
void DTree::updateNumVacant(DNode* node) {
    //node->_numVacant++;
    DNode* temp = this->_root;
    while(temp != node){
        /**
        if(node->getDiscriminator() < temp->getDiscriminator()){
            if(temp->isVacant()){
                temp->_numVacant++;
            }
            temp = temp ->_left;
        }
        else{
            
            if(temp->isVacant()){
                temp->_numVacant++;
            }
            temp = temp->_right;
        }
        **/
        if(temp->isVacant()){
            temp->_numVacant++;
        }
        else{
            if(node->getDiscriminator() < temp->getDiscriminator()){
                temp = temp->_left;
            }
            else{
                temp = temp->_right;
            }
        }
        
    }
    //cout<<"Updates the number of vacant nodes in a node's subtree based on the immediate children"<<endl;
}

/**
 * Checks for an imbalance, defined by 'Discord' rules, at the specified node.
 * @param checkImbalance DNode object to inspect for an imbalance
 * @return (can change) returns true if an imbalance occured, false otherwise
 */
bool DTree::checkImbalance(DNode* node) {
//    cout << " SIZE : " << node -> getSize() << endl;
    int leftSize = 0;   
    int rightSize = 0;
    if(node->_left != nullptr){
        leftSize = node->_left->getSize();
         
    }
    if(node->_right != nullptr){
        rightSize = node->_right->getSize();
    }
    
    if(leftSize >= 4 || rightSize >= 4){
        if(leftSize >= (rightSize * 1.5) || rightSize >= (leftSize * 1.5)){
            //cout<<"disc: "<<node->getDiscriminator()<< ", Left: "<<node->_left->getSize()<<" Right: "<<node->_right->getSize()<<endl;
            return true;
        }
    }
    return false;
    
}
DNode* DTree::rebuildTree(int begin, int last, DNode* accountArray, DNode*& node, DNode*& prevRoot, int prevRootDiscriminator){
    //cout << begin << ", " << last << endl;
    if(begin > last ){
        return nullptr;
    }

    int mid = (begin+last) / 2;

    node = new DNode(accountArray[mid]);
    node->_size = 0;

    updateSize(node, prevRoot, prevRootDiscriminator);
    if (node->_size == 0) node->_size = 1;

    
    //node -> _left = nullptr;

    //cout <<node<<" - "<<node ->getDiscriminator()<<endl;
   
    node->_left = rebuildTree(begin, mid-1, accountArray,node->_left, prevRoot, prevRootDiscriminator);
    //updateSize(node);
        
    node->_right = rebuildTree(mid+1, last, accountArray,node->_right, prevRoot, prevRootDiscriminator);
    //updateSize(node);
    
    //cout << "END"<< endl;
    
    return node;

    
}
//----------------
/**
 * Begins and manages the rebalancing process for a 'Discrd' tree (pass by reference).
 * @param node DNode root of the subtree to balance
 */
void DTree::rebalance(DNode*& node) {
    int arraySize = node->getSize();
    //cout << " root : " << node << " size : " << arraySize << endl;
    //cout<<"Begins and manages the rebalancing process for a 'Discrd' tree (pass by reference)."<<endl;
    DNode* accountArray = new DNode[node->getSize()];


    int i = 0;
    //this->dump();
    traversal(node, &i, accountArray, arraySize);
  
    //cout<<"before delete: "<< node << ": " << node->getDiscriminator() <<  endl;
    int  prevRootDiscriminator = node->getDiscriminator();
    deleteTree(node,true);
    //cout<<"after delete: "<< node << endl;
    
    node = rebuildTree(0, arraySize-1, accountArray, node, node, prevRootDiscriminator);

    //cout << this->_root <<  " Addr: " << node << " disc : " << node->getDiscriminator() <<  " new size: " << node->getSize();
    //node->_size = arraySize;
    //cout<<".......after delete: "<< node << " : " << node->getSize() << endl;
    //for(int i = 0; i < arraySize; i++){
    //    cout<<accountArray[i].getDiscriminator()<< " Size: " << accountArray[i].getSize() <<endl;
    //}
    //this->dump();
    //delete [] accountArray;
}

void DTree::traversal(DNode* node, int* index, DNode* accountArray, int arraySize){
      
    if(node == nullptr || *index >= arraySize){
        return;
    }

    traversal(node->_left,index, accountArray, arraySize);
    
    if(!node->isVacant() && *index < arraySize){
        //cout << "Traversal: "  << node << " Size: " << node->getSize() << endl;
        accountArray[*index] = node->getAccount();
        ++*index;
    }
    traversal(node->_right, index, accountArray, arraySize);
}
// -- OR --
/**
 * Begins and manages the rebalancing process for a 'Discrd' tree (returns a pointer).
 * @param node DNode root of the subtree to balance
 * @return DNode root of the balanced subtree
 */
//DNode* DTree::rebalance(DNode*& node) {
    
//}
//----------------

/**
 * Overloaded << operator for an Account to print out the account details
 * @param sout ostream object
 * @param acct Account objec to print
 * @return ostream object containing stream of account details
 */
ostream& operator<<(ostream& sout, const Account& acct) {
    sout << "Account name: " << acct.getUsername() << 
            "\n\tDiscriminator: " << acct.getDiscriminator() <<
            "\n\tNitro: " << acct.hasNitro() << 
            "\n\tBadge: " << acct.getBadge() << 
            "\n\tStatus: " << acct.getStatus();
    return sout;
}