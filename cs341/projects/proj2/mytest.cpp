#include "utree.h"
#include <random>

#define NUMACCTS 20
#define RANDDISC (distAcct(rng))


std::mt19937 rng(10);
std::uniform_int_distribution<> distAcct(0, 9999);

class Tester {
public:
    bool testBasicDTreeInsert(DTree& dtree);

    //bool testBasicUTreeInsert(UTree& utree);
};

bool Tester::testBasicDTreeInsert(DTree& dtree) {
    bool allInserted = true;
    for(int i = 0; i < NUMACCTS; i++) {
        int disc = RANDDISC;
        Account newAcct = Account("", disc, 0, "", "");
        
        if(!dtree.insert(newAcct)) {
            cout << "Insertion on node " << disc << " did not return true" << endl;
            allInserted = false;
        }
        
        //cout<<"DISC: "<<disc<<endl;
    }
    return allInserted;
}
/**
bool Tester::testBasicUTreeInsert(UTree& utree) {
    string dataFile = "accounts.csv";
    try {
        utree.loadData(dataFile);
    } catch(std::invalid_argument e) {
        std::cerr << e.what() << endl;
        return false;
    }
    return true;
}
**/

int main() {
    Tester tester;

    /* Basic dtree tests */
    DTree dtree;
  
    
    cout << "Testing DTree insertion...";
    if(tester.testBasicDTreeInsert(dtree)) {
        cout << "test passed" << endl;
    } else {
        cout << "test failed" << endl;
    }

  
    
    cout << "Resulting DTree:" << endl;
    dtree.dump();
    cout << endl;
    
    //test.dump();
    //cout<<"test"<<endl;
    //DTree test; 
    //test = dtree;
    //test.dump();
    //cout<<""<<endl;
    //cout<<"retrieve test"<<endl;
    //cout<<dtree.retrieve(7713)<<endl;
    //DNode* temp;
    //cout<<dtree.remove(2987, temp)<<endl;
    //dtree.updateNumVacant(temp);
    //dtree.dump();


    /* Basic UTree tests */
    /**
    UTree utree;

    cout << "\n\nTesting UTree insertion...";
    if(tester.testBasicUTreeInsert(utree)) {
        cout << "test passed" << endl;
    } else {
        cout << "test failed" << endl;
    }

    cout << "Resulting UTree:" << endl;
    utree.dump();
    cout << endl;
    **/

    return 0;
}