#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
class Fusoes;

vector<Fusoes*> fusoesMap;

class Fusoes {
    
    public:
        string carta1;
        string carta2;
        string resultado;
        Fusoes(string carta1, string carta2, string resultado) : carta1(carta1), carta2(carta2), resultado(resultado) {};
};

string getLastWord(const string& str){
    istringstream stream(str);

    string palavra;
    string ultima;

    while(stream >> palavra) {
        ultima = palavra;
    }

    return ultima;
}


class Card{
    private:
        string nome;
        string tipo;
    public:
    Card(string nome) : nome(nome), tipo(tipo){}
    // friend void fusao(Card& carta1, Card& carta2);

    friend string operator+(Card& carta1, Card &carta2) {
        vector<int> indices = {};

        for (int i = 0; i < fusoesMap.size(); i++){
            if (carta1.nome == fusoesMap[i]->carta1) {
                indices.push_back(i);
            }
        }

        for (int i = 0; i < indices.size(); i++){
            if (carta2.nome == fusoesMap[indices[i]]->carta2){
                string tipoFusao = getLastWord(fusoesMap[indices[i]]->resultado);
                cout << "tipoFusao: " << tipoFusao << endl;

                return fusoesMap[indices[i]]->resultado; 
            }
        }

    }

};


class MonsterCard : public Card {
    string tipo = "Monstro";
    public:
        MonsterCard(string nome) : Card(nome) {}
};

class SpellCard : public Card {
    private:
        string tipo = "Magia"; 
    public:
        SpellCard(string nome) : Card(nome) {}
};

class EquipCard : public Card {
    private:
        string tipo = "Equipamento";
    public:
        EquipCard(string nome) : Card(nome) {}
};


int main (){
    Fusoes fusao1 ("Koumori Dragon", "Saggi the Dark Clown", "Reaper of the Cards (Monstro)");

    fusoesMap.push_back(&fusao1);
    Fusoes fusao2 ("Beast Fangs", "Beast Fangs",  "Eatgaboon (Armadilha)");
    fusoesMap.push_back(&fusao2);
    Fusoes fusao3 ("Dark Magic", "Dragon", "Blackland Fire Dragon (Monstro)");
    fusoesMap.push_back(&fusao3);
    Fusoes fusao4 ("Dragon", "Machine", "Metal Dragon (Monstro)");
    fusoesMap.push_back(&fusao4);
    Fusoes fusao5 ("Dark Spellcaster", "Ryu-Kishin", "Ryu-Kishin Powered (Monstro)");
    fusoesMap.push_back(&fusao5);
    Fusoes fusao6 ("Dragon Capture Jar",  "Mooyan Curry", "Dragon Capture Jar (Magia)");
    fusoesMap.push_back(&fusao6);
    Fusoes fusao7 ("Hinotama", "Hinotama",  "Final Flame (Magia)");
    fusoesMap.push_back(&fusao7);
    Fusoes fusao8 ("Dark Energy", "Acid Trap Hole",  "Dark Hole (Magia)");
    fusoesMap.push_back(&fusao8);
    Fusoes fusao9 ("Electro-whip" , "Metalmorph", "Raigeki (Magia)");
    fusoesMap.push_back(&fusao9);
    Fusoes fusao10 ("Goblin’s Secret Remedy", "Goblin’s Secret Remedy", "Soul of the Pure (Armadilha)");
    fusoesMap.push_back(&fusao10);
    Fusoes fusao11 ("Legendary Sword"," Sword of Dark Destruction", "Kunai with Chain (Equipamento)");
    fusoesMap.push_back(&fusao11);
    Fusoes fusao12 ("Legendary Sword", "Sparks", "Salamandra (Equipamento)");
    fusoesMap.push_back(&fusao12);
    Fusoes fusao13 ("Machine Conversion Factory" , "Silver Bow & Arrow", "Winged Trumpeter (Equipamento)");
    fusoesMap.push_back(&fusao13);
    Fusoes fusao14 ("Castle of Dark Illusions", "Dark-Piercing Light" , "Bright Castle (Equipamento)");
    fusoesMap.push_back(&fusao14);
    Fusoes fusao15 ("Elegant Egotist", "Horn of the Unicorn" ," Curse of Tri-Horned Dragon (Monstro)");
    fusoesMap.push_back(&fusao15);


    MonsterCard monstro1("Koumori Dragon");
    MonsterCard monstro2("Saggi the Dark Clown");
    SpellCard magia1("Dragon Capture Jar");
    SpellCard magia2("Mooyan Curry");
    EquipCard equip1("Legendary Sword");
    EquipCard equip2("Sword of Dark Destruction");


    string fusaoo1 = monstro1 + monstro2;
    string fusaoo2 = magia1 + magia2;
    string fusaoo3 = equip1 + equip2;

    return 0;
}