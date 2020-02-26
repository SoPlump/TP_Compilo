#pragma once

#include <string>
#include <stack>

#include "symbole.h"
#include "state.h"
#include "automate.h"

using namespace std;

class S0: public State{

public:
    S0():State("S0") {}
    ~S0(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};

/***** State S1 *****/

class S1: public State{

public:
    S1():State("S1") {}
    ~S1(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};


/***** State S2 *****/

class S2: public State{
public:
    S2():State("S2") {}
    ~S2(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};

/***** State S3 *****/

class S3: public State{

public:
    S3():State("S3") {}
    ~S3(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};


/***** State S4 *****/

class S4: public State{
public:
    S4():State("S4") {}
    ~S4(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};

/***** State S5 *****/

class S5: public State{
public:
    S5():State("S5") {}
    ~S5(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};

/***** State S6 *****/

class S6: public State{
public:
    S6():State("S6") {}
    ~S6(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};


/***** State S7 *****/

class S7: public State{
public:
    S7():State("S7") {}
    ~S7(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};

/***** State S8 *****/

class S8: public State{
public:
    S8():State("S8") {}
    ~S8(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};


/***** State S9 *****/

class S9: public State{
public:
    S9():State("S9") {}
    ~S9(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};
