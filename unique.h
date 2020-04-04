#pragma once
#include <string>

class IUnique {
public:
    virtual void attack_effect()=0;
    virtual void end_turn_effect()=0;
};



class NonRace : public IUnique {
private:
    const unsigned amount = 0;
public:
    void attack_effect() override  {return;}
    void end_turn_effect() override {return;}
};

class NonAbility : public IUnique {
private:
    const unsigned amount = 0;
public: 
    void attack_effect() override {return;}
    void end_turn_effect() override {return;}  
};




class SimpleRace : public IUnique {
private:
    const unsigned amount = 6;
    const std::string avatar_name = "simple"; 
public:
    void attack_effect() override  {return;}
    void end_turn_effect() override {return;}
};


class SimpleAbiliy : public IUnique {
private:
    const unsigned amount = 5;
public: 
    void attack_effect() override {return;}
    void end_turn_effect() override {return;}  
};

