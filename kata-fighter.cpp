#include <iostream>
#include <string>

class Fighter
{
private:
    std::string name;

    int health;

    int damagePerAttack;

public:
    Fighter(std::string name, int health, int damagePerAttack)
    {
        this->name = name;
        this->health = health;
        this->damagePerAttack = damagePerAttack;
    }

    ~Fighter() { };

    std::string getName()
    {
        return name;
    }

    int getHealth()
    {
        return health;
    }

    int getDamagePerAttack()
    {
        return damagePerAttack;
    }

    void setHealth(int value)
    {
        health = value;
    }
};

std::string declareWinner(Fighter* fighter1, Fighter* fighter2, std::string firstAttacker)
{   
    int twoHealth = fighter2 -> getHealth();
    int twoAttack = fighter2 -> getDamagePerAttack();
    std::string twoName = fighter2 -> getName();


    int oneAttack = fighter1 -> getDamagePerAttack();
    int oneHealth = fighter1 ->getHealth();
    std::string oneName = fighter1 -> getName();

    bool condition = true;
    
    while(condition)
    {
        if(oneName == firstAttacker)
        {
            oneHealth -= twoAttack;
            twoHealth -= oneAttack;
            fighter2 -> setHealth(twoHealth);
            if(fighter2 -> getHealth() <= 0) { break; }
            fighter1 -> setHealth(oneHealth);
            if(fighter1 -> getHealth() <= 0) { break; }
            std::cout << "life law: " << fighter1 -> getHealth() << std::endl;
            std::cout << "harry life: " <<  fighter2 -> getHealth() << std::endl;
        }
        else
        {
            oneHealth -= twoAttack;
            twoHealth -= oneAttack;
            fighter1 -> setHealth(oneHealth);
            if(fighter1 -> getHealth() <= 0) { break; }
            fighter2 -> setHealth(twoHealth);
            if(fighter2 -> getHealth() <= 0) { break; }
            std::cout << "life law: " << fighter1 -> getHealth() << std::endl;
            std::cout << "harry life: " <<  fighter2 -> getHealth() << std::endl;
        }
    }

    condition = false;
    int oneHealthLast = fighter1 ->getHealth();
    int twoHealthLast = fighter2 ->getHealth();

    std::cout << oneHealthLast << std::endl;
    std::cout << twoHealthLast << std::endl;

    return (oneHealthLast > 0) ? oneName:twoName;
}

int main()
{
    Fighter fighter1("Lew", 10, 2);
    Fighter fighter2("Harry", 5, 4);
    
    std::cout << declareWinner(&fighter1,&fighter2,"Lew") << std::endl;
    
    return 0;
}