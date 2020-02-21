#pragma once

#include <string>
#include <stack>

#include "symbole.h"
#include "etat.h"
#include "automate.h"

using namespace std;

class E0: public Etat{

public:
    E0():Etat("E0") {}
    ~E0(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};

/***** Etat E1 *****/

class E1: public Etat{

public:
    E1():Etat("E1") {}
    ~E1(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};


/***** Etat E2 *****/

class E2: public Etat{
public:
    E2():Etat("E2") {}
    ~E2(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};

/***** Etat E3 *****/

class E3: public Etat{

public:
    E3():Etat("E3") {}
    ~E3(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};


/***** Etat E4 *****/

class E4: public Etat{
public:
    E4():Etat("E4") {}
    ~E4(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};

/***** Etat E5 *****/

class E5: public Etat{
public:
    E5():Etat("E5") {}
    ~E5(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};

/***** Etat E6 *****/

class E6: public Etat{
public:
    E6():Etat("E6") {}
    ~E6(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};


/***** Etat E7 *****/

class E7: public Etat{
public:
    E7():Etat("E7") {}
    ~E7(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};

/***** Etat E8 *****/

class E8: public Etat{
public:
    E8():Etat("E8") {}
    ~E8(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};


/***** Etat E9 *****/

class E9: public Etat{
public:
    E9():Etat("E9") {}
    ~E9(){}
    void print() const;
    bool transition(Automate & automate,Symbole* s);
};
